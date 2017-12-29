static char sccsid[] = "@(#) ./as/target/z80/ins.c";

#include <stdlib.h>
#include <string.h>

#include "../../../inc/scc.h"
#include "../../as.h"
#include "proc.h"

int
rclass(int reg)
{
	switch (reg) {
	case AREG_B:
	case AREG_C:
	case AREG_D:
	case AREG_E:
	case AREG_H:
	case AREG_L:
	case AREG_A:
		return 1;
	default:
		return 0;
	}
}

int
pclass(int reg)
{
	switch (reg) {
	case AREG_B:
	case AREG_C:
	case AREG_D:
	case AREG_E:
	case AREG_IXH:
	case AREG_IXL:
	case AREG_A:
		return 1;
	default:
		return 0;
	}
}

int
qclass(int reg)
{
	switch (reg) {
	case AREG_B:
	case AREG_C:
	case AREG_D:
	case AREG_E:
	case AREG_IYH:
	case AREG_IYL:
	case AREG_A:
		return 1;
	default:
		return 0;
	}
}

int
ddclass(int reg)
{
	switch (reg) {
	case AREG_BC:
	case AREG_DE:
	case AREG_HL:
	case AREG_SP:
		return 1;
	default:
		return 0;
	}
}

int
qqclass(int reg)
{
	switch (reg) {
	case AREG_BC:
	case AREG_DE:
	case AREG_HL:
	case AREG_AF:
		return 1;
	default:
		return 0;
	}
}

int
ppclass(int reg)
{
	switch (reg) {
	case AREG_BC:
	case AREG_DE:
	case AREG_IX:
	case AREG_SP:
		return 1;
	default:
		return 0;
	}
}

int
rrclass(int reg)
{
	switch (reg) {
	case AREG_BC:
	case AREG_DE:
	case AREG_IY:
	case AREG_SP:
		return 1;
	default:
		return 0;
	}
}

int
ccclass(int reg)
{
	switch (reg) {
	case AREG_NZ:
	case AREG_Z:
	case AREG_NC:
	case AREG_C:
	case AREG_PO:
	case AREG_PE:
	case AREG_P:
	case AREG_M:
		return 1;
	default:
		return 0;
	}
}

static int
reg2int(int reg)
{
	switch (reg) {
	case AREG_F:
	case AREG_B:   return 0;
	case AREG_C:   return 1;
	case AREG_D:   return 2;
	case AREG_E:   return 3;
	case AREG_IXH:
	case AREG_IYH:
	case AREG_H:   return 4;
	case AREG_IXL:
	case AREG_IYL:
	case AREG_L:   return 5;
	case AREG_A:   return 7;
	case AREG_BC:  return 0;
	case AREG_DE:  return 1;
	case AREG_HL:
	case AREG_IX:
	case AREG_IY:  return 2;
	case AREG_AF:
	case AREG_SP:  return 3;
	default:       abort();
	}
}

static int
flag2int(int flag)
{
	switch (flag) {
	case AREG_NZ:  return 0;
	case AREG_Z:   return 1;
	case AREG_NC:  return 2;
	case AREG_C:   return 3;
	case AREG_PO:  return 4;
	case AREG_PE:  return 5;
	case AREG_P:   return 6;
	case AREG_M:   return 7;
	default:       abort();
	}
}

void
r8_imm8(Op *op, Node **args)
{
	Node *par1, *par2;
	unsigned char buf[3];
	int n = op->size;

	par1 = args[0];
	par2 = args[1];

	memcpy(buf, op->bytes, n);
	buf[n-1] = par2->sym->value;
	buf[n-2] |= reg2int(par1->sym->argtype) << 3;
	emit(buf, n);
}

void
imm8(Op *op, Node **args)
{
	Node *par1, *par2;
	unsigned char buf[3];
	int n = op->size;

	par2 = args[1];

	memcpy(buf, op->bytes, n);
	buf[n-1] = par2->sym->value;
	emit(buf, n);
}

void
imm16(Op *op, Node **args)
{
	Node *imm;
	unsigned char buf[4];
	unsigned val;
	int n = op->size;

	imm = (args[1]) ? args[1] : args[0];
	memcpy(buf, op->bytes, n);
	val = imm->sym->value;
	buf[n-1] = val >> 8;
	buf[n-2] = val;
	emit(buf, n);
}

void
dir(Op *op, Node **args)
{
	Node *dir;

	dir = (args[1]->addr == ADIRECT) ? args[1] : args[0];
	args[1] = dir->left;
	imm16(op, args);
}

void
r8_r8(Op *op, Node **args)
{
	Node *par1, *par2;
	unsigned char buf[3];
	int n = op->size;

	par1 = args[0];
	par2 = args[1];
	memcpy(buf, op->bytes, n);
	buf[n-1] |= reg2int(par1->sym->argtype) << 3 | 
	            reg2int(par2->sym->argtype);
	emit(buf, n);
}

void
r8(Op *op, Node **args)
{
	Node *par;
	unsigned char buf[3];
	int n = op->size;

	par = args[0];
	memcpy(buf, op->bytes, n);
	buf[n-1] |= reg2int(par->sym->argtype);
	emit(buf, n);
}

void
xx_r8(Op *op, Node **args)
{
	args[0] = args[1];
	r8(op, args);
}

