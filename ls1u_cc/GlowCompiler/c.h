#pragma once

#include <assert.h> //C��׼��
#include <stdarg.h> //C��׼��
#include <stdio.h> //C��׼��
#include <stdlib.h> //C��׼��
#include <limits.h> //C��׼��
#include <string.h> //C��׼��


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

#define extend(x,ty) ((x)&(1ULL<<(8*(ty)->size-1)) ? (x)|((~0ULL)<<(8*(ty)->size-1)) : (x)&ones(8*(ty)->size)) //�޸�֧��64λ2022.2.24�޸�
//#define extend(x,ty) ((x)&(1<<(8*(ty)->size-1)) ? (x)|((~0UL)<<(8*(ty)->size-1)) : (x)&ones(8*(ty)->size)) //x��ֵת��Ϊty���͵�ֵ,������
#define ones(n) ((n)>8*sizeof (unsigned long) ? ~0ULL : ~((~0ULL)<<(n))) //�޸�֧��64λ2022.2.24�޸�
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
#define fieldsize(p)  (p)->bitsize  //ȡλ����
#define fieldright(p) ((p)->lsb - 1)  //ȡλ���ұ�λ��
#define fieldleft(p)  (8*(p)->type->size - \
                        fieldsize(p) - fieldright(p))  //ȡλ�����λ��
#define fieldmask(p)  (~(fieldsize(p) < 8*unsignedtype->size ? ~0u<<fieldsize(p) : 0u))  //����,��fieldsize(p)��1���
typedef struct node* Node;

typedef struct list* List;

typedef struct code* Code;

typedef struct swtch* Swtch;

typedef struct symbol* Symbol; //���Žṹ��ָ��



typedef struct coord {
	char* file;
	unsigned x, y;
} Coordinate;

typedef struct table* Table;

/*�޸�֧��64λ,2022.2.24*/
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
	unsigned char size, align, outofline; //59ҳ
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
	unsigned little_endian : 1;//Ϊ1������ǵ�λ����,0���λ����
	unsigned mulops_calls : 1; //Ϊ0Ӳ���˳�
	unsigned wants_callb : 1; //259
	unsigned wants_argb : 1;  //61,142
	unsigned left_to_right : 1; //������������˳��,143,259
	unsigned wants_dag : 1;  //���Ϊ0,��ǰ��������ʽ����ʱ�����Ա�����Щʹ�ö�εĹ����ӱ��ʽ
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
	Xinterface x; //���ʹ�ã������Ŀ�������صĽӿ����ݺͺ���
} _Interface; //�ӿڼ�¼����

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

/*��ַ��*/
struct addrstr {
	char *file;				//��ַ�����ļ�
	unsigned long a_7_0;	//��8λ��ַ����ROMλ��
	unsigned long a_15_8;	//��8λ��ַ����ROMλ��
	unsigned long a_23_16;	//��8λ��ַ����ROMλ��
	long offset;			//ƫ�Ƶ�ַ
	ADDRSTR link;			//ָ����һ��addrstr
};
/*��¼��ַ����*/
struct addrdata {
	char* name;				//��ַ����
	unsigned long base;		//��ַ
	ADDRSTR redirectaddr;	//ָ��ȴ��ض����λ��
	ADDRDATA link;			//ָ����һ��addrdata
};
/*����������*/
typedef struct {
	enum at{
		XOP_VOID, XOP_LOC, XOP_OFFSET, XOP_CONST_P, XOP_REGISTER_FILE, XOP_CONST, XOP_REGISTER_IO0, XOP_REGISTER_IO1, XOP_REGISTER_A, XOP_REGISTER_B
	} addrtype;				//��������ַ����
	enum dt{
		XOP_X, XOP_F, XOP_I = 5, XOP_U, XOP_P, XOP_B = 9
	} datatype;				//��������������
	ADDRDATA entry;			//addrdata���
	unsigned char datasize;	//�������ֽ���
	char asgnskip;			//Ϊ1��������һ��ASGN�ڵ�
	Value v;				//������ֵ
} Xop;
/*dag�ڵ㶨��*/
struct node {
	short op;  //���dag������,62ҳ
	short count;  //61ҳ
	Symbol syms[3]; //һЩdag����Ҳʹ��һ�����������ű�ָ����Ϊ������,��Щ�����������syms��.
	Node kids[2];  //kids��Ԫ��ָ��������ڵ�
	Node link;  //linkָ��ɭ������һ��dag�ĸ�
	Xnode x;  //�Ժ�˽ڵ����չ,62ҳ
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
			long long* values; //�޸�֧��64λ,2022.2.27
			Symbol* labels;
		} swtch;

	} u;
};
/*�޸�֧��64λ,2022.2.27*/
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
/*���Žṹ*/
struct symbol {

