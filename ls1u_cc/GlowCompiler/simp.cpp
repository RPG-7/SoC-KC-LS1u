#include "pch.h"

#include "c.h"
#include <float.h>

static char rcsid[] = "$Id$";

#define foldcnst(TYPE,VAR,OP) \
	if (l->op == CNST+TYPE && r->op == CNST+TYPE) \
		return cnsttree(ty, l->u.v.VAR OP r->u.v.VAR)
#define commute(L,R) \
	if (generic(R->op) == CNST && generic(L->op) != CNST) \
		do { Tree t = L; L = R; R = t; } while(0)
#define xfoldcnst(TYPE,VAR,OP,FUNC)\
	if (l->op == CNST+TYPE && r->op == CNST+TYPE\
	&& FUNC(l->u.v.VAR,r->u.v.VAR,\
		ty->u.sym->u.limits.min.VAR,\
		ty->u.sym->u.limits.max.VAR, needconst)) \
		return cnsttree(ty, l->u.v.VAR OP r->u.v.VAR)
#define xcvtcnst(FTYPE,SRC,DST,VAR,EXPR) \
	if (l->op == CNST+FTYPE) do {\
		if (!explicitCast\
		&&  ((SRC) < DST->u.sym->u.limits.min.VAR || (SRC) > DST->u.sym->u.limits.max.VAR))\
			warning("overflow in converting constant expression from `%t' to `%t'\n", l->type, DST);\
		if (needconst\
		|| !((SRC) < DST->u.sym->u.limits.min.VAR || (SRC) > DST->u.sym->u.limits.max.VAR))\
			return cnsttree(ty, (EXPR)); } while(0)
#define identity(X,Y,TYPE,VAR,VAL) \
	if (X->op == CNST+TYPE && X->u.v.VAR == VAL) return Y
#define zerofield(OP,TYPE,VAR) \
	if (l->op == FIELD \
	&&  r->op == CNST+TYPE && r->u.v.VAR == 0)\
		return eqtree(OP, bittree(BAND, l->kids[0],\
			cnsttree(unsignedtype, \
				(unsigned long)fieldmask(l->u.field)<<fieldright(l->u.field))), r)
#define cfoldcnst(TYPE,VAR,OP) \
	if (l->op == CNST+TYPE && r->op == CNST+TYPE) \
		return cnsttree(inttype, (long)(l->u.v.VAR OP r->u.v.VAR))
#define foldaddp(L,R,RTYPE,VAR) \
	if (L->op == CNST+P && R->op == CNST+RTYPE) { \
		Tree e = tree(CNST+P, ty, NULL, NULL);\
		e->u.v.p = (char *)L->u.v.p + R->u.v.VAR;\
		return e; }
#define ufoldcnst(TYPE,EXP) if (l->op == CNST+TYPE) return EXP
/*??????64¦Ë,2022.2.24*/
#define sfoldcnst(OP) \
	if (l->op == CNST+U && r->op == CNST+_I \
	&& r->u.v.i >= 0 && r->u.v.i < 8*l->type->size) \
		return cnsttree(ty, (unsigned long long)(l->u.v.u OP r->u.v.i))
/*
#define sfoldcnst(OP) \
	if (l->op == CNST+U && r->op == CNST+_I \
	&& r->u.v.i >= 0 && r->u.v.i < 8*l->type->size) \
		return cnsttree(ty, (unsigned long)(l->u.v.u OP r->u.v.i))
*/
#define geu(L,R,V) \
	if (R->op == CNST+U && R->u.v.u == 0) do { \
		warning("result of unsigned comparison is constant\n"); \
		return tree(RIGHT, inttype, root(L), cnsttree(inttype, (long)(V))); } while(0)
#define idempotent(OP) if (l->op == OP) return l->kids[0]

int needconst;
int explicitCast;

