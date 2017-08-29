#define __USE_MACROS
#include <ctype.h>
#undef ctype

unsigned char __ctype[255] = {
	_C,_C,_C,_C,_C,_C,_C,_C,                        /* 0-7 */
	_C,_C|_S,_C|_S,_C|_S,_C|_S,_C|_S,_C,_C,         /* 8-15 */
	_C,_C,_C,_C,_C,_C,_C,_C,                        /* 16-23 */
	_C,_C,_C,_C,_C,_C,_C,_C,                        /* 24-31 */
	_S|_SP,_P,_P,_P,_P,_P,_P,_P,                    /* 32-39 */
	_P,_P,_P,_P,_P,_P,_P,_P,                        /* 40-47 */
	_D,_D,_D,_D,_D,_D,_D,_D,                        /* 48-55 */
	_D,_D,_P,_P,_P,_P,_P,_P,                        /* 56-63 */
	_P,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U,      /* 64-71 */
	_U,_U,_U,_U,_U,_U,_U,_U,                        /* 72-79 */
	_U,_U,_U,_U,_U,_U,_U,_U,                        /* 80-87 */
	_U,_U,_U,_P,_P,_P,_P,_P,                        /* 88-95 */
	_P,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L,      /* 96-103 */
	_L,_L,_L,_L,_L,_L,_L,_L,                        /* 104-111 */
	_L,_L,_L,_L,_L,_L,_L,_L,                        /* 112-119 */
	_L,_L,_L,_P,_P,_P,_P,_C,                        /* 120-127 */
};
