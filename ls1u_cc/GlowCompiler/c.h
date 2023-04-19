#pragma once

#include <assert.h> //C标准库
#include <stdarg.h> //C标准库
#include <stdio.h> //C标准库
#include <stdlib.h> //C标准库
#include <limits.h> //C标准库
#include <string.h> //C标准库


#define NEW(p,a) ((p) = allocate(sizeof *(p), (a)))
#define NEW0(p,a) memset(NEW((p),(a)), 0, sizeof *(p))

#define isaddrop(op) (specific(op)==ADDRG+P || specific(op)==ADDRL+P \
	|| specific(op)==ADDRF+P)

#define	MAXLINE  512
#define	BUFSIZE 4096

#define istypename(t,tsym) (kind[t] == _CHAR \
	|| t == ID && tsym && tsym->sclass == TYPEDEF)
#define sizeop(n) ((n)<<10)
#define generic(op)  ((op)&0x3F0)
#define specific(op) ((op)&0x3FF)
#define opindex(op) (((op)>>4)&0x3F)
#define opkind(op)  ((op)&~0x3F0)
#define opsize(op)  ((op)>>10)
#define optype(op)  ((op)&0xF)
#ifdef __LCC__
#ifndef __STDC__
#define __STDC__
#endif
#endif
#define NELEMS(a) ((int)(sizeof (a)/sizeof ((a)[0])))
#undef roundup
#define roundup(x,n) (((x)+((n)-1))&(~((n)-1)))
#define mkop(op,ty) (specific((op) + ttob(ty)))

#define extend(x,ty) ((x)&(1ULL<<(8*(ty)->size-1)) ? (x)|((~0ULL)<<(8*(ty)->size-1)) : (x)&ones(8*(ty)->size)) //修改支持64位2022.2.24修改
//#define extend(x,ty) ((x)&(1<<(8*(ty)->size-1)) ? (x)|((~0UL)<<(8*(ty)->size-1)) : (x)&ones(8*(ty)->size)) //x的值转换为ty类型的值,带符号
#define ones(n) ((n)>8*sizeof (unsigned long) ? ~0ULL : ~((~0ULL)<<(n))) //修改支持64位2022.2.24修改
//#define ones(n) ((n)>=8*sizeof (unsigned long) ? ~0UL : ~((~0UL)<<(n)))

#define isqual(t)     ((t)->op >= _CONST)
#define unqual(t)     (isqual(t) ? (t)->type : (t))

#define isvolatile(t) ((t)->op == _VOLATILE \
                    || (t)->op == _CONST+_VOLATILE)
#define isconst(t)    ((t)->op == _CONST \
                    || (t)->op == _CONST+_VOLATILE)
#define isarray(t)    (unqual(t)->op == _ARRAY)
#define isstruct(t)   (unqual(t)->op == _STRUCT \
                    || unqual(t)->op == _UNION)
#define isunion(t)    (unqual(t)->op == _UNION)
#define isfunc(t)     (unqual(t)->op == _FUNCTION)
#define isptr(t)      (unqual(t)->op == _POINTER)
#define ischar(t)     ((t)->size == 1 && isint(t))
#define isint(t)      (unqual(t)->op == _INT \
                    || unqual(t)->op == _UNSIGNED)
#define isfloat(t)    (unqual(t)->op == _FLOAT)
#define isarith(t)    (unqual(t)->op <= _UNSIGNED)
#define isunsigned(t) (unqual(t)->op == _UNSIGNED)
#define isscalar(t)   (unqual(t)->op <= _POINTER \
                    || unqual(t)->op == _ENUM)
#define isenum(t)     (unqual(t)->op == _ENUM)
#define fieldsize(p)  (p)->bitsize  //取位域宽度
#define fieldright(p) ((p)->lsb - 1)  //取位域右边位宽
#define fieldleft(p)  (8*(p)->type->size - \
                        fieldsize(p) - fieldright(p))  //取位域左边位宽
#define fieldmask(p)  (~(fieldsize(p) < 8*unsignedtype->size ? ~0u<<fieldsize(p) : 0u))  //掩码,由fieldsize(p)个1组成
typedef struct node* Node;

typedef struct list* List;

typedef struct code* Code;

typedef struct swtch* Swtch;

typedef struct symbol* Symbol; //符号结构的指针



typedef struct coord {
	char* file;
	unsigned x, y;
} Coordinate;

typedef struct table* Table;

