#include <stdint.h>
#include <stdio.h>

#include "cc.h"

#define SWAP(x1, x2, t) (t = x1, x1 = x2, x2 = t)

Node *expr(void);

static Node *
primary(void)
{
	Node *np;
	Symbol *sym;

	switch (yytoken) {
	case IDEN:
		if ((sym = yylval.sym) == NULL)
			error("'%s' undeclared", yytext);
		np = node(emitsym, sym->type, SYM(sym), 0);
		next();
		break;
	case CONSTANT:
		next();
		/* TODO: do something */
		break;
	case '(':
		next();
		np = expr();
		expect(')');
		break;
	default:
		;
	}
	return np;
}

void
intconv(Node **np1, Node **np2)
{
}

void
floatconv(Node **np1, Node **np2)
{
}

static Node *
add(Node *np1, Node *np2)
{
	Node *naux;
	Type *tp1, *tp2;
	uint8_t t1, t2, taux;

	tp1 = UNQUAL(np1->type), tp2 = UNQUAL(np1->type);
	t1 = tp1->op, t2 = tp2->op;

	switch (t1) {
	case INT:
		switch (t2) {
		case INT:
			if (tp1 != tp2)
				intconv(&np1, &np2);
			break;
		case FLOAT:
			SWAP(np1, np2, naux);
			goto int_float;
		case PTR: case FTN: case ARY:
			SWAP(np1, np2, naux);
			SWAP(t1, t2, taux);
			goto pointer;
		default:
			goto incorrect;
		}
		break;
	case FLOAT:
		switch (t2) {
		case FLOAT:
			if (tp1 != tp2)
				floatconv(&np1, &np2);
			break;
		case INT:
int_float:		np2 = unarycode(OCAST, np1->type, np2);
			break;
		default:
			goto incorrect;
		}
		break;
	case PTR: case FTN: case ARY:
pointer:	if (t1 == PTR)
			np1 = unarycode(OPTR, np1->type, np1);
		if (t2 != INT)
			goto incorrect;
		np2 = unarycode(OCAST, np1->type, np2);
		break;
	default:
		goto incorrect;
	}

	return bincode(OADD, np1, np2);

incorrect:
	error("incorrect arithmetic operands"); /*TODO: print type names */
}

static Node *
array(Node *np1, Node *np2)
{
	Type *tp;
	uint8_t t1, t2;
	char *err;

	t1 = BTYPE(np1->type);
	t2 = BTYPE(np2->type);
	if (!isaddr(t1) && !isaddr(t2))
		goto bad_vector;
	if (t1 != INT && t2 != INT)
		goto bad_subs;
	np1 = add(np1, np2);
	return unarycode(OARY, UNQUAL(np1->type)->type , np1);

bad_vector:
	err = "subscripted value is neither array nor pointer nor vector";
	goto error;
bad_subs:
	err = "array subscript is not an integer";
error:	error(err);
}

static Node *
postfix(void)
{
	Node *np1, *np2;

	np1 = primary();
	for (;;) {
		switch (yytoken) {
		case '[':
			next();
			np2 = expr();
			np1 = array(np1, np2);
			expect(']');
			break;
		default:
			return np1;
		}
	}
}

Node *
expr(void)
{
	Node *np;

	do
		np = postfix();
	while (yytoken == ',');
	return np;
}
