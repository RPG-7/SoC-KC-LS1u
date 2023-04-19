#include "c.h"

static char rcsid[] = "$Id$";

static Tree addtree(int, Tree, Tree);
static Tree andtree(int, Tree, Tree);
static Tree cmptree(int, Tree, Tree);
static int compatible(Type, Type);
static int isnullptr(Tree e);
static Tree multree(int, Tree, Tree);
static Tree subtree(int, Tree, Tree);
#define isvoidptr(ty) \
	(isptr(ty) && unqual(ty->type) == voidtype)
/*136,148*/
Tree(*optree[])(int, Tree, Tree) = {
#define xx(a,b,c,d,e,f,g) e,
#define yy(a,b,c,d,e,f,g) e,
yy(0, 0, 0, 0, 0, 0, 0)
xx(_FLOAT, 1, 0, 0, 0, _CHAR, "float")
xx(_DOUBLE, 2, 0, 0, 0, _CHAR, "double")
xx(_CHAR, 3, 0, 0, 0, _CHAR, "char")
xx(_SHORT, 4, 0, 0, 0, _CHAR, "short")
xx(_INT, 5, 0, 0, 0, _CHAR, "int")
xx(_UNSIGNED, 6, 0, 0, 0, _CHAR, "unsigned")
xx(_POINTER, 7, 0, 0, 0, 0, "pointer")
xx(_VOID, 8, 0, 0, 0, _CHAR, "void")
xx(_STRUCT, 9, 0, 0, 0, _CHAR, "struct")
xx(_UNION, 10, 0, 0, 0, _CHAR, "union")
xx(_FUNCTION, 11, 0, 0, 0, 0, "function")
xx(_ARRAY, 12, 0, 0, 0, 0, "array")
xx(_ENUM, 13, 0, 0, 0, _CHAR, "enum")
xx(_LONG, 14, 0, 0, 0, _CHAR, "long")
xx(_CONST, 15, 0, 0, 0, _CHAR, "const")
xx(_VOLATILE, 16, 0, 0, 0, _CHAR, "volatile")
yy(0, 17, 0, 0, 0, 0, 0)
yy(0, 18, 0, 0, 0, 0, 0)
yy(0, 19, 0, 0, 0, 0, 0)
yy(0, 20, 0, 0, 0, 0, 0)
yy(0, 21, 0, 0, 0, 0, 0)
yy(0, 22, 0, 0, 0, 0, 0)
yy(0, 23, 0, 0, 0, 0, 0)
yy(0, 24, 0, 0, 0, 0, 0)
yy(0, 25, 0, 0, 0, 0, 0)
yy(0, 26, 0, 0, 0, 0, 0)
yy(0, 27, 0, 0, 0, 0, 0)
yy(0, 28, 0, 0, 0, 0, "long long")
yy(0, 29, 0, 0, 0, 0, 0)
yy(0, 30, 0, 0, 0, 0, 0)
yy(0, 31, 0, 0, 0, 0, "const volatile")
xx(ID, 32, 0, 0, 0, ID, "identifier")
yy(0, 33, 0, 0, 0, ID, "!")
xx(FCON, 34, 0, 0, 0, ID, "floating constant")
xx(ICON, 35, 0, 0, 0, ID, "integer constant")
xx(SCON, 36, 0, 0, 0, ID, "string constant")
yy(0, 37, 13, MOD, bittree, '%', "%")
yy(0, 38, 8, BAND, bittree, ID, "&")
xx(INCR, 39, 0, ADD, addtree, ID, "++")
yy(0, 40, 0, 0, 0, ID, "(")
yy(0, 41, 0, 0, 0, ')', ")")
yy(0, 42, 13, MUL, multree, ID, "*")
yy(0, 43, 12, ADD, addtree, ID, "+")
yy(0, 44, 1, 0, 0, ',', ",")
yy(0, 45, 12, SUB, subtree, ID, "-")
yy(0, 46, 0, 0, 0, '.', ".")
yy(0, 47, 13, DIV, multree, '/', "/")
xx(DECR, 48, 0, SUB, subtree, ID, "--")
xx(DEREF, 49, 0, 0, 0, DEREF, "->")
xx(ANDAND, 50, 5, AND, andtree, ANDAND, "&&")
xx(OROR, 51, 4, OR, andtree, OROR, "||")
xx(LEQ, 52, 10, LE, cmptree, LEQ, "<=")
xx(EQL, 53, 9, EQ, eqtree, EQL, "==")
xx(NEQ, 54, 9, NE, eqtree, NEQ, "!=")
xx(GEQ, 55, 10, GE, cmptree, GEQ, ">=")
xx(RSHIFT, 56, 11, RSH, shtree, RSHIFT, ">>")
xx(LSHIFT, 57, 11, LSH, shtree, LSHIFT, "<<")
yy(0, 58, 0, 0, 0, ':', ":")
yy(0, 59, 0, 0, 0, IF, ";")
yy(0, 60, 10, LT, cmptree, '<', "<")
yy(0, 61, 2, ASGN, asgntree, '=', "=")
yy(0, 62, 10, GT, cmptree, '>', ">")
yy(0, 63, 0, 0, 0, '?', "?")
xx(ELLIPSIS, 64, 0, 0, 0, ELLIPSIS, "...")
xx(SIZEOF, 65, 0, 0, 0, ID, "sizeof")
yy(0, 66, 0, 0, 0, 0, 0)
xx(AUTO, 67, 0, 0, 0, STATIC, "auto")
xx(BREAK, 68, 0, 0, 0, IF, "break")
xx(CASE, 69, 0, 0, 0, IF, "case")
xx(CONTINUE, 70, 0, 0, 0, IF, "continue")
xx(DEFAULT, 71, 0, 0, 0, IF, "default")
xx(DO, 72, 0, 0, 0, IF, "do")
xx(ELSE, 73, 0, 0, 0, IF, "else")
xx(EXTERN, 74, 0, 0, 0, STATIC, "extern")
xx(FOR, 75, 0, 0, 0, IF, "for")
xx(GOTO, 76, 0, 0, 0, IF, "goto")
xx(IF, 77, 0, 0, 0, IF, "if")
xx(REGISTER, 78, 0, 0, 0, STATIC, "register")
xx(RETURN, 79, 0, 0, 0, IF, "return")
xx(SIGNED, 80, 0, 0, 0, _CHAR, "signed")
xx(STATIC, 81, 0, 0, 0, STATIC, "static")
xx(SWITCH, 82, 0, 0, 0, IF, "switch")
xx(TYPEDEF, 83, 0, 0, 0, STATIC, "typedef")
xx(WHILE, 84, 0, 0, 0, IF, "while")
xx(TYPECODE, 85, 0, 0, 0, ID, "__typecode")
xx(FIRSTARG, 86, 0, 0, 0, ID, "__firstarg")
yy(0, 87, 0, 0, 0, 0, 0)
yy(0, 88, 0, 0, 0, 0, 0)
yy(0, 89, 0, 0, 0, 0, 0)
yy(0, 90, 0, 0, 0, 0, 0)
yy(0, 91, 0, 0, 0, '[', "[")
yy(0, 92, 0, 0, 0, 0, 0)
yy(0, 93, 0, 0, 0, ']', "]")
yy(0, 94, 7, BXOR, bittree, '^', "^")
yy(0, 95, 0, 0, 0, 0, 0)
yy(0, 96, 0, 0, 0, 0, 0)
yy(0, 97, 0, 0, 0, 0, 0)
yy(0, 98, 0, 0, 0, 0, 0)
yy(0, 99, 0, 0, 0, 0, 0)
yy(0, 100, 0, 0, 0, 0, 0)
yy(0, 101, 0, 0, 0, 0, 0)
yy(0, 102, 0, 0, 0, 0, 0)
yy(0, 103, 0, 0, 0, 0, 0)
yy(0, 104, 0, 0, 0, 0, 0)
yy(0, 105, 0, 0, 0, 0, 0)
yy(0, 106, 0, 0, 0, 0, 0)
yy(0, 107, 0, 0, 0, 0, 0)
yy(0, 108, 0, 0, 0, 0, 0)
yy(0, 109, 0, 0, 0, 0, 0)
yy(0, 110, 0, 0, 0, 0, 0)
yy(0, 111, 0, 0, 0, 0, 0)
yy(0, 112, 0, 0, 0, 0, 0)
yy(0, 113, 0, 0, 0, 0, 0)
yy(0, 114, 0, 0, 0, 0, 0)
yy(0, 115, 0, 0, 0, 0, 0)
yy(0, 116, 0, 0, 0, 0, 0)
yy(0, 117, 0, 0, 0, 0, 0)
yy(0, 118, 0, 0, 0, 0, 0)
yy(0, 119, 0, 0, 0, 0, 0)
yy(0, 120, 0, 0, 0, 0, 0)
yy(0, 121, 0, 0, 0, 0, 0)
yy(0, 122, 0, 0, 0, 0, 0)
yy(0, 123, 0, 0, 0, IF, "{")
yy(0, 124, 6, BOR, bittree, '|', "|")
yy(0, 125, 0, 0, 0, '}', "}")
yy(0, 126, 0, BCOM, 0, ID, "~")
xx(EOI, 127, 0, 0, 0, EOI, "end of input")
#undef xx
#undef yy
};
/*143*/
Tree call(Tree f, Type fty, Coordinate src) {
	int n = 0;
	Tree args = NULL, r = NULL, e;
	Type* proto, rty = unqual(freturn(fty));
	Symbol t3 = NULL;

	if (fty->u.f.oldstyle)
		proto = NULL;
	else
		proto = fty->u.f.proto;
	if (hascall(f))
		r = f;
	if (isstruct(rty))
	{
		t3 = temporary(AUTO, unqual(rty));
		if (rty->size == 0)
			error("illegal use of incomplete type `%t'\n", rty);
	}
	if (t != ')')
		for (;;) {
			Tree q = pointer(expr1(0));
			if (proto && *proto && *proto != voidtype)
			{
				Type aty;
				q = value(q);
				aty = assign(*proto, q);
				if (aty)
					q = cast(q, aty);
				else
					error("type error in argument %d to %s; found `%t' expected `%t'\n", n + 1, funcname(f),

						q->type, *proto);
				if ((isint(q->type) || isenum(q->type))
					&& q->type->size != inttype->size)
					q = cast(q, promote(q->type));
				++proto;
			}
			else
			{
				if (!fty->u.f.oldstyle && *proto == NULL)
					error("too many arguments to %s\n", funcname(f));
				q = value(q);
				if (isarray(q->type) || q->type->size == 0)
					error("type error in argument %d to %s; `%t' is illegal\n", n + 1, funcname(f), q->type);

				else
					q = cast(q, promote(q->type));
			}
			if (!IR->wants_argb && isstruct(q->type))
				if (iscallb(q))
					q = addrof(q);
				else {
					Symbol t1 = temporary(AUTO, unqual(q->type));
					q = asgn(t1, q);
					q = tree(RIGHT, ptr(t1->type),
						root(q), lvalue(idtree(t1)));
				}
			if (q->type->size == 0)
				q->type = inttype;
			if (hascall(q))
				r = r ? tree(RIGHT, voidtype, r, q) : q;
			args = tree(mkop(ARG, q->type), q->type, q, args);
			n++;
			if (Aflag >= 2 && n == 32)
				warning("more than 31 arguments in a call to %s\n",
					funcname(f));
			if (t != ',')
				break;
			t = gettok();
		}
	expect(')');
	if (proto && *proto && *proto != voidtype)
		error("insufficient number of arguments to %s\n",
			funcname(f));
	if (r)
		args = tree(RIGHT, voidtype, r, args);
	e = calltree(f, rty, args, t3);
	if (events.calls)
		apply(events.calls, &src, &e);
	return e;
}
/*145*/
Tree calltree(Tree f, Type ty, Tree args, Symbol t3) {
	Tree p;

	if (args)
		f = tree(RIGHT, f->type, args, f);
	if (isstruct(ty))
		assert(t3),
		p = tree(RIGHT, ty,
			tree(CALL + B, ty, f, addrof(idtree(t3))),
			idtree(t3));
	else {
		Type rty = ty;
		if (isenum(ty))
			rty = unqual(ty)->type;
		if (!isfloat(rty))
			rty = promote(rty);
		p = tree(mkop(CALL, rty), rty, f, NULL);
		if (isptr(ty) || p->type->size > ty->size)
			p = cast(p, ty);
	}
	return p;
}
Tree vcall(Symbol func, Type ty, ...) {
	va_list ap;
	Tree args = NULL, e, f = pointer(idtree(func)), r = NULL;

	assert(isfunc(func->type));
	if (ty == NULL)
		ty = freturn(func->type);
	va_start(ap, ty);
	while ((e = va_arg(ap, Tree)) != NULL) {
		if (hascall(e))
			r = r == NULL ? e : tree(RIGHT, voidtype, r, e);
		args = tree(mkop(ARG, e->type), e->type, e, args);
	}
	va_end(ap);
	if (r != NULL)
		args = tree(RIGHT, voidtype, r, args);
	return calltree(f, ty, args, NULL);
}
/*147*/
int iscallb(Tree e) {
	return e->op == RIGHT && e->kids[0] && e->kids[1]
		&& e->kids[0]->op == CALL + B
		&& e->kids[1]->op == INDIR + B
		&& isaddrop(e->kids[1]->kids[0]->op)
		&& e->kids[1]->kids[0]->u.sym->temporary;
}
/*147,148*/
static Tree addtree(int op, Tree l, Tree r) {
	Type ty = inttype;

	if (isarith(l->type) && isarith(r->type)) {
		ty = binary(l->type, r->type);
		l = cast(l, ty);
		r = cast(r, ty);
	}
	else if (isptr(l->type) && isint(r->type))
		return addtree(ADD, r, l);
	else if (isptr(r->type) && isint(l->type)
		&& !isfunc(r->type->type))
	{
		long n;
		ty = unqual(r->type);
		n = unqual(ty->type)->size;
		if (n == 0)
			error("unknown size for type `%t'\n", ty->type);
		l = cast(l, promote(l->type));
		if (n > 1)
			l = multree(MUL, cnsttree(signedptr, n), l);
		if (isunsigned(l->type))
			l = cast(l, unsignedptr);
		else
			l = cast(l, signedptr);
		if (YYcheck && !isaddrop(r->op))		/* omit */
			return nullcall(ty, YYcheck, r, l);	/* omit */
		return simplify(ADD, ty, l, r);
	}

	else
		typeerror(op, l, r);
	return simplify(op, ty, l, r);
}

