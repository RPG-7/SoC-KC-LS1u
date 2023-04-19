#include "c.h"

static char rcsid[] = "$Id$";

static char* outs(const char* str, FILE* f, char* bp) {
	if (f)
		fputs(str, f);
	else
		while (*bp = *str++)
			bp++;
	return bp;
}

static char* outd(long n, FILE* f, char* bp) {
	unsigned long m;
	char buf[25], * s = buf + sizeof buf;

	*--s = '\0';
	if (n < 0)
		m = -n;
	else
		m = n;
	do
		*--s = m % 10 + '0';
	while ((m /= 10) != 0);
	if (n < 0)
		*--s = '-';
	return outs(s, f, bp);
}

static char* outu(unsigned long n, int base, FILE* f, char* bp) {
	char buf[25], * s = buf + sizeof buf;

	*--s = '\0';
	do
		*--s = "0123456789abcdef"[n % base];
	while ((n /= base) != 0);
	return outs(s, f, bp);
}
void print(const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vfprint(stdout, NULL, fmt, ap);
	va_end(ap);
}
/* fprint - formatted output to  f */
void fprint(FILE* f, const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);
	vfprint(f, NULL, fmt, ap);
	va_end(ap);
}

/* stringf - formatted output to a saved string */
char* stringf(const char* fmt, ...) {
	char buf[1024];
	va_list ap;
	va_start(ap, fmt);
	vfprint(NULL, buf, fmt, ap);
	va_end(ap);
	return string(buf);
}

/* vfprint - formatted output to f or string bp */
void vfprint(FILE* f, char* bp, const char* fmt, va_list ap) {

	for (; *fmt; fmt++)
		if (*fmt == '%')
			switch (*++fmt) {
			case 'd': bp = outd(va_arg(ap, int), f, bp); break;
			case 'D': bp = outd(va_arg(ap, long), f, bp); break;
			case 'U': bp = outu(va_arg(ap, unsigned long), 10, f, bp); break;
			case 'u': bp = outu(va_arg(ap, unsigned), 10, f, bp); break;
			case 'o': bp = outu(va_arg(ap, unsigned), 8, f, bp); break;
			case 'X': bp = outu(va_arg(ap, unsigned long), 16, f, bp); break;
			case 'x': bp = outu(va_arg(ap, unsigned), 16, f, bp); break;
			case 'f': case 'e':
			case 'g': {
				static char format[] = "%f";
				//char buf[128];
				char buf[320]; //修改支持长浮点 2022.3.8
				format[1] = *fmt;
				sprintf(buf, format, va_arg(ap, double));
				bp = outs(buf, f, bp);
			}
					; break;
			case 's':
				bp = outs(va_arg(ap, char*), f, bp); break;
			case 'p': {
				void* p = va_arg(ap, void*);
				if (p)
					bp = outs("0x", f, bp);
				bp = outu((unsigned long)p, 16, f, bp);
				break;
			}
			case 'c': if (f) fputc(va_arg(ap, int), f); else *bp++ = va_arg(ap, int); break;
			case 'S': { char* s = va_arg(ap, char*);
				int n = va_arg(ap, int);
				if (s)
					for (; n-- > 0; s++)
						if (f) (void)putc(*s, f); else *bp++ = *s;
			} break;
			case 'k': { int t = va_arg(ap, int);
				static char* tokens[] = {
#define xx(a,b,c,d,e,f,g) g,
#define yy(a,b,c,d,e,f,g) g,
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
				assert(tokens[t & 0177]);
				bp = outs(tokens[t & 0177], f, bp);
			} break;
			case 't': { Type ty = va_arg(ap, Type);
				assert(f);
				outtype(ty ? ty : voidtype, f);
			} break;
			case 'w': { Coordinate* p = va_arg(ap, Coordinate*);
				if (p->file && *p->file) {
					bp = outs(p->file, f, bp);
					bp = outs(":", f, bp);
				}
				bp = outd(p->y, f, bp);
			} break;
			case 'I': { int n = va_arg(ap, int);
				while (--n >= 0)
					if (f) (void)putc(' ', f); else *bp++ = ' ';
			} break;
			default:  if (f) (void)putc(*fmt, f); else *bp++ = *fmt; break;
			}
		else if (f)
			(void)putc(*fmt, f);
		else
			*bp++ = *fmt;
	if (!f)
		*bp = '\0';

}