	char* name; //������
	int scope;  //����������
	Coordinate src; //�������ļ��еĶ�λ
	Symbol up;  //ָ���ϸ�����
	List uses;  //���ŵ�ʹ�����
	int sclass; //���ŵ���չ�洢����(AUTO,REGISTER,STATIC,EXTERN)
	unsigned structarg : 1;  //���ӿڱ�־wants_argb��1,structarg��ʶ�ṹ����

	unsigned addressed : 1;
	unsigned computed : 1;
	unsigned temporary : 1;  //��ʱ������temporary��generated����1,����ź��������ɵı���,�����ַ������ֵı���,ֻ��generated��1
	unsigned generated : 1;  //��ʱ������temporary��generated����1,����ź��������ɵı���,�����ַ������ֵı���,ֻ��generated��1
	unsigned defined : 1;  //����һ�����ʱ��λ������
	Type type;  //����,����,����,�ṹ,���Ϻ�ö�ٵ�����
	float ref;  //���Ʊ����ͱ�ű����õĴ���,�����ֵ��ʾ�����������ٱ�����һ��

	union {

		struct {
			int label;  //label��Ψһ��ʶ�ñ�ŵ���ֵ,name��ֵ���ַ�����ʾ
			Symbol equatedto;
		} l;

		struct {
			unsigned cfields : 1;  //�ṹ�����ϵ����������const��volatile,cfields��vfields��1
			unsigned vfields : 1;
			Table ftab;		/* omit */
			Field flist;  //ָ����link����������field�ṹ
		} s;

		int value;
		Symbol* idlist;

		struct {
			Value min, max;
		} limits;

		struct {
			Value v;  //��ų�����ʵ��ֵ
			Symbol loc;  //�����Ҫ����һ����������ų���,��ô,loc��ָ��ñ����ķ��ű����
		} c;

		struct {
			Coordinate pt;
			int label;
			int ncalls;
			Symbol* callee;
		} f;

		int seg; //����ȫ�ֺ;�̬����,u.seg�����˱����������߼���.
		Symbol alias;

		struct {
			Node cse;  //ǰ��������ʱ�������ŵ�u.t.cse��,�������Ϊdag�ڵ�,�����������ֵ
			int replace;
			Symbol next;
		} t;
	} u;
	Xsymbol x;  //���ں�˴�ŷ�������Ŀ�������ص�����
};

enum { CONSTANTS = 1, LABELS, GLOBAL, PARAM, LOCAL }; //CONSTANTS(����),LABELS(���),GLOBAL(ȫ�ֱ���),PARAM(����),LOCAL(�ֲ�����)
/*���ʽ�﷨��,113ҳ*/
struct tree {
	int op; //����������
	Type type; //������������
	Tree kids[2]; //������
	Node node; //��Ӧ��dag
	union {
		Value v;
		Symbol sym;

		Field field;
	} u; //������Ϣ
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
	int op;  //������Ͳ���������
	Type type;
	int align;  //���Ͷ����ֽ�
	int size;  //�����ܴ�С,��align��������
	union {
		Symbol sym;  //ָ����ű����
		struct {
			unsigned oldstyle : 1; //1Ϊ�ɷ��ʡ�Բ���������,0Ϊ�·�����ǰ�������������,145
			Type* proto; //ָ���Կ�ָ���β��Type����,proto[i]��i+1������������,145
		} f;
	} u;
	Xtype x;
};
struct field {
	char* name;  //�������
	Type type;  //�������
	int offset;  //�ڽṹ�е�ƫ����,��λ�ֽ�
	short bitsize;  //���λ��
	short lsb;  //λ���������Чλ��λ��+1,�����Чλ�Ŵ�0��ʼ
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

/*�޸�*/
extern int rcc_main(int argc, char* argv[]);