void simp_init(void) {
	needconst = 0;
	explicitCast = 0;
}
/*??????64¦Ë,2022.2.24*/
static int addi(long long x, long long y, long long min, long long max, int needconst) {
	int cond = x == 0 || y == 0
		|| x < 0 && y < 0 && x >= min - y
		|| x < 0 && y > 0
		|| x > 0 && y < 0
		|| x > 0 && y > 0 && x <= max - y;
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;
}
/*
static int addi(long x, long y, long min, long max, int needconst) {
	int cond = x == 0 || y == 0
		|| x < 0 && y < 0 && x >= min - y
		|| x < 0 && y > 0
		|| x > 0 && y < 0
		|| x > 0 && y > 0 && x <= max - y;
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;


}
*/
static int addd(double x, double y, double min, double max, int needconst) {
	int cond = x == 0 || y == 0
		|| x < 0 && y < 0 && x >= min - y
		|| x < 0 && y > 0
		|| x > 0 && y < 0
		|| x > 0 && y > 0 && x <= max - y;
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;


}

static Tree addrtree(Tree e, long n, Type ty) {
	Symbol p = e->u.sym, q;

	if (p->scope == GLOBAL
		|| p->sclass == STATIC || p->sclass == EXTERN)

		//NEW0(q, PERM);
	    memset(q = (Symbol)allocate(sizeof * q, PERM), 0, sizeof * q);

	else
		//NEW0(q, FUNC);
	    memset(q = (Symbol)allocate(sizeof * q, FUNC), 0, sizeof * q);

	q->name = stringd(genlabel(1));
	q->sclass = p->sclass;
	q->scope = p->scope;
	assert(isptr(ty) || isarray(ty));
	q->type = isptr(ty) ? ty->type : ty;
	q->temporary = p->temporary;
	q->generated = p->generated;
	q->addressed = p->addressed;
	q->computed = 1;
	q->defined = 1;
	q->ref = 1;
	assert(IR->_address);
	if (p->scope == GLOBAL
		|| p->sclass == STATIC || p->sclass == EXTERN) {
		if (p->sclass == AUTO)
			q->sclass = STATIC;
		(*IR->_address)(q, p, n);
	}
	else {
		Code cp;
		addlocal(p);
		cp = code(code::Address);
		cp->u.addr.sym = q;
		cp->u.addr.base = p;
		cp->u.addr.offset = n;
	}
	e = tree(e->op, ty, NULL, NULL);
	e->u.sym = q;
	return e;
}

/*??????64¦Ë,2022.2.24*/
static int divi(long long x, long long y, long long min, long long max, int needconst) {
	int cond = y != 0 && !(x == min && y == -1);
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;
}
/* div[id] - return 1 if min <= x/y <= max, 0 otherwise *//*
static int divi(long x, long y, long min, long max, int needconst) {
	int cond = y != 0 && !(x == min && y == -1);
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;


}
*/
static int divd(double x, double y, double min, double max, int needconst) {
	int cond;

	if (x < 0) x = -x;
	if (y < 0) y = -y;
	cond = y != 0 && !(y < 1 && x > max * y);
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;

}

/*??????64¦Ë,2022.2.24*/
static int muli(long long x, long long y, long long min, long long max, int needconst) {
	int cond = x > -1 && x <= 1 || y > -1 && y <= 1
		|| x < 0 && y < 0 && -x <= max / -y
		|| x < 0 && y > 0 && x >= min / y
		|| x > 0 && y < 0 && y >= min / x
		|| x > 0 && y > 0 && x <= max / y;
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;
}

/* mul[id] - return 1 if min <= x*y <= max, 0 otherwise *//*
static int muli(long x, long y, long min, long max, int needconst) {
	int cond = x > -1 && x <= 1 || y > -1 && y <= 1
		|| x < 0 && y < 0 && -x <= max / -y
		|| x < 0 && y > 0 && x >= min / y
		|| x > 0 && y < 0 && y >= min / x
		|| x > 0 && y > 0 && x <= max / y;
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;


}
*/