/*修改支持64位,2022.2.24*/
typedef union value {
	long long i;
	unsigned long long u;
	long double d;
	void* p;
	void (*g)(void);
} Value;
/*
typedef union value {
	long i;
	unsigned long u;
	long double d;
	void* p;
	void (*g)(void);
} Value;
*/
typedef struct tree* Tree;

typedef struct type* Type;

typedef struct field* Field;

typedef struct {
	unsigned printed : 1;
	unsigned marked;
	unsigned short typeno;
	void* xt;
} Xtype;

#include "config.h"
typedef struct metrics {
	unsigned char size, align, outofline; //59页
} Metrics;
typedef struct _interface {
	Metrics charmetric;
	Metrics shortmetric;
	Metrics intmetric;
	Metrics longmetric;
	Metrics longlongmetric;
	Metrics floatmetric;
	Metrics doublemetric;
	Metrics longdoublemetric;
	Metrics ptrmetric;
	Metrics structmetric;
	unsigned little_endian : 1;//为1则机器是低位优先,0则高位优先
	unsigned mulops_calls : 1; //为0硬件乘除
	unsigned wants_callb : 1; //259
	unsigned wants_argb : 1;  //61,142
	unsigned left_to_right : 1; //函数参数计算顺序,143,259
	unsigned wants_dag : 1;  //如果为0,则前端生成显式的临时变量以保存那些使用多次的公共子表达式
	unsigned unsigned_char : 1;
	void (*_address)(Symbol p, Symbol q, long n);
	void (*_blockbeg)(Env*);
	void (*_blockend)(Env*);
	void (*_defaddress)(Symbol);
	void (*_defconst)  (int suffix, int size, Value v);
	void (*_defstring)(int n, char* s);
	void (*_defsymbol)(Symbol);
	void (*_emit)    (Node);
	void (*_export)(Symbol);
	void (*_function)(Symbol, Symbol[], Symbol[], int);
	Node(*_gen)     (Node);
	void (*_global)(Symbol);
	void (*_import)(Symbol);
	void (*_local)(Symbol);
	void (*_progbeg)(int argc, char* argv[]);
	void (*_progend)(void);
	void (*_segment)(int);
	void (*_space)(int);
	void (*_stabblock)(int, int, Symbol*);
	void (*_stabend)  (Coordinate*, Symbol, Coordinate**, Symbol*, Symbol*);
	void (*_stabfend) (Symbol, int);
	void (*_stabinit) (char*, int, char* []);
	void (*_stabline) (Coordinate*);
	void (*_stabsym)  (Symbol);
	void (*_stabtype) (Symbol);
	Xinterface x; //后端使用，存放与目标机器相关的接口数据和函数
} _Interface; //接口记录定义

typedef struct binding {
	char* name;
	_Interface* ir;
} Binding;

extern Binding bindings[];
extern _Interface* IR;
typedef struct {
	List blockentry;
	List blockexit;
	List entry;
	List exit;
	List returns;
	List points;
	List calls;
	List end;
} Events;

enum {
#define xx(a,b,c,d,e,f,g) a=b,
#define yy(a,b,c,d,e,f,g)
#include "token.h"
	LAST
};

typedef struct addrdata* ADDRDATA;
typedef struct addrstr* ADDRSTR;

/*地址串*/
struct addrstr {
	char *file;				//地址所在文件
	unsigned long a_7_0;	//低8位地址所在ROM位置
	unsigned long a_15_8;	//中8位地址所在ROM位置
	unsigned long a_23_16;	//高8位地址所在ROM位置
	long offset;			//偏移地址
	ADDRSTR link;			//指向下一个addrstr
};
/*记录地址参数*/
struct addrdata {
	char* name;				//地址名称
	unsigned long base;		//基址
	ADDRSTR redirectaddr;	//指向等待重定向的位置
	ADDRDATA link;			//指向下一个addrdata
};
/*操作数定义*/
typedef struct {
	enum at{
		XOP_VOID, XOP_LOC, XOP_OFFSET, XOP_CONST_P, XOP_REGISTER_FILE, XOP_CONST, XOP_REGISTER_IO0, XOP_REGISTER_IO1, XOP_REGISTER_A, XOP_REGISTER_B
	} addrtype;				//操作数地址类型
	enum dt{
		XOP_X, XOP_F, XOP_I = 5, XOP_U, XOP_P, XOP_B = 9
	} datatype;				//操作数数据类型
	ADDRDATA entry;			//addrdata入口
	unsigned char datasize;	//操作数字节数
	char asgnskip;			//为1则跳过上一个ASGN节点
	Value v;				//操作数值
} Xop;
/*dag节点定义*/
struct node {
	short op;  //存放dag操作符,62页
	short count;  //61页
	Symbol syms[3]; //一些dag操作也使用一个或两个符号表指针作为操作数,这些操作数存放在syms中.
	Node kids[2];  //kids的元素指向操作数节点
	Node link;  //link指向森林中下一个dag的根
	Xnode x;  //对后端节点的扩展,62页
	Xop glowop;
};
enum {
	F = _FLOAT,
	_I = _INT,
	U = _UNSIGNED,
	P = _POINTER,
	V = _VOID,
	B = _STRUCT
};
#define gop(name,value) name=value<<4,
#define op(name,type,sizes)

