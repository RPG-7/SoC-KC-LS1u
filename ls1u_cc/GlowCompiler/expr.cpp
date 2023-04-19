#include "c.h"

static char rcsid[] = "$Id$";

static char prec[] = {
#define xx(a,b,c,d,e,f,g) c,
#define yy(a,b,c,d,e,f,g) c,
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
static int oper[] = {
#define xx(a,b,c,d,e,f,g) d,
#define yy(a,b,c,d,e,f,g) d,
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
float refinc = 1.0;
static Tree expr2(void);
static Tree expr3(int);
static Tree nullcheck(Tree);
static Tree postfix(Tree);
static Tree unary(void);
static Tree primary(void);
static Type super(Type ty);

void expr_init(void)
{
	refinc = 1.0;
}
/*返回父类型,134*/
static Type super(Type ty) {
	switch (ty->op) {
	case _INT:
		//if (ty->size < inttype->size) 修改
		//	return inttype;
		break;
	case _UNSIGNED:
		//if (ty->size < unsignedtype->size) 修改
		//	return unsignedtype;
		break;
	case _POINTER:
		return unsignedptr;
	}
	return ty;
}
Tree expr(int tok) {
	static char stop[] = { IF, ID, '}', 0 };
	Tree p = expr1(0);

	while (t == ',') {
		Tree q;
		t = gettok();
		q = pointer(expr1(0));
		p = tree(RIGHT, q->type, root(value(p)), q);
	}
	if (tok)
		test(tok, stop);
	return p;
}
Tree expr0(int tok) {
	return root(expr(tok));
}
Tree expr1(int tok) {
	static char stop[] = { IF, ID, 0 };
	Tree p = expr2();

	if (t == '='
		|| (prec[t] >= 6 && prec[t] <= 8)
		|| (prec[t] >= 11 && prec[t] <= 13)) {
		int op = t;
		t = gettok();
		if (oper[op] == ASGN)
			p = asgntree(ASGN, p, value(expr1(0)));
		else
		{
			expect('=');
			p = incr(op, p, expr1(0));
		}
	}
	if (tok)
		test(tok, stop);
	return p;
}
/*处理类似a+=b的表达式,120,147*/
Tree incr(int op, Tree v, Tree e) {
	return asgntree(ASGN, v, (*optree[op])(oper[op], v, e));
}
static Tree expr2(void) {
	Tree p = expr3(4);

	if (t == '?') {
		Tree l, r;
		Coordinate pts[2];
		if (Aflag > 1 && isfunc(p->type))
			warning("%s used in a conditional expression\n",
				funcname(p));
		p = pointer(p);
		t = gettok();
		pts[0] = src;
		l = pointer(expr(':'));
		pts[1] = src;
		r = pointer(expr2());
		if (generic(p->op) != CNST && events.points)
		{
			apply(events.points, &pts[0], &l);
			apply(events.points, &pts[1], &r);
		}
		p = condtree(p, l, r);
	}
	return p;
}
/*133*/
Tree value(Tree p) {
	int op = generic(rightkid(p)->op);

	if (p->type != voidtype
		&& (op == AND || op == OR || op == NOT || op == EQ || op == NE
			|| op == LE || op == LT || op == GE || op == GT))
		p = condtree(p, consttree(1, inttype),
			consttree(0, inttype));
	return p;
}
static Tree expr3(int k) {
	int k1;
	Tree p = unary();

	for (k1 = prec[t]; k1 >= k; k1--)
		while (prec[t] == k1 && *cp != '=') {
			Tree r;
			Coordinate pt;
			int op = t;
			t = gettok();
			pt = src;
			p = pointer(p);
			if (op == ANDAND || op == OROR) {
				r = pointer(expr3(k1));
				if (events.points)
					apply(events.points, &pt, &r);
			}
			else
				r = pointer(expr3(k1 + 1));
			p = (*optree[op])(oper[op], p, r);
		}
	return p;
}
/*处理一元表达式*/
static Tree unary(void) {
	Tree p;

	switch (t) {
	case '*':    t = gettok(); p = unary(); p = pointer(p);
		if (isptr(p->type)
			&& (isfunc(p->type->type) || isarray(p->type->type)))
			p = retype(p, p->type->type);
		else {
			if (YYnull)
				p = nullcheck(p);
			p = rvalue(p);
		} break;
	case '&':    t = gettok(); p = unary(); if (isarray(p->type) || isfunc(p->type))
		p = retype(p, ptr(p->type));
			else
		p = lvalue(p);
		if (isaddrop(p->op) && p->u.sym->sclass == REGISTER)
			error("invalid operand of unary &; `%s' is declared register\n", p->u.sym->name);

		else if (isaddrop(p->op))
			p->u.sym->addressed = 1;
		break;
	case '+':    t = gettok(); p = unary(); p = pointer(p);
		if (isarith(p->type))
			p = cast(p, promote(p->type));
		else
			typeerror(ADD, p, NULL);  break;
	case '-':    t = gettok(); p = unary(); p = pointer(p);
		if (isarith(p->type)) {
			Type ty = promote(p->type);
			p = cast(p, ty);
			if (isunsigned(ty)) {
				warning("unsigned operand of unary -\n");
				p = simplify(ADD, ty, simplify(BCOM, ty, p, NULL), cnsttree(ty, 1ULL)); //修改支持64位,2022.2.25
				//p = simplify(ADD, ty, simplify(BCOM, ty, p, NULL), cnsttree(ty, 1UL));
			}
			else
				p = simplify(NEG, ty, p, NULL);
		}
		else
			typeerror(SUB, p, NULL); break;
	case '~':    t = gettok(); p = unary(); p = pointer(p);
		if (isint(p->type)) {
			Type ty = promote(p->type);
			p = simplify(BCOM, ty, cast(p, ty), NULL);
		}
		else
			typeerror(BCOM, p, NULL);  break;
	case '!':    t = gettok(); p = unary(); p = pointer(p);
		if (isscalar(p->type))
			p = simplify(NOT, inttype, cond(p), NULL);
		else
			typeerror(NOT, p, NULL); break;
	//case INCR:   t = gettok(); p = unary(); p = incr(INCR, pointer(p), consttree(1, inttype)); break;
	//case DECR:   t = gettok(); p = unary(); p = incr(DECR, pointer(p), consttree(1, inttype)); break;
	case INCR:   t = gettok(); p = unary(); p = incr(INCR, pointer(p), consttree(1, chartype)); break; //修改
	case DECR:   t = gettok(); p = unary(); p = incr(DECR, pointer(p), consttree(1, chartype)); break; //修改
	case TYPECODE: case SIZEOF: { int op = t;
		Type ty;
		p = NULL;
		t = gettok();
		if (t == '(') {
			t = gettok();
			if (istypename(t, tsym)) {
				ty = _typename();
				expect(')');
			}
			else {
				p = postfix(expr(')'));
				ty = p->type;
			}
		}
		else {
			p = unary();
			ty = p->type;
		}
		assert(ty);
		if (op == TYPECODE)
			p = cnsttree(inttype, (long)ty->op);
		else {
			if (isfunc(ty) || ty->size == 0)
				error("invalid type argument `%t' to `sizeof'\n", ty);
			else if (p && rightkid(p)->op == FIELD)
				error("`sizeof' applied to a bit field\n");
			p = cnsttree(unsignedlong, (unsigned long)ty->size);
		} } break;
	case '(':
		t = gettok();
		if (istypename(t, tsym)) {
			Type ty, ty1 = _typename(), pty;
			expect(')');
			ty = unqual(ty1);
			if (isenum(ty)) {
				Type ty2 = ty->type;
				if (isconst(ty1))
					ty2 = qual(_CONST, ty2);
				if (isvolatile(ty1))
					ty2 = qual(_VOLATILE, ty2);
				ty1 = ty2;
				ty = ty->type;
			}
			p = pointer(unary());
			pty = p->type;
			if (isenum(pty))
				pty = pty->type;
			if (isarith(pty) && isarith(ty)
				|| isptr(pty) && isptr(ty)) {
				explicitCast++;
				p = cast(p, ty);
				explicitCast--;
			}
			else if (isptr(pty) && isint(ty)
				|| isint(pty) && isptr(ty)) {
				if (Aflag >= 1 && ty->size < pty->size)
					warning("conversion from `%t' to `%t' is compiler dependent\n", p->type, ty);

				p = cast(p, ty);
			}
			else if (ty != voidtype) {
				error("cast from `%t' to `%t' is illegal\n",
					p->type, ty1);
				ty1 = inttype;
			}
			if (generic(p->op) == INDIR || ty->size == 0)
				p = tree(RIGHT, ty1, NULL, p);
			else
				p = retype(p, ty1);
		}
		else
			p = postfix(expr(')'));
		break;
	default:
		p = postfix(primary());
	}
	return p;
}
/*143*/
static Tree postfix(Tree p) {
	for (;;)
		switch (t) {
		case INCR:  p = tree(RIGHT, p->type,
			tree(RIGHT, p->type,
				p,
				incr(t, p, consttree(1, inttype))),
			p);
			t = gettok(); break;
		case DECR:  p = tree(RIGHT, p->type,
			tree(RIGHT, p->type,
				p,
				incr(t, p, consttree(1, inttype))),
			p);
			t = gettok(); break;
		case '[': {
			Tree q;
			t = gettok();
			q = expr(']');
			if (YYnull)
				if (isptr(p->type))
					p = nullcheck(p);
				else if (isptr(q->type))
					q = nullcheck(q);
			p = (*optree['+'])(ADD, pointer(p), pointer(q));
			if (isptr(p->type) && isarray(p->type->type))
				p = retype(p, p->type->type);
			else
				p = rvalue(p);
		} break;
		case '(': {
			Type ty;
			Coordinate pt;

			p = pointer(p);
			if (isptr(p->type) && isfunc(p->type->type))
				ty = p->type->type;
			else {
				error("found `%t' expected a function\n", p->type);
				ty = func(voidtype, NULL, 1);
				p = retype(p, ptr(ty));
			}
			pt = src;
			t = gettok();
			p = call(p, ty, pt);
		} break;
		case '.':   t = gettok();
			if (t == ID) {
				if (isstruct(p->type)) {
					Tree q = addrof(p);
					p = field(q, token);
					q = rightkid(q);
					if (isaddrop(q->op) && q->u.sym->temporary)
						p = tree(RIGHT, p->type, p, NULL);
				}
				else
					error("left operand of . has incompatible type `%t'\n",
						p->type);
				t = gettok();
			}
			else
				error("field name expected\n"); break;
		case DEREF: t = gettok();
			p = pointer(p);
			if (t == ID) {
				if (isptr(p->type) && isstruct(p->type->type)) {
					if (YYnull)
						p = nullcheck(p);
					p = field(p, token);
				}
				else
					error("left operand of -> has incompatible type `%t'\n", p->type);

				t = gettok();
			}
			else
				error("field name expected\n"); break;
		default:
			return p;
		}
}
static Tree primary(void) {
	Tree p;

	assert(t != '(');
	switch (t) {
	case ICON:
	case FCON: p = tree(mkop(CNST, tsym->type), tsym->type, NULL, NULL);
		p->u.v = tsym->u.c.v;
		break;
	case SCON: if (ischar(tsym->type->type))
		tsym->u.c.v.p = stringn((char*)tsym->u.c.v.p, tsym->type->size);
			 else
		tsym->u.c.v.p = memcpy(allocate((tsym->type->size / widechar->size) * sizeof(int), PERM),
			tsym->u.c.v.p, (tsym->type->size / widechar->size) * sizeof(int));
		tsym = constant(tsym->type, tsym->u.c.v);
		if (tsym->u.c.loc == NULL)
			tsym->u.c.loc = genident(STATIC, tsym->type, GLOBAL);
		p = idtree(tsym->u.c.loc); break;
	case ID:   if (tsym == NULL)
	{
		Symbol p = install(token, &identifiers, level, PERM);
		p->src = src;
		if (getchr() == '(') {
			Symbol q = lookup(token, externals);
			p->type = func(inttype, NULL, 1);
			p->sclass = EXTERN;
			if (Aflag >= 1)
				warning("missing prototype\n");
			if (q && !eqtype(q->type, p->type, 1))
				warning("implicit declaration of `%s' does not match previous declaration at %w\n", q->name, &q->src);

			if (q == NULL) {
				q = install(p->name, &externals, GLOBAL, PERM);
				q->type = p->type;
				q->sclass = EXTERN;
				q->src = src;
				(*IR->_defsymbol)(q);
			}
			p->u.alias = q;
		}
		else {
			error("undeclared identifier `%s'\n", p->name);
			p->sclass = AUTO;
			p->type = inttype;
			if (p->scope == GLOBAL)
				(*IR->_defsymbol)(p);
			else
				addlocal(p);
		}
		t = gettok();
		if (xref)
			use(p, src);
		return idtree(p);
	}
		   if (xref)
			   use(tsym, src);
		   if (tsym->sclass == _ENUM)
			   p = consttree(tsym->u.value, inttype);
		   else {
			   if (tsym->sclass == TYPEDEF)
				   error("illegal use of type name `%s'\n", tsym->name);
			   p = idtree(tsym);
		   } break;
	case FIRSTARG:
		if (level > PARAM && cfunc && cfunc->u.f.callee[0])
			p = idtree(cfunc->u.f.callee[0]);
		else {
			error("illegal use of `%k'\n", FIRSTARG);
			p = cnsttree(inttype, 0L);
		}
		break;
	default:
		error("illegal expression\n");
		p = cnsttree(inttype, 0L);
	}
	t = gettok();
	return p;
}
Tree idtree(Symbol p) {
	int op;
	Tree e;
	Type ty = p->type ? unqual(p->type) : voidptype;

	if (p->scope == GLOBAL || p->sclass == STATIC)
		op = ADDRG;
	else if (p->scope == PARAM) {
		op = ADDRF;
		if (isstruct(p->type) && !IR->wants_argb)
		{
			e = tree(mkop(op, voidptype), ptr(ptr(p->type)), NULL, NULL);
			e->u.sym = p;
			return rvalue(rvalue(e));
		}
	}
	else if (p->sclass == EXTERN) {
		assert(p->u.alias);
		p = p->u.alias;
		op = ADDRG;
	}
	else
		op = ADDRL;
	p->ref += refinc;
	if (isarray(ty))
		e = tree(mkop(op, voidptype), p->type, NULL, NULL);
	else if (isfunc(ty))
		e = tree(mkop(op, funcptype), p->type, NULL, NULL);
	else
		e = tree(mkop(op, voidptype), ptr(p->type), NULL, NULL);
	e->u.sym = p;
	if (isptr(e->type))
		e = rvalue(e);
	return e;
}
/*133*/
Tree rvalue(Tree p) {
	Type ty = deref(p->type);

	ty = unqual(ty);
	return tree(mkop(INDIR, ty), ty, p, NULL);
}
/*133*/
Tree lvalue(Tree p) {
	if (generic(p->op) != INDIR) {
		error("lvalue required\n");
		return value(p);
	}
	else if (unqual(p->type) == voidtype)
		warning("`%t' used as an lvalue\n", p->type);
	return p->kids[0];
}
Tree retype(Tree p, Type ty) {
	Tree q;

	if (p->type == ty)
		return p;
	q = tree(p->op, ty, p->kids[0], p->kids[1]);
	q->node = p->node;
	q->u = p->u;
	return q;
}
Tree rightkid(Tree p) {
	while (p && p->op == RIGHT)
		if (p->kids[1])
			p = p->kids[1];
		else if (p->kids[0])
			p = p->kids[0];
		else
			assert(0);
	assert(p);
	return p;
}
int hascall(Tree p) {
	if (p == 0)
		return 0;
	if (generic(p->op) == CALL || (IR->mulops_calls &&
		(p->op == DIV + _I || p->op == MOD + _I || p->op == MUL + _I
			|| p->op == DIV + U || p->op == MOD + U || p->op == MUL + U)))
		return 1;
	return hascall(p->kids[0]) || hascall(p->kids[1]);
}

/*常规算术转换,132*/
Type binary(Type xty, Type yty) {
#define xx(t) if (xty == t || yty == t) return t
	xx(longdouble);
	xx(doubletype);
	xx(floattype);
	xx(unsignedlonglong);
	xx(longlong);
	xx(unsignedlong);
	if (xty == longtype && yty == unsignedtype
		|| xty == unsignedtype && yty == longtype)
		if (longtype->size > unsignedtype->size)
			return longtype;
		else
			return unsignedlong;
	xx(longtype);
	xx(unsignedtype);
	xx(inttype);		//修改,增加此行
	xx(unsignedshort);	//修改,增加此行
	xx(shorttype);		//修改,增加此行
	xx(unsignedchar);	//修改,增加此行
	xx(signedchar);		//修改,增加此行
	xx(chartype);		//修改,增加此行
	return inttype;
#undef xx
}
/*处理第二类隐式转换,133*/
Tree pointer(Tree p) {
	if (isarray(p->type))
		/* assert(p->op != RIGHT || p->u.sym == NULL), */
		p = retype(p, atop(p->type));
	else if (isfunc(p->type))
		p = retype(p, ptr(p->type));
	return p;
}
/*将表示某个值的树添加与零比较操作,转换为表示条件的树,133*/
Tree cond(Tree p) {
	int op = generic(rightkid(p)->op);

	if (op == AND || op == OR || op == NOT
		|| op == EQ || op == NE
		|| op == LE || op == LT || op == GE || op == GT)
		return p;
	p = pointer(p);
	return (*optree[NEQ])(NE, p, consttree(0, inttype));
}
/*类型转换，134*/
Tree cast(Tree p, Type type) {
	Type src, dst;

	p = value(p);
	if (p->type == type)
		return p;
	dst = unqual(type);
	src = unqual(p->type);
	if (src->op != dst->op || src->size != dst->size) {
		switch (src->op) {
		case _INT:
			//if (src->size < inttype->size)
			//	p = simplify(CVI, inttype, p, NULL); 修改
			break;
		case _UNSIGNED:
			//if (src->size < inttype->size)
			//	p = simplify(CVU, inttype, p, NULL);
			//else if (src->size < unsignedtype->size)
			//	p = simplify(CVU, unsignedtype, p, NULL);  修改
			break;
		case _ENUM:
			p = retype(p, inttype);
			break;
		case _POINTER:
			if (isint(dst) && src->size > dst->size)
				warning("conversion from `%t' to `%t' is undefined\n", p->type, type);
			p = simplify(CVP, super(src), p, NULL);
			break;
		case _FLOAT:
			break;
		default: assert(0);
		}
		{
			src = unqual(p->type);
			dst = super(dst);
			if (src->op != dst->op)
				switch (src->op) {
				case _INT:
					p = simplify(CVI, dst, p, NULL);
					break;
				case _UNSIGNED:
					if (isfloat(dst)) {
						Type ssrc = signedint(src);
						Tree two = cnsttree(longdouble, (long double)2.0);
						p = (*optree['+'])(ADD,
							(*optree['*'])(MUL,
								two,
								simplify(CVU, ssrc,
									simplify(RSH, src,
										p, consttree(1, inttype)), NULL)),
							simplify(CVU, ssrc,
								simplify(BAND, src,
									p, consttree(1, unsignedtype)), NULL));
					}
					else
						p = simplify(CVU, dst, p, NULL);
					break;
				case _FLOAT:
					if (isunsigned(dst)) {
						Type sdst = signedint(dst);
						Tree c = cast(cnsttree(longdouble, (long double)sdst->u.sym->u.limits.max.i + 1), src);
						p = condtree(
							simplify(GE, src, p, c),
							(*optree['+'])(ADD,
								cast(cast(simplify(SUB, src, p, c), sdst), dst),
								cast(cnsttree(unsignedlong, (unsigned long)sdst->u.sym->u.limits.max.i + 1), dst)),
							simplify(CVF, sdst, p, NULL));
					}
					else
						p = simplify(CVF, dst, p, NULL);
					break;
				default: assert(0);
				}
			dst = unqual(type);
		}
	}
	src = unqual(p->type);
	switch (src->op) {
	case _INT:
		if (src->op != dst->op || src->size != dst->size)
			p = simplify(CVI, dst, p, NULL);
		break;
	case _UNSIGNED:
		if (src->op != dst->op || src->size != dst->size)
			p = simplify(CVU, dst, p, NULL);
		break;
	case _FLOAT:
		if (src->op != dst->op || src->size != dst->size)
			p = simplify(CVF, dst, p, NULL);
		break;
	case _POINTER:
		if (src->op != dst->op)
			p = simplify(CVP, dst, p, NULL);
		else {
			if (isfunc(src->type) && !isfunc(dst->type)
				|| !isfunc(src->type) && isfunc(dst->type))
				warning("conversion from `%t' to `%t' is compiler dependent\n", p->type, type);

			if (src->size != dst->size)
				p = simplify(CVP, dst, p, NULL);
		}
		break;
	default: assert(0);
	}
	return retype(p, type);
}
/*140*/
Tree field(Tree p, const char* name) {
	Field q;
	Type ty1, ty = p->type;

	if (isptr(ty))
		ty = deref(ty);
	ty1 = ty;
	ty = unqual(ty);
	if ((q = fieldref(name, ty)) != NULL) {
		if (isarray(q->type)) {
			ty = q->type->type;
			if (isconst(ty1) && !isconst(ty))
				ty = qual(_CONST, ty);
			if (isvolatile(ty1) && !isvolatile(ty))
				ty = qual(_VOLATILE, ty);
			ty = array(ty, q->type->size / ty->size, q->type->align);
		}
		else {
			ty = q->type;
			if (isconst(ty1) && !isconst(ty))
				ty = qual(_CONST, ty);
			if (isvolatile(ty1) && !isvolatile(ty))
				ty = qual(_VOLATILE, ty);
			ty = ptr(ty);
		}
		if (YYcheck && !isaddrop(p->op) && q->offset > 0)	/* omit */
			p = nullcall(ty, YYcheck, p, consttree(q->offset, inttype));	/* omit */
		else					/* omit */
			p = simplify(ADD + P, ty, p, consttree(q->offset, signedptr));

		if (q->lsb) {
			p = tree(FIELD, ty->type, rvalue(p), NULL);
			p->u.field = q;
		}
		else if (!isarray(q->type))
			p = rvalue(p);

	}
	else {
		error("unknown field `%s' of `%t'\n", name, ty);
		p = rvalue(retype(p, ptr(inttype)));
	}
	return p;
}
/* funcname - return name of function f or a function' */
char* funcname(Tree f) {
	if (isaddrop(f->op))
		return stringf("`%s'", f->u.sym->name);
	return "a function";
}
/*138*/
static Tree nullcheck(Tree p) {
	if (!needconst && YYnull && isptr(p->type)) {
		p = value(p);
		if (strcmp(YYnull->name, "_YYnull") == 0) {
			Symbol t1 = temporary(REGISTER, voidptype);
			p = tree(RIGHT, p->type,
				tree(OR, voidtype,
					cond(asgn(t1, cast(p, voidptype))),
					vcall(YYnull, voidtype, (file && *file ? pointer(idtree(mkstr(file)->u.c.loc)) : cnsttree(voidptype, NULL)), cnsttree(inttype, (long)lineno), NULL)),
				idtree(t1));
		}

		else
			p = nullcall(p->type, YYnull, p, cnsttree(inttype, 0L));

	}
	return p;
}
Tree nullcall(Type pty, Symbol f, Tree p, Tree e) {
	Type ty;

	if (isarray(pty))
		return retype(nullcall(atop(pty), f, p, e), pty);
	ty = unqual(unqual(p->type)->type);
	return vcall(f, pty,
		p, e,
		cnsttree(inttype, (long)ty->size),
		cnsttree(inttype, (long)ty->align),
		(file && *file ? pointer(idtree(mkstr(file)->u.c.loc)) : cnsttree(voidptype, NULL)), cnsttree(inttype, (long)lineno), NULL);
}
