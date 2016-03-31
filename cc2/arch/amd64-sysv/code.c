
#include <stdio.h>
#include <stdlib.h>

#include "arch.h"
#include "../../cc2.h"
#include "../../../inc/sizes.h"

enum segment {
	CODESEG,
	DATASEG,
	BSSSEG,
	NOSEG
};

static int curseg = NOSEG;

static void
segment(int seg)
{
	static char *txt[] = {
		[CODESEG] = "\t.text\n",
		[DATASEG] = "\t.data\n",
		[BSSSEG] = "\t.bss\n",
	};

	if (seg == curseg)
		return;
	fputs(txt[seg], stdout);
	curseg = seg;
}

static char *
symname(Symbol *sym)
{
	static char name[IDENTSIZ+1];
	static unsigned short id;

	if (sym->name) {
		switch (sym->kind) {
		case EXTRN:
		case GLOB:
		case PRIVAT:
			return sym->name;
		}
	}

	if (sym->numid == 0 && (sym->numid = ++id) == 0)
		error(EIDOVER);
	sprintf(name, ".L%d", sym->numid);

	return name;
}

static void
emitconst(Node *np)
{
	switch (np->type.size) {
	case 1:
		printf("%d", (int) np->u.i & 0xFF);
		break;
	case 2:
		printf("%d", (int) np->u.i & 0xFFFF);
		break;
	case 4:
		printf("%ld", (long) np->u.i & 0xFFFFFFFF);
		break;
	case 8:
		printf("%lld", (long long) np->u.i & 0xFFFFFFFF);
		break;
	default:
		abort();
	}
}

static void
emittree(Node *np)
{
	if (!np)
		return;

	switch (np->op) {
	case OSTRING:
		printf("\"%s\"", np->u.s);
		free(np->u.s);
		np->u.s = NULL;
		break;
	case OCONST:
		emitconst(np);
		break;
	case OADDR:
		emittree(np->left);
		break;
	case MEM:
		fputs(symname(np->u.sym), stdout);
		break;
	default:
		emittree(np->left);
		printf(" %c ", np->op);
		emittree(np->right);
		break;
	}
}
static void
size2asm(Type *tp)
{
	char *s;

	if (tp->flags & STRF) {
		s = "\t.ascii\t";
	} else {
		switch (tp->size) {
		case 1:
			s = "\t.byte\t";
			break;
		case 2:
			s = "\t.short\t";
			break;
		case 4:
			s = "\t.long\t";
			break;
		case 8:
			s = "\t.quad\t";
			break;
		default:
			s = "\t.space\t%llu,";
			break;
		}
	}
	printf(s, (unsigned long long) tp->size);
}


void
defsym(Symbol *sym, int alloc)
{
	label(sym);
	if (!alloc)
		return;
	size2asm(&sym->type);
	puts("0");
}

void
data(Node *np)
{
	size2asm(&np->type);
	emittree(np);
	putchar('\n');
}

void
label(Symbol *sym)
{
	int seg, flags = sym->type.flags;
	char *name = symname(sym);
	Type *tp = &sym->type;

	if (flags & FUNF)
		seg = CODESEG;
	else if (flags & INITF)
		seg = DATASEG;
	else
		seg = BSSSEG;
	segment(seg);

	switch (sym->kind) {
	case EXTRN:
		printf("\t.extern\t%s\n", name);
	case LOCAL:
		return;
	case GLOB:
		printf("\t.global\t%s\n", name);
		if (seg == BSSSEG) {
			printf("\t.comm\t%s,%llu\n",
			       name,
			       (unsigned long long) tp->size);
		}
		break;
	}
	if (sym->type.align != 1)
		printf("\t.align\t%d\n",sym->type.align );
	printf("%s:\n", name);
}

void
writeout(void)
{
}