enum {
#include "ops.h"
	LASTOP
};

#undef gop
#undef op
enum { CODE = 1, BSS, DATA, LIT };
enum { PERM = 0, FUNC, STMT, GLOW_ADDRDATA };
struct list {
	void* x;
	List link;
};

struct code {
	enum code_enum{
		Blockbeg, Blockend, Local, Address, Defpoint,
		Label, Start, Gen, Jump, Switch
	} kind;
	Code prev, next;
	union {
		struct {
			int level;
			Symbol* locals;
			Table identifiers, types;
			Env x;
		} block;
		Code begin;
		Symbol var;

		struct {
			Symbol sym;
			Symbol base;
			long offset;
		} addr;
		struct {
			Coordinate src;
			int point;
		} point;
		Node forest;
		struct {
			Symbol sym;
			Symbol table;
			Symbol deflab;
			int size;
			//long* values;
			long long* values; //修改支持64位,2022.2.27
			Symbol* labels;
		} swtch;

	} u;
};
/*修改支持64位,2022.2.27*/
struct swtch {
	Symbol sym;
	int lab;
	Symbol deflab;
	int ncases;
	int size;
	long long* values;
	Symbol* labels;
};
/*
struct swtch {
	Symbol sym;
	int lab;
	Symbol deflab;
	int ncases;
	int size;
	long* values;
	Symbol* labels;
};
*/
/*符号结构*/
struct symbol {

	char* name; //符号名
	int scope;  //符号作用域
	Coordinate src; //符号在文件中的定位
	Symbol up;  //指向上个符号
	List uses;  //符号的使用情况
	int sclass; //符号的扩展存储类型(AUTO,REGISTER,STATIC,EXTERN)
	unsigned structarg : 1;  //当接口标志wants_argb置1,structarg标识结构参数

	unsigned addressed : 1;
	unsigned computed : 1;
	unsigned temporary : 1;  //临时变量的temporary和generated域都置1,而标号和其他生成的变量,如存放字符串文字的变量,只有generated置1
	unsigned generated : 1;  //临时变量的temporary和generated域都置1,而标号和其他生成的变量,如存放字符串文字的变量,只有generated置1
	unsigned defined : 1;  //定义一个标记时该位被设置
	Type type;  //变量,函数,常量,结构,联合和枚举的类型
	float ref;  //估计变量和标号被引用的次数,非零的值表示变量或标号至少被引用一次

	union {

		struct {
			int label;  //label是唯一标识该标号的数值,name是值的字符串表示
			Symbol equatedto;
		} l;

		struct {
			unsigned cfields : 1;  //结构或联合的任意域带有const或volatile,cfields和vfields置1
			unsigned vfields : 1;
			Table ftab;		/* omit */
			Field flist;  //指向用link连接起来的field结构
		} s;

		int value;
		Symbol* idlist;

		struct {
			Value min, max;
		} limits;

		struct {
			Value v;  //存放常量的实际值
			Symbol loc;  //如果需要生成一个变量来存放常量,那么,loc域指向该变量的符号表入口
		} c;

		struct {
			Coordinate pt;
			int label;
			int ncalls;
			Symbol* callee;
		} f;

		int seg; //对于全局和静态变量,u.seg给出了变量定义点的逻辑段.
		Symbol alias;

		struct {
			Node cse;  //前端设置临时变量符号的u.t.cse域,该域可作为dag节点,计算所保存的值
			int replace;
			Symbol next;
		} t;
	} u;
	Xsymbol x;  //用于后端存放符号中与目标机器相关的数据
};

enum { CONSTANTS = 1, LABELS, GLOBAL, PARAM, LOCAL }; //CONSTANTS(常量),LABELS(标号),GLOBAL(全局变量),PARAM(参数),LOCAL(局部变量)
/*表达式语法树,113页*/
struct tree {
	int op; //操作符代码
	Type type; //计算结果的类型
	Tree kids[2]; //操作数
	Node node; //对应的dag
	union {
		Value v;
		Symbol sym;

