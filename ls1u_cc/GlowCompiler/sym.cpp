#include "c.h"
#include <stdio.h> //C标准库

static char rcsid[] = "$Id$";

#define equalp(x) v.x == p->sym.u.c.v.x


struct entry {
	struct symbol sym;
	struct entry* link;
};
/*符号表*/
struct table {
	int level; //符号表作用域
	Table previous; //指向上个符号表
	struct entry *buckets[256]; //当前作用域符号哈希链的入口指针
	Symbol all; //当前作用域或上个作用域符号链表的入口
};
#define HASHSIZE NELEMS(((Table)0)->buckets) //HASHSIZE = 256
static struct table
cns = { CONSTANTS },
ext = { GLOBAL },
ids = { GLOBAL },
tys = { GLOBAL };
Table constants = &cns;  //常量符号表
Table externals = &ext;  //extern符号表
Table identifiers = &ids;  //指向内层的符号表
Table globals = &ids;  //文件作用域符号表
Table types = &tys;  //类型标记符号表
Table labels;  //内部标号符号表
int level = GLOBAL; //当前作用域
static int tempid;
List loci, symbols;

static int label;

void sym_init(void)
{
	int i;

	cns = { CONSTANTS };
	cns.previous = 0;
	cns.all = 0;
	for (i = 0; i < 256; ++i) cns.buckets[i] = 0;

	ext = { GLOBAL };
	ext.previous = 0;
	ext.all = 0;
	for (i = 0; i < 256; ++i) ext.buckets[i] = 0;

	ids = { GLOBAL };
	ids.previous = 0;
	ids.all = 0;
	for (i = 0; i < 256; ++i) ids.buckets[i] = 0;

	tys = { GLOBAL };
	tys.previous = 0;
	tys.all = 0;
	for (i = 0; i < 256; ++i) tys.buckets[i] = 0;

	constants = &cns;
	externals = &ext;
	identifiers = &ids;
	globals = &ids;
	types = &tys;
	labels = 0;
	level = GLOBAL;
	int tempid;
	loci = 0;
	symbols = 0;

	label = 1;
}

/*创建一个table,返回它的指针,arena为分配区*/
Table newtable(int arena) {
	Table _new;
	//NEW0(_new, arena);
	//memset(_new = (Table)allocate(sizeof * _new, arena), 0, sizeof * _new);
	_new = (Table)allocate(sizeof * _new, arena);
	int i = sizeof * _new;
	memset(_new, 0, i);
	return _new;
}

/*创建一个table,连接tp指向的table,返回它的指针,level为新的作用域*/
Table table(Table tp, int level) {
	Table _new = newtable(FUNC);
	_new->previous = tp;
	_new->level = level;
	if (tp)
		_new->all = tp->all;
	return _new;
}

/*对指定作用域中的所有符号执行给定函数*/
void foreach(Table tp, int lev, void (*apply)(Symbol, void*), void* cl) {
	assert(tp);
	while (tp && tp->level > lev) //tp所在层同步到lev
		tp = tp->previous;
	if (tp && tp->level == lev) {
		Symbol p;
		Coordinate sav;
		sav = src;
		for (p = tp->all; p && p->scope == lev; p = p->up) { //该层的符号都调用(*apply)(p, cl)
			src = p->src; //src传递坐标给(*apply)(p, cl)
			(*apply)(p, cl);
		}
		src = sav;
	}
}

/*进入一个新的作用域*/
void enterscope(void) {
	if (++level == LOCAL)
		tempid = 0;  //进入局部变量作用域该计数清零
}

/*退出当前作用域*/
void exitscope(void) {
	rmtypes(level);
	if (types->level == level)
		types = types->previous;
	if (identifiers->level == level) {
		if (Aflag >= 2) {
			int n = 0;
			Symbol p;
			for (p = identifiers->all; p && p->scope == level; p = p->up)
				if (++n > 127) {
					warning("more than 127 identifiers declared in a block\n");
					break;
				}
		}
		identifiers = identifiers->previous;
	}
	assert(level >= GLOBAL);
	--level;
}

/*插入一个符号,并返回一个该符号的Symbol, name为符号名称,tpp为所在符号表,level为当前层,arena为分配区*/
Symbol install(const char* name, Table* tpp, int level, int arena) {
	Table tp = *tpp;
	struct entry* p;
	unsigned h = (unsigned long)name & (HASHSIZE - 1);

	assert(level == 0 || level >= tp->level);
	if (level > 0 && tp->level < level)  //小于level层则新建一个table
		tp = *tpp = table(tp, level);
	//NEW0(p, arena);
	memset(p = (entry*)allocate(sizeof * p, arena), 0, sizeof * p);
	p->sym.name = (char*)name;
	p->sym.scope = level;
	p->sym.up = tp->all;
	tp->all = &p->sym;
	p->link = tp->buckets[h];
	tp->buckets[h] = p;
	return &p->sym;
}

