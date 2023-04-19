#include "c.h"
#define I(f) b_##f

static char rcsid[] = "$Id$";

static int cseg;

void bytecode_init(void)
{
	cseg = 0;
}

/*数据段通知*/
static void I(_segment)(int n) {
	//static int cseg;

	if (cseg != n)
		switch (cseg = n) {
		case CODE: print("code\n"); return;
		case DATA: print("data\n"); return;
		case BSS:  print("bss\n");  return;
		case LIT:  print("lit\n");  return;
		default: assert(0);
		}
}
/*struct偏移地址通知*/
static void I(_address)(Symbol q, Symbol p, long n) {

	q->x.name = stringf("%s%s%D", p->x.name, n > 0 ? "+" : "", n);
	q->x.offset = p->x.offset + n;
}
/*处理地址*/
static void I(_defaddress)(Symbol p) {

	print("address %s %d\n", p->x.name, p->x.offset);
}

/*常量通知*/
static void I(_defconst)(int suffix, int size, Value v) {

	switch (suffix) {
	case _I:
		if (size > sizeof(int))
			print("byte %d %D\n", size, v.i);
		else
			print("byte %d %d\n", size, v.i);
		return;
	case U:
		if (size > sizeof(unsigned))
			print("byte %d %U\n", size, v.u);
		else
			print("byte %d %u\n", size, v.u);
		return;
	case P: print("byte %d %U\n", size, (unsigned long)v.p); return;
	case F:
		if (size == 4) {
			float f = v.d;
			print("byte 4 %u\n", *(unsigned*)&f);
		}
		else {
			double d = v.d;
			unsigned* p = (unsigned*)&d;
			print("byte 4 %u\n", p[swap]);
			print("byte 4 %u\n", p[1 - swap]);
		}
		return;
	}
	assert(0);
}
/*字符串通知-实际内容*/
static void I(_defstring)(int len, char* str) {
	char* s;

	for (s = str; s < str + len; s++)
		print("byte 1 %d\n", (*s) & 0377);
}
/*符号通知*/
static void I(_defsymbol)(Symbol p) {
	if (p->scope == CONSTANTS)
		switch (optype(ttob(p->type))) {
		case _I: p->x.name = stringf("%D", p->u.c.v.i); break;
		case U: p->x.name = stringf("%U", p->u.c.v.u); break;
		case P: p->x.name = stringf("%U", p->u.c.v.p); break;
		case F: p->x.name = stringf("%f", p->u.c.v.d); break;
		default: assert(0);
		}
	else if (p->scope >= LOCAL && p->sclass == STATIC)
		p->x.name = stringf("$%d", genlabel(1));
	else if (p->scope == LABELS || p->generated)
		p->x.name = stringf("$%s", p->name);
	else
		p->x.name = p->name;
}

static void dumptree(Node p) {
	switch (specific(p->op)) {
	case ASGN + B:
		assert(p->kids[0]);
		assert(p->kids[1]);
		assert(p->syms[0]);
		dumptree(p->kids[0]);
		dumptree(p->kids[1]);
		print("%s %d\n", opname(p->op), p->syms[0]->u.c.v.u);
		return;
	case RET + V:
		assert(!p->kids[0]);
		assert(!p->kids[1]);
		print("%s\n", opname(p->op));
		return;
	}
	switch (generic(p->op)) {
	case CNST:
		assert(!p->kids[0]);
		assert(!p->kids[1]);
		assert(p->syms[0] && p->syms[0]->x.name);
		print("%s %s\n", opname(p->op), p->syms[0]->x.name);
		return;
	case ADDRG: case ADDRF: case ADDRL: case LABEL:
		assert(!p->kids[0]);
		assert(!p->kids[1]);
		assert(p->syms[0] && p->syms[0]->x.name);
		print("%s %s\n", opname(p->op), p->syms[0]->x.name);
		return;
	case CVF: case CVI: case CVP: case CVU:
		assert(p->kids[0]);
		assert(!p->kids[1]);
		assert(p->syms[0]);
		dumptree(p->kids[0]);
		print("%s %d\n", opname(p->op), p->syms[0]->u.c.v.i);
		return;
	case ARG: case BCOM: case NEG: case INDIR: case JUMP: case RET:
		assert(p->kids[0]);
		assert(!p->kids[1]);
		dumptree(p->kids[0]);
		print("%s\n", opname(p->op));
		return;
	case CALL:
		assert(p->kids[0]);
		assert(!p->kids[1]);
		assert(optype(p->op) != B);
		dumptree(p->kids[0]);
		print("%s\n", opname(p->op));
		return;
	case ASGN: case BOR: case BAND: case BXOR: case RSH: case LSH:
	case ADD: case SUB: case DIV: case MUL: case MOD:
		assert(p->kids[0]);
		assert(p->kids[1]);
		if (generic(p->op) == ASGN)
		{
			int x = 0;
		}
		dumptree(p->kids[0]);
		dumptree(p->kids[1]);
		print("%s\n", opname(p->op));
		return;
	case EQ: case NE: case GT: case GE: case LE: case LT:
		assert(p->kids[0]);
		assert(p->kids[1]);
		assert(p->syms[0]);
		assert(p->syms[0]->x.name);
		dumptree(p->kids[0]);
		dumptree(p->kids[1]);
		print("%s %s\n", opname(p->op), p->syms[0]->x.name);
		return;
	}
	assert(0);
}