		Field field;
	} u; //附加信息
};
enum {
	AND = 38 << 4,
	NOT = 39 << 4,
	OR = 40 << 4,
	COND = 41 << 4,
	RIGHT = 42 << 4,
	FIELD = 43 << 4
};
struct type {
	int op;  //存放类型操作符编码
	Type type;
	int align;  //类型对齐字节
	int size;  //类型总大小,是align的整数倍
	union {
		Symbol sym;  //指向符号表入口
		struct {
			unsigned oldstyle : 1; //1为旧风格省略参数的类型,0为新风格总是包含参数的类型,145
			Type* proto; //指向以空指针结尾的Type数组,proto[i]是i+1个参数的类型,145
		} f;
	} u;
	Xtype x;
};
struct field {
	char* name;  //域的名字
	Type type;  //域的类型
	int offset;  //在结构中的偏移量,单位字节
	short bitsize;  //域的位宽
	short lsb;  //位域中最低有效位的位号+1,最低有效位号从0开始
	Field link;
};
extern int assignargs;
extern int prunetemps;
extern int nodecount;
extern Symbol cfunc;
extern Symbol retv;
extern Tree(*optree[])(int, Tree, Tree);

extern char kind[];
extern int errcnt;
extern int errlimit;
extern int wflag;
extern Events events;
extern float refinc;

extern unsigned char* cp;
extern unsigned char* limit;
extern char* firstfile;
extern char* file;
extern char* line;
extern int lineno;
extern int t;
extern char* token;
extern Symbol tsym;
extern Coordinate src;
extern int Aflag;
extern int Pflag;
extern Symbol YYnull; //138
extern Symbol YYcheck;
extern int glevel;
extern int xref;

extern int ncalled;
extern int npoints;

extern int needconst;
extern int explicitCast;
extern struct code codehead;
extern Code codelist;
extern Table stmtlabs;
extern float density;
extern Table constants;
extern Table externals;
extern Table globals;
extern Table identifiers;
extern Table labels;
extern Table types;
extern int level;

extern List loci, symbols;

extern List symbols;

extern int where;
extern Type chartype;
extern Type doubletype;
extern Type floattype;
extern Type inttype;
extern Type longdouble;
extern Type longtype;
extern Type longlong;
extern Type shorttype;
extern Type signedchar;
extern Type unsignedchar;
extern Type unsignedlonglong;
extern Type unsignedlong;
extern Type unsignedshort;
extern Type unsignedtype;
extern Type charptype;
extern Type funcptype;
extern Type voidptype;
extern Type voidtype;
extern Type unsignedptr;
extern Type signedptr;
extern Type widechar;
extern void* allocate(unsigned long n, unsigned a);
extern void deallocate(unsigned a);
extern void* newarray(unsigned long m, unsigned long n, unsigned a);
extern void walk(Tree e, int tlab, int flab);
extern Node listnodes(Tree e, int tlab, int flab);
extern Node newnode(int op, Node left, Node right, Symbol p);
extern Tree cvtconst(Tree);
extern void printdag(Node, int);
extern void compound(int, Swtch, int);
extern void defglobal(Symbol, int);
extern void finalize(void);
extern void program(void);

extern Tree vcall(Symbol func, Type ty, ...);
extern Tree addrof(Tree);
extern Tree asgn(Symbol, Tree);
extern Tree asgntree(int, Tree, Tree);
extern Type assign(Type, Tree);
extern Tree bittree(int, Tree, Tree);
extern Tree call(Tree, Type, Coordinate);
extern Tree calltree(Tree, Type, Tree, Symbol);
extern Tree condtree(Tree, Tree, Tree);
extern Tree cnsttree(Type, ...);
extern Tree consttree(int, Type);
extern Tree eqtree(int, Tree, Tree);
extern int iscallb(Tree);
extern Tree shtree(int, Tree, Tree);
extern void typeerror(int, Tree, Tree);

extern void test(int tok, char set[]);
extern void expect(int tok);
extern void skipto(int tok, char set[]);
extern void error(const char*, ...);
extern int fatal(const char*, const char*, int);
extern void warning(const char*, ...);

