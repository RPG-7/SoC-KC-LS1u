#include "c.h"

static char rcsid[] = "$Id$";

static void printtoken(void);
int errcnt = 0;
int errlimit = 20;
char kind[] = {
#define xx(a,b,c,d,e,f,g) f,
#define yy(a,b,c,d,e,f,g) f,
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

int wflag;		/* != 0 to suppress warning messages */


void error_init(void)
{
	errcnt = 0;
	//errlimit = 20;
	errlimit = 65536; //修改增加错误数量输出2022.3.10
	wflag = 0;
}

/*检查下一个单词是否等于tok,不是则报错,并跳过,直到遇到set,107页*/
void test(int tok, char set[]) {
	if (t == tok)
		t = gettok();
	else {
		expect(tok); //报错
		skipto(tok, set); //跳过错误单词
		if (t == tok)
			t = gettok();
	}
}
/*检查下一个单词是否等于tok,是则转入下一个输入单词,108页*/
void expect(int tok) {
	if (t == tok)
		t = gettok();
	else {
		error("syntax error; found");
		printtoken();
		fprint(stderr, " expecting `%k'\n", tok);
	}
}
void error(const char* fmt, ...) {
	va_list ap;

	if (errcnt++ >= errlimit) {
		errcnt = -1;
		error("too many errors\n");
		exit(1);
	}
	va_start(ap, fmt);
	if (firstfile != file && firstfile && *firstfile)
		fprint(stderr, "%s: ", firstfile);
	fprint(stderr, "%w: ", &src);
	vfprint(stderr, NULL, fmt, ap);
	va_end(ap);
}

void skipto(int tok, char set[]) {
	int n;
	char* s;

	assert(set);
	for (n = 0; t != EOI && t != tok; t = gettok()) {
		for (s = set; *s && kind[t] != *s; s++)
			;
		if (kind[t] == *s)
			break;
		if (n++ == 0)
			error("skipping");
		if (n <= 8)
			printtoken();
		else if (n == 9)
			fprint(stderr, " ...");
	}
	if (n > 8) {
		fprint(stderr, " up to");
		printtoken();
	}
	if (n > 0)
		fprint(stderr, "\n");
}
/* fatal - issue fatal error message and exit */
int fatal(const char* name, const char* fmt, int n) {
	print("\n");
	errcnt = -1;
	error("compiler error in %s--", name);
	fprint(stderr, fmt, n);
	exit(EXIT_FAILURE);
	return 0;
}

/* printtoken - print current token preceeded by a space */
static void printtoken(void) {
	switch (t) {
	case ID: fprint(stderr, " `%s'", token); break;
	case ICON:
		fprint(stderr, " `%s'", vtoa(tsym->type, tsym->u.c.v));
		break;
	case SCON: {
		int i, n;
		if (ischar(tsym->type->type)) {
			char* s = (char*)tsym->u.c.v.p;
			n = tsym->type->size;
			fprint(stderr, " \"");
			for (i = 0; i < 20 && i < n && *s; s++, i++)
				if (*s < ' ' || *s >= 0177)
					fprint(stderr, "\\%o", *s);
				else
					fprint(stderr, "%c", *s);
		}
		else {	/* wchar_t string */
			unsigned int* s = (unsigned int*)tsym->u.c.v.p;
			assert(tsym->type->type->size == widechar->size);
			n = tsym->type->size / widechar->size;
			fprint(stderr, " L\"");
			for (i = 0; i < 20 && i < n && *s; s++, i++)
				if (*s < ' ' || *s >= 0177)
					fprint(stderr, "\\x%x", *s);
				else
					fprint(stderr, "%c", *s);
		}
		if (i < n)
			fprint(stderr, " ...");
		else
			fprint(stderr, "\"");
		break;
	}
	case FCON:
		fprint(stderr, " `%S'", token, (char*)cp - token);
		break;
	case '`': case '\'': fprint(stderr, " \"%k\"", t); break;
	default: fprint(stderr, " `%k'", t);
	}
}

/* warning - issue warning error message */
void warning(const char* fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	if (wflag == 0) {
		errcnt--;
		error("warning: ");
		vfprint(stderr, NULL, fmt, ap);
	}
	va_end(ap);
}

