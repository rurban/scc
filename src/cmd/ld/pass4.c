#include <stdio.h>
#include <stdlib.h>

#include <scc/mach.h>

#include "ld.h"

void
pass4(int argc, char *argv[])
{
	Objlst *lp;
	Objsect *sp;
	Section *sec;
	unsigned long i;
	FILE *fp;

	for (lp = objhead; lp; lp = lp->next) {
		fp = lp->obj->fp;
		for (sp = lp->obj->secs; sp; sp = sp->next) {
			if (!objpos(lp->obj, lp->obj->fp, sp->seek))
				error("seeking for section content");

			sec = section(sp->name);
			if (!sec->fp) {
				sec->fp = tmpfile();
				if (!sec->fp) {
					error("out of memory");
					exit(EXIT_FAILURE);
				}
			}

			/* TODO: add symbol alignment */

			for (i = 0; i < sp->size; i++)
				putc(getc(fp), sec->fp);

			/* TODO: Apply relocations */
		}
	}
}
