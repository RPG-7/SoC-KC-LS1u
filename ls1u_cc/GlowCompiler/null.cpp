#include "c.h"
#define I(f) null_##f

static Node I(_gen)(Node p) { return p; }
/*偏移地址通知*/
static void I(_address)(Symbol q, Symbol p, long n) {}
static void I(_blockbeg)(Env* e) {}
static void I(_blockend)(Env* e) {}
/*定义地址通知*/
static void I(_defaddress)(Symbol p) {}
/*定义常量通知*/
static void I(_defconst)(int suffix, int size, Value v) {}
/*定义字符串通知*/
static void I(_defstring)(int len, char* s) {}
/*定义符号通知*/
static void I(_defsymbol)(Symbol p) {}
/*传递语句表达式给后端解析(二叉树形式)*/
static void I(_emit)(Node p) {}
/*输出符号通知*/
static void I(_export)(Symbol p) {}
static void I(_function)(Symbol f, Symbol caller[], Symbol callee[], int ncalls) {}
/*全局符号通知*/
static void I(_global)(Symbol p) {}
/*引进符号通知*/
static void I(_import)(Symbol p) {}
/*局部符号通知*/
static void I(_local)(Symbol p) {}
/*编译开始通知*/
static void I(_progbeg)(int argc, char* argv[]) {}
/*编译结束通知*/
static void I(_progend)(void) {}
/*数据段通知*/
static void I(_segment)(int s) {}
/*空间通知*/
static void I(_space)(int n) {}
static void I(_stabblock)(int brace, int lev, Symbol* p) {}
static void I(_stabend)(Coordinate* cp, Symbol p, Coordinate** cpp, Symbol* sp, Symbol* stab) {}
static void I(_stabfend)(Symbol p, int lineno) {}
static void I(_stabinit)(char* file, int argc, char* argv[]) {}
static void I(_stabline)(Coordinate* cp) {}
static void I(_stabsym)(Symbol p) {}
static void I(_stabtype)(Symbol p) {}

static char rcsid[] = "$Id$";

_Interface nullIR = {
	1, 1, 0,	/* char */
	2, 2, 0,	/* short */
	4, 4, 0,	/* int */
	8, 8, 1,	/* long */
	8 ,8, 1,	/* long long */
	4, 4, 1,	/* float */
	8, 8, 1,	/* double */
	16,16,1,	/* long double */
	4, 4, 0,	/* T* */
	0, 4, 0,	/* struct */
	1,		/* little_endian */
	0,		/* mulops_calls */
	0,		/* wants_callb */
	0,		/* wants_argb */
	1,		/* left_to_right */
	0,		/* wants_dag */
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
	I(_stabblock),
	I(_stabend),
	I(_stabfend),
	I(_stabinit),
	I(_stabline),
	I(_stabsym),
	I(_stabtype)
};