/*从src指向的符号表里抽一个名为name的符号出来放进dst指向的符号表,并返回该符号的指针*/
Symbol relocate(const char* name, Table src, Table dst) {
	struct entry *p, ** q;
	Symbol* r;
	unsigned h = (unsigned long)name & (HASHSIZE - 1);

	for (q = &src->buckets[h]; *q; q = &(*q)->link)  //在src指向的符号哈希链里搜索名为name的符号
		if (name == (*q)->sym.name)
			break;
	assert(*q);
	/*
	 Remove the entry from src's hash chain
	  and from its list of all symbols.
	*/

	p = *q;
	*q = (*q)->link;  //从哈希链里抽出来
	for (r = &src->all; *r && *r != &p->sym; r = &(*r)->up)  //从symbol链里抽出来
		;
	assert(*r == &p->sym);
	*r = p->sym.up;

	/*
	 Insert the entry into dst's hash chain
	  and into its list of all symbols.
	  Return the symbol-table entry.
	*/
	p->link = dst->buckets[h];
	dst->buckets[h] = p;
	p->sym.up = dst->all;
	dst->all = &p->sym;
	return &p->sym;
}

/*在表中查找一个符号,并返回一个该符号的Symbol, name为符号名称,tp为所在符号表*/
Symbol lookup(const char* name, Table tp) {
	struct entry* p;
	unsigned h = (unsigned long)name & (HASHSIZE - 1);

	assert(tp);
	do
		for (p = tp->buckets[h]; p; p = p->link)
			if (name == p->sym.name)
				return &p->sym;
	while ((tp = tp->previous) != NULL);
	return NULL;
}

/*产生一个累加计数的序号*/
int genlabel(int n) {
	//static int label = 1;

	label += n;
	return label - n;
}

/*labels表查找一个标号,如果没有找到则新建一个同时通知编译后端,并返回该符号的指针,lab为标号数*/
Symbol findlabel(int lab) {
	struct entry* p;
	unsigned h = lab & (HASHSIZE - 1);

	for (p = labels->buckets[h]; p; p = p->link)
		if (lab == p->sym.u.l.label)
			return &p->sym;
	//NEW0(p, FUNC);
	memset(p = (entry*)allocate(sizeof * p, FUNC), 0, sizeof * p);
	p->sym.name = stringd(lab);
	p->sym.scope = LABELS;
	p->sym.up = labels->all;
	labels->all = &p->sym;
	p->link = labels->buckets[h];
	labels->buckets[h] = p;
	p->sym.generated = 1;  //标志为名称是由数字组成的字符串
	p->sym.u.l.label = lab;  //保存标号数
	(*IR->_defsymbol)(&p->sym);
	return &p->sym;
}

/*constants表中查找类型ty和值v的常量符号,如果没有找到则新建一个同时通知编译后端,并返回该符号的指针,*/
Symbol constant(Type ty, Value v) {
	struct entry* p;
	unsigned h = v.u & (HASHSIZE - 1);
	static union { int x; char endian; } little = { 1 };

	ty = unqual(ty);  //如果ty->op >= _CONST返回ty->type,否则返回ty,即去掉类型中的const和volatile
	for (p = constants->buckets[h]; p; p = p->link)
		if (eqtype(ty, p->sym.type, 1)) //ty指向的地址和p->sym.type的地址一样?
			switch (ty->op) {  //看ty->op是什么类型选择比较的类型
			case _INT:      if (equalp(i)) return &p->sym; break;  //i是long
			case _UNSIGNED: if (equalp(u)) return &p->sym; break;  //u是unsigned long
			case _FLOAT:
				if (v.d == 0.0) {
					float z1 = v.d, z2 = p->sym.u.c.v.d;
					char* b1 = (char*)&z1, * b2 = (char*)&z2;
					if (z1 == z2
						&& (!little.endian && b1[0] == b2[0]
							|| little.endian && b1[sizeof(z1) - 1] == b2[sizeof(z2) - 1]))
						return &p->sym;
				}
				else if (equalp(d)) //d是long double
					return &p->sym;
				break;
			case _FUNCTION: if (equalp(g)) return &p->sym; break;  //g是void (*g)(void)
			case _ARRAY:
			case _POINTER:  if (equalp(p)) return &p->sym; break;  //p是void*
			default: assert(0);
			}
	//NEW0(p, PERM);
	memset(p = (entry*)allocate(sizeof * p, PERM), 0, sizeof* p);
	p->sym.name = vtoa(ty, v);
	p->sym.scope = CONSTANTS;
	p->sym.type = ty;
	p->sym.sclass = STATIC;
	p->sym.u.c.v = v;
	p->link = constants->buckets[h];
	p->sym.up = constants->all;
	constants->all = &p->sym;
	constants->buckets[h] = p;
	if (ty->u.sym && !ty->u.sym->addressed)
		(*IR->_defsymbol)(&p->sym);
	p->sym.defined = 1; //通知完后端之后defined标志置1
	return &p->sym;
}

/*intconst封装了建立和通知整型常量的功能*/
Symbol intconst(int n) {
	Value v;

	v.i = n;
	return constant(inttype, v);
}