static int muld(double x, double y, double min, double max, int needconst) {
	int cond = x >= -1 && x <= 1 || y >= -1 && y <= 1
		|| x < 0 && y < 0 && -x <= max / -y
		|| x < 0 && y > 0 && x >= min / y
		|| x > 0 && y < 0 && y >= min / x
		|| x > 0 && y > 0 && x <= max / y;
	if (!cond && needconst) {
		warning("overflow in constant expression\n");
		cond = 1;
	}
	return cond;


}

/*??????64¦Ë,2022.2.24*/
static int subi(long long x, long long y, long long min, long long max, int needconst) {
	return addi(x, -y, min, max, needconst);
}

/* sub[id] - return 1 if min <= x-y <= max, 0 otherwise *//*
static int subi(long x, long y, long min, long max, int needconst) {
	return addi(x, -y, min, max, needconst);
}
*/

static int subd(double x, double y, double min, double max, int needconst) {
	return addd(x, -y, min, max, needconst);
}
Tree _constexpr(int tok) {
	Tree p;

	needconst++;
	p = expr1(tok);
	needconst--;
	return p;
}

int intexpr(int tok, int n) {
	Tree p = _constexpr(tok);

	needconst++;
	if (p->op == CNST + _I || p->op == CNST + U)
		n = cast(p, inttype)->u.v.i;
	else
		error("integer expression must be constant\n");
	needconst--;
	return n;
}
/*??????,???????,135*/
Tree simplify(int op, Type ty, Tree l, Tree r) {
	int n;
	Tree p;

	if (optype(op) == 0)
		op = mkop(op, ty);
	switch (op) {
	case ADD + U:
		foldcnst(U, u, +);
		commute(r, l);
		identity(r, l, U, u, 0);
		break;
	case ADD + _I:
		xfoldcnst(_I, i, +, addi);
		commute(r, l);
		identity(r, l, _I, i, 0);
		break;
	case CVI + _I:
		xcvtcnst(_I, l->u.v.i, ty, i, (long long)extend(l->u.v.i, ty)); //??????64¦Ë,2022.2.24
		//xcvtcnst(_I, l->u.v.i, ty, i, (long)extend(l->u.v.i, ty));
		break;
	case CVU + _I:
		if (l->op == CNST + U) {
			if (!explicitCast && l->u.v.u > ty->u.sym->u.limits.max.i)
				warning("overflow in converting constant expression from `%t' to `%t'\n", l->type, ty);
			if (needconst || !(l->u.v.u > ty->u.sym->u.limits.max.i))
				return cnsttree(ty, (long long)extend(l->u.v.u, ty)); //??????64¦Ë,2022.2.24
				//return cnsttree(ty, (long)extend(l->u.v.u, ty));
		}
		break;
	case CVP + U:
		xcvtcnst(P, (unsigned long)l->u.v.p, ty, u, (unsigned long)l->u.v.p);
		break;
	case CVU + P:
		xcvtcnst(U, (void*)l->u.v.u, ty, p, (void*)l->u.v.u);
		break;
	case CVP + P:
		xcvtcnst(P, l->u.v.p, ty, p, l->u.v.p);
		break;
	case CVI + U:
		xcvtcnst(_I, l->u.v.i, ty, u, ((unsigned long long)l->u.v.i) & ones(8 * ty->size)); //??????64¦Ë,2022.2.24
		//xcvtcnst(_I, l->u.v.i, ty, u, ((unsigned long)l->u.v.i) & ones(8 * ty->size));
		break;
	case CVU + U:
		xcvtcnst(U, l->u.v.u, ty, u, l->u.v.u & ones(8 * ty->size));
		break;
	case CVI + F:
		xcvtcnst(_I, l->u.v.i, ty, d, (long double)l->u.v.i);
	case CVU + F:
		xcvtcnst(U, l->u.v.u, ty, d, (long double)l->u.v.u);
		break;
	case CVF + _I:
		xcvtcnst(F, l->u.v.d, ty, i, (long long)l->u.v.d); //??????64¦Ë,2022.2.24
		//xcvtcnst(F, l->u.v.d, ty, i, (long)l->u.v.d);
		break;
	case CVF + F: {
		float d;
		if (l->op == CNST + F)
			if (l->u.v.d < ty->u.sym->u.limits.min.d)
				d = ty->u.sym->u.limits.min.d;
			else if (l->u.v.d > ty->u.sym->u.limits.max.d)
				d = ty->u.sym->u.limits.max.d;
			else
				d = l->u.v.d;
		xcvtcnst(F, l->u.v.d, ty, d, (long double)d);
		break;
	}
	case BAND + U:
		foldcnst(U, u, &);
		commute(r, l);
		identity(r, l, U, u, ones(8 * ty->size));
		if (r->op == CNST + U && r->u.v.u == 0)
			return tree(RIGHT, ty, root(l), cnsttree(ty, 0ULL)); //??????64¦Ë,2022.2.24
			//return tree(RIGHT, ty, root(l), cnsttree(ty, 0UL));
		break;
	case BAND + _I:
		foldcnst(_I, i, &);
		commute(r, l);
		identity(r, l, _I, i, ones(8 * ty->size));
		if (r->op == CNST + _I && r->u.v.u == 0)
			return tree(RIGHT, ty, root(l), cnsttree(ty, 0LL)); //??????64¦Ë,2022.2.24
			//return tree(RIGHT, ty, root(l), cnsttree(ty, 0L));
		break;

	case MUL + U:
		commute(l, r);
		if (l->op == CNST + U && (n = ispow2(l->u.v.u)) != 0)
			return simplify(LSH, ty, r, cnsttree(inttype, (long)n));
		foldcnst(U, u, *);
		identity(r, l, U, u, 1);
		break;
	case NE + _I:
		cfoldcnst(_I, i, != );
		commute(r, l);
		zerofield(NE, _I, i);
		break;

	case EQ + _I:
		cfoldcnst(_I, i, == );
		commute(r, l);
		zerofield(EQ, _I, i);
		break;
	case ADD + P:
		foldaddp(l, r, _I, i);
		foldaddp(l, r, U, u);
		foldaddp(r, l, _I, i);
		foldaddp(r, l, U, u);
		commute(r, l);
		identity(r, retype(l, ty), _I, i, 0);
		identity(r, retype(l, ty), U, u, 0);
		/*
		Some assemblers, e.g., the MIPS, can't handle offsets
		larger than 16 bits. A better solution would be to change
		the interface so that address() could fail.
		*/
		if (l->op == ADDRG + P && l->u.sym->generated
			&& (r->op == CNST + _I && (r->u.v.i > 32767 || r->u.v.i < -32768)
				|| r->op == CNST + U && r->u.v.u > 65536))
			break;
		if (IR->_address
			&& isaddrop(l->op)
			&& (r->op == CNST + _I && r->u.v.i <= longtype->u.sym->u.limits.max.i
				&& r->u.v.i >= longtype->u.sym->u.limits.min.i
				|| r->op == CNST + U && r->u.v.u <= longtype->u.sym->u.limits.max.i))
			return addrtree(l, cast(r, longtype)->u.v.i, ty);
		if (IR->_address
			&& l->op == ADD + P && isaddrop(l->kids[1]->op)
			&& (r->op == CNST + _I && r->u.v.i <= longtype->u.sym->u.limits.max.i
				&& r->u.v.i >= longtype->u.sym->u.limits.min.i
				|| r->op == CNST + U && r->u.v.u <= longtype->u.sym->u.limits.max.i))
			return simplify(ADD + P, ty, l->kids[0],
				addrtree(l->kids[1], cast(r, longtype)->u.v.i, ty));
		if ((l->op == ADD + _I || l->op == SUB + _I)
			&& l->kids[1]->op == CNST + _I && isaddrop(r->op))
			return simplify(ADD + P, ty, l->kids[0],
				simplify(generic(l->op) + P, ty, r, l->kids[1]));
		if (l->op == ADD + P && generic(l->kids[1]->op) == CNST
			&& generic(r->op) == CNST)
			return simplify(ADD + P, ty, l->kids[0],
				simplify(ADD, l->kids[1]->type, l->kids[1], r));
		if (l->op == ADD + _I && generic(l->kids[1]->op) == CNST
			&& r->op == ADD + P && generic(r->kids[1]->op) == CNST)
			return simplify(ADD + P, ty, l->kids[0],
				simplify(ADD + P, ty, r->kids[0],
					simplify(ADD, r->kids[1]->type, l->kids[1], r->kids[1])));
		if (l->op == RIGHT && l->kids[1])
			return tree(RIGHT, ty, l->kids[0],
				simplify(ADD + P, ty, l->kids[1], r));
		else if (l->op == RIGHT && l->kids[0])
			return tree(RIGHT, ty,
				simplify(ADD + P, ty, l->kids[0], r), NULL);
		break;

	case ADD + F:
		xfoldcnst(F, d, +, addd);
		commute(r, l);
		break;
	case AND + _I:
		op = AND;
		ufoldcnst(_I, l->u.v.i ? cond(r) : l);	/* 0&&r => 0, 1&&r => r */
		break;
	case OR + _I:
		op = OR;
		/* 0||r => r, 1||r => 1 */
		ufoldcnst(_I, l->u.v.i ? cnsttree(ty, 1LL) : cond(r));  //??????64¦Ë,2022.2.24
		//ufoldcnst(_I, l->u.v.i ? cnsttree(ty, 1L) : cond(r));
		break;
	case BCOM + _I:
		ufoldcnst(_I, cnsttree(ty, (long long)extend((~l->u.v.i) & ones(8 * ty->size), ty)));  //??????64¦Ë,2022.2.24
		//ufoldcnst(_I, cnsttree(ty, (long)extend((~l->u.v.i) & ones(8 * ty->size), ty)));
		idempotent(BCOM + U);
		break;
	case BCOM + U:
		ufoldcnst(U, cnsttree(ty, (unsigned long long)((~l->u.v.u) & ones(8 * ty->size))));  //??????64¦Ë,2022.2.24
		//ufoldcnst(U, cnsttree(ty, (unsigned long)((~l->u.v.u) & ones(8 * ty->size))));
		idempotent(BCOM + U);
		break;
	case BOR + U:
		foldcnst(U, u, | );
		commute(r, l);
		identity(r, l, U, u, 0);
		break;
	case BOR + _I:
		foldcnst(_I, i, | );
		commute(r, l);
		identity(r, l, _I, i, 0);
		break;
	case BXOR + U:
		foldcnst(U, u, ^);
		commute(r, l);
		identity(r, l, U, u, 0);
		break;
	case BXOR + _I:
		foldcnst(_I, i, ^);
		commute(r, l);
		identity(r, l, _I, i, 0);
		break;
	case DIV + F:
		xfoldcnst(F, d, / , divd);
		break;
	case DIV + _I:
		identity(r, l, _I, i, 1);
		if (r->op == CNST + _I && r->u.v.i == 0
			|| l->op == CNST + _I && l->u.v.i == ty->u.sym->u.limits.min.i
			&& r->op == CNST + _I && r->u.v.i == -1)
			break;
		xfoldcnst(_I, i, / , divi);
		break;
	case DIV + U:
		identity(r, l, U, u, 1);
		if (r->op == CNST + U && r->u.v.u == 0)
			break;
		if (r->op == CNST + U && (n = ispow2(r->u.v.u)) != 0)
			return simplify(RSH, ty, l, cnsttree(inttype, (long)n));
		foldcnst(U, u, / );
		break;
	case EQ + F:
		cfoldcnst(F, d, == );
		commute(r, l);
		break;
	case EQ + U:
		cfoldcnst(U, u, == );
		commute(r, l);
		zerofield(EQ, U, u);
		break;
	case GE + F: cfoldcnst(F, d, >= ); break;
	case GE + _I: cfoldcnst(_I, i, >= ); break;
	case GE + U:
		geu(l, r, 1);	/* l >= 0 => (l,1) */
		cfoldcnst(U, u, >= );
		if (l->op == CNST + U && l->u.v.u == 0)	/* 0 >= r => r == 0 */
			return eqtree(EQ, r, l);
		break;
	case GT + F: cfoldcnst(F, d, > ); break;
	case GT + _I: cfoldcnst(_I, i, > ); break;
	case GT + U:
		geu(r, l, 0);	/* 0 > r => (r,0) */
		cfoldcnst(U, u, > );
		if (r->op == CNST + U && r->u.v.u == 0)	/* l > 0 => l != 0 */
			return eqtree(NE, l, r);
		break;
	case LE + F: cfoldcnst(F, d, <= ); break;
	case LE + _I: cfoldcnst(_I, i, <= ); break;
	case LE + U:
		geu(r, l, 1);	/* 0 <= r => (r,1) */
		cfoldcnst(U, u, <= );
		if (r->op == CNST + U && r->u.v.u == 0)	/* l <= 0 => l == 0 */
			return eqtree(EQ, l, r);
		break;
	case LSH + _I:
		identity(r, l, _I, i, 0);
		if (l->op == CNST + _I && r->op == CNST + _I
			&& r->u.v.i >= 0 && r->u.v.i < 8 * l->type->size
			&& muli(l->u.v.i, 1 << r->u.v.i, ty->u.sym->u.limits.min.i, ty->u.sym->u.limits.max.i, needconst))
			return cnsttree(ty, (long long)(l->u.v.i << r->u.v.i));   //??????64¦Ë,2022.2.24
			//return cnsttree(ty, (long)(l->u.v.i << r->u.v.i));
		if (r->op == CNST + _I && (r->u.v.i >= 8 * ty->size || r->u.v.i < 0)) {
			warning("shifting an `%t' by %d bits is undefined\n", ty, r->u.v.i);
			break;
		}

		break;
	case LSH + U:
		identity(r, l, _I, i, 0);
		sfoldcnst(<< );
		if (r->op == CNST + _I && (r->u.v.i >= 8 * ty->size || r->u.v.i < 0)) {
			warning("shifting an `%t' by %d bits is undefined\n", ty, r->u.v.i);
			break;
		}

		break;

	case LT + F: cfoldcnst(F, d, < ); break;
	case LT + _I: cfoldcnst(_I, i, < ); break;
	case LT + U:
		geu(l, r, 0);	/* l < 0 => (l,0) */
		cfoldcnst(U, u, < );
		if (l->op == CNST + U && l->u.v.u == 0)	/* 0 < r => r != 0 */
			return eqtree(NE, r, l);
		break;
	case MOD + _I:
		if (r->op == CNST + _I && r->u.v.i == 0
			|| l->op == CNST + _I && l->u.v.i == ty->u.sym->u.limits.min.i
			&& r->op == CNST + _I && r->u.v.i == -1)
			break;
		xfoldcnst(_I, i, %, divi);
		if (r->op == CNST + _I && r->u.v.i == 1)	/* l%1 => (l,0) */
			return tree(RIGHT, ty, root(l), cnsttree(ty, 0LL));   //??????64¦Ë,2022.2.25
			//return tree(RIGHT, ty, root(l), cnsttree(ty, 0L));
		break;
	case MOD + U:
		if (r->op == CNST + U && ispow2(r->u.v.u)) /* l%2^n => l&(2^n-1) */
			return bittree(BAND, l, cnsttree(ty, r->u.v.u - 1));
		if (r->op == CNST + U && r->u.v.u == 0)
			break;
		foldcnst(U, u, %);
		break;
	case MUL + F:
		xfoldcnst(F, d, *, muld);
		commute(l, r);
		break;
	case MUL + _I:
		commute(l, r);
		xfoldcnst(_I, i, *, muli);
		if (l->op == CNST + _I && r->op == ADD + _I && r->kids[1]->op == CNST + _I)
			/* c1*(x + c2) => c1*x + c1*c2 */
			return simplify(ADD, ty, simplify(MUL, ty, l, r->kids[0]),
				simplify(MUL, ty, l, r->kids[1]));
		if (l->op == CNST + _I && r->op == SUB + _I && r->kids[1]->op == CNST + _I)
			/* c1*(x - c2) => c1*x - c1*c2 */
			return simplify(SUB, ty, simplify(MUL, ty, l, r->kids[0]),
				simplify(MUL, ty, l, r->kids[1]));
		if (l->op == CNST + _I && l->u.v.i > 0 && (n = ispow2(l->u.v.i)) != 0)
			/* 2^n * r => r<<n */
			return simplify(LSH, ty, r, cnsttree(inttype, (long)n));
		identity(r, l, _I, i, 1);
		break;
	case NE + F:
		cfoldcnst(F, d, != );
		commute(r, l);
		break;
	case NE + U:
		cfoldcnst(U, u, != );
		commute(r, l);
		zerofield(NE, U, u);
		break;
	case NEG + F:
		ufoldcnst(F, cnsttree(ty, -l->u.v.d));
		idempotent(NEG + F);
		break;
	case NEG + _I:
		if (l->op == CNST + _I) {
			if (needconst && l->u.v.i == ty->u.sym->u.limits.min.i)
				warning("overflow in constant expression\n");
			if (needconst || l->u.v.i != ty->u.sym->u.limits.min.i)
				return cnsttree(ty, -l->u.v.i);
		}
		idempotent(NEG + _I);
		break;
	case NOT + _I:
		op = NOT;
		ufoldcnst(_I, cnsttree(ty, !l->u.v.i));
		break;
	case RSH + _I:
		identity(r, l, _I, i, 0);
		if (l->op == CNST + _I && r->op == CNST + _I
			&& r->u.v.i >= 0 && r->u.v.i < 8 * l->type->size) {
			/*??????64¦Ë,2022.2.24*/
			long long n = l->u.v.i >> r->u.v.i;
			if (l->u.v.i < 0)
				n |= ~0ULL << (8 * l->type->size - r->u.v.i);
			return cnsttree(ty, n);
			/*
			long n = l->u.v.i >> r->u.v.i;
			if (l->u.v.i < 0)
				n |= ~0UL << (8 * l->type->size - r->u.v.i);
			return cnsttree(ty, n);
			*/
		}
		if (r->op == CNST + _I && (r->u.v.i >= 8 * ty->size || r->u.v.i < 0)) {
			warning("shifting an `%t' by %d bits is undefined\n", ty, r->u.v.i);
			break;
		}

		break;
	case RSH + U:
		identity(r, l, _I, i, 0);
		sfoldcnst(>> );
		if (r->op == CNST + _I && (r->u.v.i >= 8 * ty->size || r->u.v.i < 0)) {
			warning("shifting an `%t' by %d bits is undefined\n", ty, r->u.v.i);
			break;
		}

		break;
	case SUB + F:
		xfoldcnst(F, d, -, subd);
		break;
	case SUB + _I:
		xfoldcnst(_I, i, -, subi);
		identity(r, l, _I, i, 0);
		break;
	case SUB + U:
		foldcnst(U, u, -);
		identity(r, l, U, u, 0);
		break;
	case SUB + P:
		if (l->op == CNST + P && r->op == CNST + P)
			return cnsttree(ty, (long)((char*)l->u.v.p - (char*)r->u.v.p));
		if (r->op == CNST + _I || r->op == CNST + U)
			return simplify(ADD, ty, l,
				cnsttree(inttype, r->op == CNST + _I ? -r->u.v.i : -(long)r->u.v.u));
		if (isaddrop(l->op) && r->op == ADD + _I && r->kids[1]->op == CNST + _I)
			/* l - (x + c) => l-c - x */
			return simplify(SUB, ty,
				simplify(SUB, ty, l, r->kids[1]), r->kids[0]);
		break;
	default:assert(0);
	}
	return tree(op, ty, l, r);
}
/* ispow2 - if u > 1 && u == 2^n, return n, otherwise return 0 */
int ispow2(unsigned long u) {
	int n;

	if (u > 1 && (u & (u - 1)) == 0)
		for (n = 0; u; u >>= 1, n++)
			if (u & 1)
				return n;
	return 0;
}