void I(_emit)(Node p) {
	for (; p; p = p->link)
		dumptree(p);
}

/*输出符号通知*/
static void I(_export)(Symbol p) {
	print("export %s\n", p->x.name);
}
/*263*/
static void I(_function)(Symbol f, Symbol caller[], Symbol callee[], int ncalls) {
	int i;

	(*IR->_segment)(CODE);
	offset = 0;
	for (i = 0; caller[i] && callee[i]; i++) {
		offset = roundup(offset, caller[i]->type->align);
		caller[i]->x.name = callee[i]->x.name = stringf("%d", offset);
		caller[i]->x.offset = callee[i]->x.offset = offset;
		offset += caller[i]->type->size;
	}
	//maxargoffset = maxoffset = argoffset = offset = 0;
	maxoffset = offset;
	maxargoffset = argoffset = 0;

	gencode(caller, callee);
	print("proc %s %d %d\n", f->x.name, maxoffset, maxargoffset);
	emitcode();
	print("endproc %s %d %d\n", f->x.name, maxoffset, maxargoffset);

}

static void gen02(Node p) {
	assert(p);
	if (generic(p->op) == ARG) {
		assert(p->syms[0]);
		argoffset += (p->syms[0]->u.c.v.i < 4 ? 4 : p->syms[0]->u.c.v.i);
	}
	else if (generic(p->op) == CALL) {
		maxargoffset = (argoffset > maxargoffset ? argoffset : maxargoffset);
		argoffset = 0;
	}
}

static void gen01(Node p) {
	if (p) {
		gen01(p->kids[0]);
		gen01(p->kids[1]);
		gen02(p);
	}
}

static Node I(_gen)(Node p) {
	Node q;

	assert(p);
	for (q = p; q; q = q->link)
		gen01(q);
	return p;
}
/*全局标号通知*/
static void I(_global)(Symbol p) {

	print("align %d\n", p->type->align > 4 ? 4 : p->type->align);
	print("LABELV %s\n", p->x.name);
}
/*引进符号通知*/
static void I(_import)(Symbol p) {

	print("import %s\n", p->x.name);
}

/*局部变量分配地址递增(不包含参数)*/
static void I(_local)(Symbol p) {

	offset = roundup(offset, p->type->align);
	p->x.name = stringf("%d", offset);
	p->x.offset = offset;
	offset += p->type->size;

}


static void I(_progbeg)(int argc, char* argv[])
{
	bytecode_init();
}

static void I(_progend)(void) {}
/*空间通知*/
static void I(_space)(int n) {

	print("skip %d\n", n);
}

static void I(_stabline)(Coordinate* cp) {
	static char* prevfile;
	static int prevline;

	if (cp->file && (prevfile == NULL || strcmp(prevfile, cp->file) != 0)) {
		print("file \"%s\"\n", prevfile = cp->file);
		prevline = 0;
	}
	if (cp->y != prevline)
		print("line %d\n", prevline = cp->y);
}

#define b__blockbeg blockbeg
#define b__blockend blockend

_Interface bytecodeIR = {
	1, 1, 0,	/* char */
	2, 1, 0,	/* short */
	1, 1, 0,	/* int */
	4, 1, 0,	/* long */
	8, 1, 0,	/* long long */
	4, 1, 0,	/* float */
	8, 1, 0,	/* double */
	8, 1, 0,	/* long double */
	4, 1, 0,	/* T* */
	0, 1, 0,	/* struct */
	1,		/* little_endian */
	0,		/* mulops_calls */
	0,		/* wants_callb */
	0,		/* wants_argb */
	1,		/* left_to_right */
	1,		/* wants_dag */
	0,		/* unsigned_char */
	I(_address),
	I(_blockbeg),
	I(_blockend),
	I(_defaddress),
	I(_defconst),
	I(_defstring),
	I(_defsymbol),
	I(_emit),
	I(_export),
	I(_function),
	I(_gen),
	I(_global),
	I(_import),
	I(_local),
	I(_progbeg),
	I(_progend),
	I(_segment),
	I(_space),
	0,		/* I(stabblock) */
	0,		/* I(stabend) */
	0,		/* I(stabfend) */
	0,		/* I(stabinit) */
	I(_stabline),
	0,		/* I(stabsym) */
	0,		/* I(stabtype) */
};