/*产生一个符号结构并初始化(产生的局部变量),scls为符号的扩展存储类型,ty为类型,lev为所在层,如果为GLOBAL则通知编译后端,最后返回该符号的指针*/
Symbol genident(int scls, Type ty, int lev) {
	Symbol p;

	//NEW0(p, lev >= LOCAL ? FUNC : PERM);
	memset(p = (Symbol)allocate(sizeof * p, lev >= LOCAL ? FUNC : PERM), 0, sizeof * p);
	p->name = stringd(genlabel(1));
	p->scope = lev;
	p->sclass = scls;
	p->type = ty;
	p->generated = 1;  //标志为名称是由数字组成的字符串
	if (lev == GLOBAL)
		(*IR->_defsymbol)(p);
	return p;
}

/*产生一个符号结构并初始化(产生的临时变量),scls为符号的扩展存储类型,ty为类型,最后返回该符号的指针*/
Symbol temporary(int scls, Type ty) {
	Symbol p;

	//NEW0(p, FUNC);
	memset(p = (Symbol)allocate(sizeof *p, FUNC), 0, sizeof *p);
	p->name = stringd(++tempid);
	p->scope = level < LOCAL ? LOCAL : level;
	p->sclass = scls;
	p->type = ty;
	p->temporary = 1;  //该函数的标志
	p->generated = 1;  //标志为名称是由数字组成的字符串
	return p;
}

/*newtemp给编译后端使用,产生一个符号结构并初始化(产生的临时变量),同时通知编译后端,最后返回该符号的指针*/
Symbol newtemp(int sclass, int tc, int size) {
	Symbol p = temporary(sclass, btot(tc, size));  //btot将该后缀映射为相应类型

	(*IR->_local)(p);
	p->defined = 1;  //通知完后端之后defined标志置1
	return p;
}

Symbol allsymbols(Table tp) {
	return tp->all;
}

void locus(Table tp, Coordinate* cp) {
	loci = append(cp, loci);
	symbols = append(allsymbols(tp), symbols);
}

/*给Symbol指针和符号定位src,增加符号的使用情况uses*/
void use(Symbol p, Coordinate src) {
	Coordinate* cp;

	//NEW(cp, PERM);
	cp = (Coordinate*) allocate(sizeof * cp, PERM);
	*cp = src;
	p->uses = append(cp, p->uses);
}

/* findtype - find type ty in identifiers */
/*identifiers中搜索类型ty的符号,返回该符号的指针,条件(p->sym.sclass == TYPEDEF)*/
Symbol findtype(Type ty) {
	Table tp = identifiers;
	int i;
	struct entry* p;

	assert(tp);
	do
		for (i = 0; i < HASHSIZE; i++)
			for (p = tp->buckets[i]; p; p = p->link)
				if (p->sym.type == ty && p->sym.sclass == TYPEDEF)
					return &p->sym;
	while ((tp = tp->previous) != NULL);
	return NULL;
}

/* mkstr - make a string constant */
/*mkstr - 生成字符串常量,返回该symbol指针*/
Symbol mkstr(char* str) {
	Value v;
	Symbol p;

	v.p = str;
	p = constant(array(chartype, strlen((char*)v.p) + 1, 0), v);
	if (p->u.c.loc == NULL)
		p->u.c.loc = genident(STATIC, p->type, GLOBAL);
	return p;
}

/* mksymbol - make a symbol for name, install in &globals if sclass==EXTERN */
/* mksymbol - 为名称制作一个符号，如果sclass==EXTERN，则安装在globals中,同时通知编译后端,sclass为扩展存储类型,name为名称,ty为类型,返回该symbol指针 */
Symbol mksymbol(int sclass, const char* name, Type ty) {
	Symbol p;

	if (sclass == EXTERN)
		p = install(string(name), &globals, GLOBAL, PERM);
	else {
		//NEW0(p, PERM);
		memset(p = (Symbol) allocate(sizeof *p, PERM), 0, sizeof *p);
		p->name = string(name);
		p->scope = GLOBAL;
	}
	p->sclass = sclass;
	p->type = ty;
	(*IR->_defsymbol)(p);
	p->defined = 1;  //通知完后端之后defined标志置1
	return p;
}

/* vtoa - return string for the constant v of type ty */
/*给类型ty和值v生成相应的字符串*/
char* vtoa(Type ty, Value v) {
	ty = unqual(ty);
	switch (ty->op) {
	case _INT:      return stringd(v.i);
	case _UNSIGNED: return stringf((v.u & ~0x7FFF) ? "0x%X" : "%U", v.u);
	case _FLOAT:    return stringf("%g", (double)v.d);
	case _ARRAY:
		if (ty->type == chartype || ty->type == signedchar
			|| ty->type == unsignedchar)
			return (char*)v.p;
		return stringf("%p", v.p);
	case _POINTER:  return stringf("%p", v.p);
	case _FUNCTION: return stringf("%p", v.g);
	}
	assert(0); return NULL;
}