typedef void (*Apply)(void*, void*, void*);
extern void attach(Apply, void*, List*);
extern void apply(List event, void* arg1, void* arg2);
extern Tree retype(Tree p, Type ty);
extern Tree rightkid(Tree p);
extern int hascall(Tree p);
extern Type binary(Type, Type);
extern Tree cast(Tree, Type);
extern Tree cond(Tree);
extern Tree expr0(int);
extern Tree expr(int);
extern Tree expr1(int);
extern Tree field(Tree, const char*);
extern char* funcname(Tree);
extern Tree idtree(Symbol);
extern Tree incr(int, Tree, Tree);
extern Tree lvalue(Tree);
extern Tree nullcall(Type, Symbol, Tree, Tree);
extern Tree pointer(Tree);
extern Tree rvalue(Tree);
extern Tree value(Tree);

extern void defpointer(Symbol);
extern Type initializer(Type, int);
extern void swtoseg(int);

extern void input_init(int, char* []);
extern void fillbuf(void);
extern void nextline(void);

extern int getchr(void);
extern int gettok(void);

extern void emitcode(void);
extern void gencode(Symbol[], Symbol[]);
extern void fprint(FILE* f, const char* fmt, ...);
extern char* stringf(const char*, ...);
extern void check(Node);
extern void print(const char*, ...);

extern List append(void* x, List list);
extern int  length(List list);
extern void* ltov(List* list, unsigned a);
extern void init(int, char* []);

extern Type _typename(void);
extern void checklab(Symbol p, void* cl);
extern Type enumdcl(void);
extern void main_init(int, char* []);
extern int main(int, char* []);

extern void vfprint(FILE*, char*, const char*, va_list);

void profInit(char*);
extern int process(char*);
extern int findfunc(char*, char*);
extern int findcount(char*, int, int);

extern Tree _constexpr(int);
extern int intexpr(int, int);
extern Tree simplify(int, Type, Tree, Tree);
extern int ispow2(unsigned long u);

extern int reachable(int);

extern void addlocal(Symbol);
extern void branch(int);
extern Code code(int);
extern void definelab(int);
extern void definept(Coordinate*);
extern void equatelab(Symbol, Symbol);
extern Node jump(int);
extern void retcode(Tree);
extern void statement(int, Swtch, int);
extern void swcode(Swtch, int*, int, int);
extern void swgen(Swtch);

extern char* string(const char* str);
extern char* stringn(const char* str, int len);
extern char* stringd(long n);
extern Symbol relocate(const char* name, Table src, Table dst);
extern void use(Symbol p, Coordinate src);
extern void locus(Table tp, Coordinate* cp);
extern Symbol allsymbols(Table);

extern Symbol constant(Type, Value);
extern void enterscope(void);
extern void exitscope(void);
extern Symbol findlabel(int);
extern Symbol findtype(Type);
extern void foreach(Table, int, void (*)(Symbol, void*), void*);
extern Symbol genident(int, Type, int);
extern int genlabel(int);
extern Symbol install(const char*, Table*, int, int);
extern Symbol intconst(int);
extern Symbol lookup(const char*, Table);
extern Symbol mkstr(char*);
extern Symbol mksymbol(int, const char*, Type);
extern Symbol newtemp(int, int, int);
extern Table newtable(int);
extern Table table(Table, int);
extern Symbol temporary(int, Type);
extern char* vtoa(Type, Value);

extern void traceInit(char*);
extern int nodeid(Tree);
extern char* opname(int);
extern int* printed(int);
extern void printtree(Tree, int);
extern Tree root(Tree);
extern Tree texpr(Tree(*)(int), int, int);
extern Tree tree(int, Type, Tree, Tree);

extern void type_init(int, char* []);

extern Type signedint(Type);

extern int hasproto(Type);
extern void outtype(Type, FILE*);
extern void printdecl(Symbol p, Type ty);
extern void printproto(Symbol p, Symbol args[]);
extern char* typestring(Type ty, char* id);
extern Field fieldref(const char* name, Type ty);
extern Type array(Type, int, int);
extern Type atop(Type);
extern Type btot(int, int);
extern Type compose(Type, Type);
extern Type deref(Type);
extern int eqtype(Type, Type, int);
extern Field fieldlist(Type);
extern Type freturn(Type);
extern Type ftype(Type, ...);
extern Type func(Type, Type*, int);
extern Field newfield(char*, Type, Type);
extern Type newstruct(int, char*);
extern void printtype(Type, int);
extern Type promote(Type);
extern Type ptr(Type);
extern Type qual(int, Type);
extern void rmtypes(int);
extern int ttob(Type);
extern int variadic(Type);

/*修改*/
extern int rcc_main(int argc, char* argv[]);