void
r8_xx(Op *op, Node **args)
{
	Node *par;
	unsigned char buf[3];
	int n = op->size;

	par = args[0];
	memcpy(buf, op->bytes, n);
	buf[n-1] |= reg2int(par->sym->argtype) << 3;
	emit(buf, n);
}

void
r16_imm16(Op *op, Node **args)
{
	Node *par1, *par2;
	unsigned char buf[4];
	int n = op->size;
	unsigned val;

	par1 = args[0];
	par2 = args[1];

	memcpy(buf, op->bytes, n);
	val = par2->sym->value;
	buf[n-1] = val >> 8;
	buf[n-2] = val;
	buf[n-3] |= reg2int(par1->sym->argtype) << 4;
	emit(buf, n);
}

void
r16_dir(Op *op, Node **args)
{
	Node *dir, *reg;

	if (args[1]->addr == ADIRECT)
		dir = args[1], reg = args[0];
	else
		dir = args[0], reg = args[1];

	args[0] = reg;
	args[1] = dir->left;
	r16_imm16(op, args);
}

void
alu16(Op *op, Node **args)
{
	Node *par;
	int n = op->size;
	unsigned val;
	unsigned char buf[4];

	par = (args[1]) ? args[1] : args[0];
	val = reg2int(par->sym->argtype);
	memcpy(buf, op->bytes, n);
	buf[n-1] |= val << 4;
	emit(buf, n);
}

void
ld16(Op *op, Node **args)
{
	if (!args[1])
		alu16(op, args);
}

void
alu8(Op *op, Node **args)
{
	Node *par = args[1];
	unsigned char buf[4];
	int n = op->size, shift;
	unsigned val;

	if (args[1]) {
		shift = 0;
		par = args[1];
	} else {
		shift = 3;
		par = args[0];
	}

	switch (par->addr) {
	case AIMM:
		val = par->sym->value;
		break;
	case AREG:
		val = reg2int(par->sym->argtype) << shift;
		break;
	case AINDEX:
		val = par->left->right->sym->value;
		break;
	case AINDIR:
		val = 0;
		break;
	default:
		abort();
	}

	memcpy(buf, op->bytes, n);
	buf[n-1] |= val;
	emit(buf, n);
}

void
idx(Op *op, Node **args)
{
	Node *tmp, *idx, *imm, *reg;
	unsigned char buf[4];
	int n = op->size, i = n, shift = 0;

	imm = reg = NULL;
	if (args[0]->addr != AINDEX) {
		shift = 3;
		tmp = args[0];
		args[0] = args[1];
		args[1] = tmp;
	}
	idx = args[0]->left->right;

	if (args[1]) {
		if (args[1]->addr == AREG)
			reg = args[1];
		else
			imm = args[1];
	}
	memcpy(buf, op->bytes, n);

	if (imm)
		buf[--i] = imm->sym->value;
	buf[--i] = idx->sym->value;
	if (reg)
		buf[--i] |= reg2int(reg->sym->argtype) << shift;

	emit(buf, n);
}

void
inout(Op *op, Node **args)
{
	Node *port, *value;
	unsigned val;
	int n = op->size;
	unsigned char buf[5];

	port = args[0];
	value = args[1];
	if (port->addr != ADIRECT && port->addr != AINDIR) {
		value = port;
		port = args[1];
	}

	if (port->addr == ADIRECT)
		val = port->left->sym->value;
	else if (value->addr == AREG)
		val = reg2int(value->sym->argtype) << 3;
	else
		val = 0;

	memcpy(buf, op->bytes, n);
	buf[n-1] |= val;
	emit(buf, n);
}

void
rot_bit(Op *op, Node **args)
{
	Node *par = args[0];
	unsigned char buf[5];
	int n = op->size;
	unsigned val, npar = 0;

	memcpy(buf, op->bytes, n);

	par = args[0];
	if (par->addr == AIMM) {
		buf[n-1] |= par->sym->value << 3;
		par = args[npar = 1];
	}

	switch (par->addr) {
	case AINDEX:
		val = par->left->right->sym->value;
		buf[n-2] = val;
		par = args[npar+1];
		if (!par)
			break;
	case AREG:
		val = reg2int(par->sym->argtype);
		buf[n-1] |= val;
		break;
	case AINDIR:
		break;
	default:
		abort();
	}

	emit(buf, n);
}

void
im(Op *op, Node **args)
{
	unsigned val = args[0]->sym->value;
	unsigned char buf[4];
	int n = op->size;

	if (val > 0)
		++val;

	memcpy(buf, op->bytes, n);
	buf[n-1] |= val << 3;
	emit(buf, n);
}

void
branch(Op *op, Node **args)
{
	unsigned char buf[4];
	Node *flag, *imm;
	int n = op->size, i = n;
	unsigned val;

	flag = imm = NULL;
	if (args[0]->addr == AREG) {
		flag = args[0];
		imm = args[1];
	} else if (args[0]->addr == AIMM) {
		imm = args[0];
	}
	memcpy(buf, op->bytes, n);

	if (imm) {
		val = imm->sym->value;
		buf[--i] = val >> 8;
		buf[--i] = val;
	}
	if (flag)
		buf[--i] |= flag2int(flag->sym->argtype) << 3;

	emit(buf, n);
}

void
rst(Op *op, Node **args)
{
	unsigned char buf[1];

	buf[0] = op->bytes[0];
	buf[0] |= args[0]->sym->value;
	emit(buf, 1);
}