Tree cnsttree(Type ty, ...) {
	Tree p = tree(mkop(CNST, ty), ty, NULL, NULL);
	va_list ap;

	va_start(ap, ty);
	/*修改支持64位,2022.02.24*/
	switch (ty->op) {
	case _INT:     
		p->u.v.i = va_arg(ap, long long);
		if (ty->size == 1)
			p->u.v.i = (long long)(char)p->u.v.i;
		else if (ty->size == 2)
			p->u.v.i = (long long)(short)p->u.v.i;
		else if (ty->size == 4)
			p->u.v.i = (long long)(long)p->u.v.i;
		break;
	case _UNSIGNED:p->u.v.u = va_arg(ap, unsigned long long) & ones(8 * ty->size); break;
	case _FLOAT:   p->u.v.d = va_arg(ap, long double); break;
	case _POINTER: p->u.v.p = va_arg(ap, void*); break;
	default: assert(0);
	}
	/*
	switch (ty->op) {
	case _INT:     p->u.v.i = va_arg(ap, long); break;
	case _UNSIGNED:p->u.v.u = va_arg(ap, unsigned long) & ones(8 * ty->size); break;
	case _FLOAT:   p->u.v.d = va_arg(ap, long double); break;
	case _POINTER: p->u.v.p = va_arg(ap, void*); break;
	default: assert(0);
	}
	*/
	va_end(ap);
	return p;
}
/*149*/
Tree consttree(int n, Type ty) {
	if (isarray(ty))
		ty = atop(ty);
	else assert(isint(ty));
	return cnsttree(ty, (long)n);
}
/*147*/
static Tree cmptree(int op, Tree l, Tree r) {
	Type ty;

	if (isarith(l->type) && isarith(r->type)) {
		ty = binary(l->type, r->type);
		l = cast(l, ty);
		r = cast(r, ty);
	}
	else if (compatible(l->type, r->type)) {
		ty = unsignedptr;
		l = cast(l, ty);
		r = cast(r, ty);
	}
	else {
		ty = unsignedtype;
		typeerror(op, l, r);
	}
	return simplify(mkop(op, ty), inttype, l, r);
}
/*149*/
static int compatible(Type ty1, Type ty2) {
	ty1 = unqual(ty1);
	ty2 = unqual(ty2);
	return isptr(ty1) && !isfunc(ty1->type)
		&& isptr(ty2) && !isfunc(ty2->type)
		&& eqtype(unqual(ty1->type), unqual(ty2->type), 0);
}
/*149*/
static int isnullptr(Tree e) {
	Type ty = unqual(e->type);

	return generic(e->op) == CNST
		&& (ty->op == _INT && e->u.v.i == 0
			|| ty->op == _UNSIGNED && e->u.v.u == 0
			|| isvoidptr(ty) && e->u.v.p == NULL);
}
/*147,150*/
Tree eqtree(int op, Tree l, Tree r) {
	Type xty = unqual(l->type), yty = unqual(r->type);

	if (isptr(xty) && isnullptr(r)
		|| isptr(xty) && !isfunc(xty->type) && isvoidptr(yty)
		|| (isptr(xty) && isptr(yty)
			&& eqtype(unqual(xty->type), unqual(yty->type), 1))) {
		Type ty = unsignedptr;
		l = cast(l, ty);
		r = cast(r, ty);
		return simplify(mkop(op, ty), inttype, l, r);
	}
	if (isptr(yty) && isnullptr(l)
		|| isptr(yty) && !isfunc(yty->type) && isvoidptr(xty))
		return eqtree(op, r, l);
	return cmptree(op, l, r);
}
/*145,150*/
Type assign(Type xty, Tree e) {
	Type yty = unqual(e->type);

	xty = unqual(xty);
	if (isenum(xty))
		xty = xty->type;
	if (xty->size == 0 || yty->size == 0)
		return NULL;
	if (isarith(xty) && isarith(yty)
		|| isstruct(xty) && xty == yty)
		return xty;
	if (isptr(xty) && isnullptr(e))
		return xty;
	if ((isvoidptr(xty) && isptr(yty)
		|| isptr(xty) && isvoidptr(yty))
		&& ((isconst(xty->type) || !isconst(yty->type))
			&& (isvolatile(xty->type) || !isvolatile(yty->type))))
		return xty;

	if ((isptr(xty) && isptr(yty)
		&& eqtype(unqual(xty->type), unqual(yty->type), 1))
		&& ((isconst(xty->type) || !isconst(yty->type))
			&& (isvolatile(xty->type) || !isvolatile(yty->type))))
		return xty;
	if (isptr(xty) && isptr(yty)
		&& ((isconst(xty->type) || !isconst(yty->type))
			&& (isvolatile(xty->type) || !isvolatile(yty->type)))) {
		Type lty = unqual(xty->type), rty = unqual(yty->type);
		if (isenum(lty) && rty == inttype
			|| isenum(rty) && lty == inttype) {
			if (Aflag >= 1)
				warning("assignment between `%t' and `%t' is compiler-dependent\n",
					xty, yty);
			return xty;
		}
	}
	return NULL;
}
/*147,152*/
Tree asgntree(int op, Tree l, Tree r) {
	Type aty, ty;

	r = pointer(r);
	ty = assign(l->type, r);
	if (ty)
		r = cast(r, ty);
	else {
		typeerror(ASGN, l, r);
		if (r->type == voidtype)
			r = retype(r, inttype);
		ty = r->type;
	}
	if (l->op != FIELD)
		l = lvalue(l);
	aty = l->type;
	if (isptr(aty))
		aty = unqual(aty)->type;
	if (isconst(aty)
		|| isstruct(aty) && unqual(aty)->u.sym->u.s.cfields)
		if (isaddrop(l->op)
			&& !l->u.sym->computed && !l->u.sym->generated)
			error("assignment to const identifier `%s'\n",
				l->u.sym->name);
		else
			error("assignment to const location\n");
	if (l->op == FIELD) {
		long n = 8 * l->u.field->type->size - fieldsize(l->u.field);
		if (n > 0 && isunsigned(l->u.field->type))
			r = bittree(BAND, r,
				cnsttree(r->type, (unsigned long)fieldmask(l->u.field)));
		else if (n > 0) {
			if (r->op == CNST + _I) {
				n = r->u.v.i;
				if (n & (1 << (fieldsize(l->u.field) - 1)))
					n |= ~0UL << fieldsize(l->u.field);
				r = cnsttree(r->type, n);
			}
			else
				r = shtree(RSH,
					shtree(LSH, r, cnsttree(inttype, n)),
					cnsttree(inttype, n));
		}
	}
	if (isstruct(ty) && isaddrop(l->op) && iscallb(r))
		return tree(RIGHT, ty,
			tree(CALL + B, ty, r->kids[0]->kids[0], l),
			idtree(l->u.sym));
	return tree(mkop(op, ty), ty, l, r);
}
/*147*/
Tree condtree(Tree e, Tree l, Tree r) {
	Symbol t1;
	Type ty, xty = l->type, yty = r->type;
	Tree p;

	if (isarith(xty) && isarith(yty))
		ty = binary(xty, yty);
	else if (eqtype(xty, yty, 1))
		ty = unqual(xty);
	else if (isptr(xty) && isnullptr(r))
		ty = xty;
	else if (isnullptr(l) && isptr(yty))
		ty = yty;
	else if (isptr(xty) && !isfunc(xty->type) && isvoidptr(yty)
		|| isptr(yty) && !isfunc(yty->type) && isvoidptr(xty))
		ty = voidptype;
	else if ((isptr(xty) && isptr(yty)
		&& eqtype(unqual(xty->type), unqual(yty->type), 1)))
		ty = xty;
	else {
		typeerror(COND, l, r);
		return consttree(0, inttype);
	}
	if (isptr(ty)) {
		ty = unqual(unqual(ty)->type);
		if (isptr(xty) && isconst(unqual(xty)->type)
			|| isptr(yty) && isconst(unqual(yty)->type))
			ty = qual(_CONST, ty);
		if (isptr(xty) && isvolatile(unqual(xty)->type)
			|| isptr(yty) && isvolatile(unqual(yty)->type))
			ty = qual(_VOLATILE, ty);
		ty = ptr(ty);
	}
	switch (e->op) {
	case CNST + _I: return cast(e->u.v.i != 0 ? l : r, ty);
	case CNST + U: return cast(e->u.v.u != 0 ? l : r, ty);
	case CNST + P: return cast(e->u.v.p != 0 ? l : r, ty);
	case CNST + F: return cast(e->u.v.d != 0.0 ? l : r, ty);
	}
	if (ty != voidtype && ty->size > 0) {
		t1 = genident(REGISTER, unqual(ty), level);
		/*	t1 = temporary(REGISTER, unqual(ty)); */
		l = asgn(t1, l);
		r = asgn(t1, r);
	}
	else
		t1 = NULL;
	p = tree(COND, ty, cond(e),
		tree(RIGHT, ty, root(l), root(r)));
	p->u.sym = t1;
	return p;
}
/*146*/
/* addrof - address of p */
Tree addrof(Tree p) {
	Tree q = p;

	for (;;)
		switch (generic(q->op)) {
		case RIGHT:
			assert(q->kids[0] || q->kids[1]);
			q = q->kids[1] ? q->kids[1] : q->kids[0];
			continue;
		case ASGN:
			q = q->kids[1];
			continue;
		case COND: {
			Symbol t1 = q->u.sym;
			q->u.sym = 0;
			q = idtree(t1);
			/* fall thru */
		}
		case INDIR:
			if (p == q)
				return q->kids[0];
			q = q->kids[0];
			return tree(RIGHT, q->type, root(p), q);
		default:
			error("addressable object required\n");
			return value(p);
		}
}
/*147*/
/* andtree - construct tree for l [&& ||] r */
static Tree andtree(int op, Tree l, Tree r) {
	if (!isscalar(l->type) || !isscalar(r->type))
		typeerror(op, l, r);
	return simplify(op, inttype, cond(l), cond(r));
}
/*147*/
/* asgn - generate tree for assignment of expr e to symbol p sans qualifiers */
Tree asgn(Symbol p, Tree e) {
	if (isarray(p->type))
		e = tree(ASGN + B, p->type, idtree(p),
			tree(INDIR + B, e->type, e, NULL));
	else {
		Type ty = p->type;
		p->type = unqual(p->type);
		if (isstruct(p->type) && p->type->u.sym->u.s.cfields) {
			p->type->u.sym->u.s.cfields = 0;
			e = asgntree(ASGN, idtree(p), e);
			p->type->u.sym->u.s.cfields = 1;
		}
		else
			e = asgntree(ASGN, idtree(p), e);
		p->type = ty;
	}
	return e;
}
/*147*/
/* bittree - construct tree for l [& | ^ %] r */
Tree bittree(int op, Tree l, Tree r) {
	Type ty = inttype;

	if (isint(l->type) && isint(r->type)) {
		ty = binary(l->type, r->type);
		l = cast(l, ty);
		r = cast(r, ty);
	}
	else
		typeerror(op, l, r);
	return simplify(op, ty, l, r);
}
/*147*/
/* multree - construct tree for l [* /] r */
static Tree multree(int op, Tree l, Tree r) {
	Type ty = inttype;

	if (isarith(l->type) && isarith(r->type)) {
		ty = binary(l->type, r->type);
		l = cast(l, ty);
		r = cast(r, ty);
	}
	else
		typeerror(op, l, r);
	return simplify(op, ty, l, r);
}
/*147*/
/* shtree - construct tree for l [>> <<] r */
Tree shtree(int op, Tree l, Tree r) {
	Type ty = inttype;

	if (isint(l->type) && isint(r->type)) {
		ty = promote(l->type);
		l = cast(l, ty);
		r = cast(r, inttype);
	}
	else
		typeerror(op, l, r);
	return simplify(op, ty, l, r);
}
/*147*/
/* subtree - construct tree for l - r */
static Tree subtree(int op, Tree l, Tree r) {
	long n;
	Type ty = inttype;

	if (isarith(l->type) && isarith(r->type)) {
		ty = binary(l->type, r->type);
		l = cast(l, ty);
		r = cast(r, ty);
	}
	else if (isptr(l->type) && !isfunc(l->type->type) && isint(r->type)) {
		ty = unqual(l->type);
		n = unqual(ty->type)->size;
		if (n == 0)
			error("unknown size for type `%t'\n", ty->type);
		r = cast(r, promote(r->type));
		if (n > 1)
			r = multree(MUL, cnsttree(signedptr, n), r);
		if (isunsigned(r->type))
			r = cast(r, unsignedptr);
		else
			r = cast(r, signedptr);
		return simplify(SUB + P, ty, l, r);
	}
	else if (compatible(l->type, r->type)) {
		ty = unqual(l->type);
		n = unqual(ty->type)->size;
		if (n == 0)
			error("unknown size for type `%t'\n", ty->type);
		l = simplify(SUB + U, unsignedptr,
			cast(l, unsignedptr), cast(r, unsignedptr));
		return simplify(DIV + _I, longtype,
			cast(l, longtype), cnsttree(longtype, n));
	}
	else
		typeerror(op, l, r);
	return simplify(op, ty, l, r);
}

/*137*/
/* typeerror - issue "operands of op have illegal types `l' and `r'" */
void typeerror(int op, Tree l, Tree r) {
	int i;
	static struct { int op; char* name; } ops[] = {
		ASGN, "=",	INDIR, "*",	NEG,  "-",
		ADD,  "+",	SUB,   "-",	LSH,  "<<",
		MOD,  "%",	RSH,   ">>",	BAND, "&",
		BCOM, "~",	BOR,   "|",	BXOR, "^",
		DIV,  "/",	MUL,   "*",	EQ,   "==",
		GE,   ">=",	GT,    ">",	LE,   "<=",
		LT,   "<",	NE,    "!=",	AND,  "&&",
		NOT,  "!",	OR,    "||",	COND, "?:",
		0, 0
	};

	op = generic(op);
	for (i = 0; ops[i].op; i++)
		if (op == ops[i].op)
			break;
	assert(ops[i].name);
	if (r)
		error("operands of %s have illegal types `%t' and `%t'\n",
			ops[i].name, l->type, r->type);
	else
		error("operand of unary %s has illegal type `%t'\n", ops[i].name,
			l->type);
}
