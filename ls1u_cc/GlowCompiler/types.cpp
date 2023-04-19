#include "c.h"
#include <float.h> //C标准库

static char rcsid[] = "$Id$";

static Field isfield(const char*, Field);
static Type type(int, Type, int, int, void*);

/*类型表*/
static struct entry {
	struct type type;
	struct entry* link;  //指向下个类型表
} *typetable[128]; //类型表哈希链入口指针

static int maxlevel;

static Symbol pointersym;

Type chartype;			/* char */
Type doubletype;		/* double */
Type floattype;			/* float */
Type inttype;			/* signed int */
Type longdouble;		/* long double */
Type longtype;			/* long */
Type longlong;			/* long long */
Type shorttype;			/* signed short int */
Type signedchar;		/* signed char */
Type unsignedchar;		/* unsigned char */
Type unsignedlong;		/* unsigned long int */
Type unsignedlonglong;		/* unsigned long long int */
Type unsignedshort;		/* unsigned short int */
Type unsignedtype;		/* unsigned int */
Type funcptype;			/* void (*)() */
Type charptype;			/* char* */
Type voidptype;			/* void* */
Type voidtype;			/* basic types: void */
Type unsignedptr;		/* unsigned type to hold void* */
Type signedptr;			/* signed type to hold void* */
Type widechar;			/* unsigned type that represents wchar_t */

static unsigned mark;

static Type xxinit(int op, char* name, Metrics m) {

	Symbol p = install(string(name), &types, GLOBAL, PERM);
	Type ty = type(op, 0, m.size, m.align, p);

	assert(ty->align == 0 || ty->size % ty->align == 0);
	p->type = ty;
	p->addressed = m.outofline;
	switch (ty->op) {
	case _INT:
		p->u.limits.max.i = ones(8 * ty->size) >> 1;
		p->u.limits.min.i = -p->u.limits.max.i - 1;
		break;
	case _UNSIGNED:
		p->u.limits.max.u = ones(8 * ty->size);
		p->u.limits.min.u = 0;
		break;
	case _FLOAT:
		if (ty->size == sizeof(float))
			p->u.limits.max.d = FLT_MAX;
		else if (ty->size == sizeof(double))
			p->u.limits.max.d = DBL_MAX;
		else
			p->u.limits.max.d = LDBL_MAX;
		p->u.limits.min.d = -p->u.limits.max.d;
		break;
	default: assert(0);
	}
	return ty;
}

/*搜索类型表,找到则返回该类型表指针,否则创建该类型表,返回该类型表指针,所有参数都为比较参数或创建参数*/
static Type type(int op, Type ty, int size, int align, void* sym) {
	unsigned h = (op ^ ((unsigned long)ty >> 3))
		& (NELEMS(typetable) - 1);  //截尾8位哈希值
	struct entry* tn;

	if (op != _FUNCTION && (op != _ARRAY || size > 0))  //op不是函数并且不是size为0的数组
		for (tn = typetable[h]; tn; tn = tn->link)
			if (tn->type.op == op && tn->type.type == ty
				&& tn->type.size == size && tn->type.align == align
				&& tn->type.u.sym == sym)
				return &tn->type;
	//NEW0(tn, PERM);
	memset(tn = (entry*)allocate(sizeof * tn, PERM), 0, sizeof * tn);
	tn->type.op = op;
	tn->type.type = ty;
	tn->type.size = size;
	tn->type.align = align;
	tn->type.u.sym = (Symbol)sym;
	tn->link = typetable[h];
	typetable[h] = tn;
	return &tn->type;
}

void type_init(int argc, char* argv[]) {
	//static int inited;
	int i;
	/*
	if (inited)
		return;
	inited = 1;
	if (!IR)
		return;
		*/

	/*初始化变量值*/
	maxlevel = 0;
	mark = 0;
	for (i = 0; i < 128; ++i)
		typetable[i] = 0;

	chartype = NULL;			/* char */
	doubletype = NULL;		/* double */
	floattype = NULL;			/* float */
	inttype = NULL;			/* signed int */
	longdouble = NULL;		/* long double */
	longtype = NULL;			/* long */
	longlong = NULL;			/* long long */
	shorttype = NULL;			/* signed short int */
	signedchar = NULL;		/* signed char */
	unsignedchar = NULL;		/* unsigned char */
	unsignedlong = NULL;		/* unsigned long int */
	unsignedlonglong = NULL;		/* unsigned long long int */
	unsignedshort = NULL;		/* unsigned short int */
	unsignedtype = NULL;		/* unsigned int */
	funcptype = NULL;			/* void (*)() */
	charptype = NULL;			/* char* */
	voidptype = NULL;			/* void* */
	voidtype = NULL;			/* basic types: void */
	unsignedptr = NULL;		/* unsigned type to hold void* */
	signedptr = NULL;			/* signed type to hold void* */
	widechar = NULL;			/* unsigned type that represents wchar_t */

//////////////////////////////////////初始化IR///////////////////////////////////////

	for (i = 1; i < argc; i++) {
		int size, align, outofline;
		if (strncmp(argv[i], "-unsigned_char=", 15) == 0)
			IR->unsigned_char = argv[i][15] - '0';
#define xx(name) \
		else if (sscanf(argv[i], "-" #name "=%d,%d,%d", &size, &align, &outofline) == 3) { \
			IR->name.size = size; IR->name.align = align; \
			IR->name.outofline = outofline; }
		xx(charmetric)
			xx(shortmetric)
			xx(intmetric)
			xx(longmetric)
			xx(longlongmetric)
			xx(floatmetric)
			xx(doublemetric)
			xx(longdoublemetric)
			xx(ptrmetric)
			xx(structmetric)
#undef xx
	}

//////////////////////////////////////初始化整形和浮点类型///////////////////////////////////////

#define xx(v,name,op,metrics) v=xxinit(op,name,IR->metrics)
	xx(chartype, "char", IR->unsigned_char ? _UNSIGNED : _INT, charmetric);
	xx(doubletype, "double", _FLOAT, doublemetric);
	xx(floattype, "float", _FLOAT, floatmetric);
	xx(inttype, "int", _INT, intmetric);
	xx(longdouble, "long double", _FLOAT, longdoublemetric);
	xx(longtype, "long int", _INT, longmetric);
	xx(longlong, "long long int", _INT, longlongmetric);
	xx(shorttype, "short", _INT, shortmetric);
	xx(signedchar, "signed char", _INT, charmetric);
	xx(unsignedchar, "unsigned char", _UNSIGNED, charmetric);
	xx(unsignedlong, "unsigned long", _UNSIGNED, longmetric);
	xx(unsignedshort, "unsigned short", _UNSIGNED, shortmetric);
	xx(unsignedtype, "unsigned int", _UNSIGNED, intmetric);
	xx(unsignedlonglong, "unsigned long long", _UNSIGNED, longlongmetric);
#undef xx

//////////////////////////////////////初始化空类型///////////////////////////////////////

	{
		Symbol p;

		p = install(string("void"), &types, GLOBAL, PERM);
		voidtype = type(_VOID, NULL, 0, 0, p);
		p->type = voidtype;
	}

//////////////////////////////////////初始化指针类型///////////////////////////////////////

	pointersym = install(string("T*"), &types, GLOBAL, PERM);
	pointersym->addressed = IR->ptrmetric.outofline;
	pointersym->u.limits.max.p = (void*)ones(8 * IR->ptrmetric.size);
	pointersym->u.limits.min.p = 0;

	voidptype = ptr(voidtype);
	funcptype = ptr(func(voidtype, NULL, 1));
	charptype = ptr(chartype);

//////////////////////////////////////////////////////////////////////////////////////////

#define xx(v,t) if (v==NULL && t->size==voidptype->size && t->align==voidptype->align) v=t
	xx(unsignedptr, unsignedshort);
	xx(unsignedptr, unsignedtype);
	xx(unsignedptr, unsignedlong);
	xx(unsignedptr, unsignedlonglong);
	if (unsignedptr == NULL)
		unsignedptr = type(_UNSIGNED, NULL, voidptype->size, voidptype->align, voidptype->u.sym);
	xx(signedptr, shorttype);
	xx(signedptr, inttype);
	xx(signedptr, longtype);
	xx(signedptr, longlong);
	if (signedptr == NULL)
		signedptr = type(_INT, NULL, voidptype->size, voidptype->align, voidptype->u.sym);
#undef xx
	widechar = unsignedshort;
	for (i = 0; i < argc; i++) {
#define xx(name,type) \
		if (strcmp(argv[i], "-wchar_t=" #name) == 0) \
			widechar = type;
		xx(unsigned_char, unsignedchar)
			xx(unsigned_int, unsignedtype)
			xx(unsigned_short, unsignedshort)
	}
#undef xx
}

/*从typrtable中删除那些type.u.sym->scope >= lev的类型*/
void rmtypes(int lev) {
	if (maxlevel >= lev) {
		int i;
		maxlevel = 0;
		for (i = 0; i < NELEMS(typetable); i++) {
			struct entry* tn, ** tq = &typetable[i];
			while ((tn = *tq) != NULL)
				if (tn->type.op == _FUNCTION)
					tq = &tn->link;

				else if (tn->type.u.sym && tn->type.u.sym->scope >= lev)
					*tq = tn->link;
				else {
					if (tn->type.u.sym && tn->type.u.sym->scope > maxlevel)
						maxlevel = tn->type.u.sym->scope;
					tq = &tn->link;
				}

		}
	}
}

/*搜索或创建_POINTER类型表,返回该类型表指针,ty为类型的type域*/
Type ptr(Type ty) {
	return type(_POINTER, ty, IR->ptrmetric.size,
		IR->ptrmetric.align, pointersym);
}

/*指针类型返回ty->type*/
Type deref(Type ty) {
	if (isptr(ty))
		ty = ty->type;
	else
		error("type error: %s\n", "pointer expected");
	return isenum(ty) ? unqual(ty)->type : ty;
}

/*创建_ARRAY类型,返回该类型指针,ty为成员类型,n为成员数,a为对齐字节*/
Type array(Type ty, int n, int a) {
	assert(ty);
	if (isfunc(ty)) {
		error("illegal type `array of %t'\n", ty);
		return array(inttype, n, 0);
	}
	if (isarray(ty) && ty->size == 0)
		error("missing array size\n");
	if (ty->size == 0) {
		if (unqual(ty) == voidtype)
			error("illegal type `array of %t'\n", ty);
		else if (Aflag >= 2)
			warning("declaring type array of %t' is undefined\n", ty);

	}
	else if (n > INT_MAX / ty->size) {
		error("size of `array of %t' exceeds %d bytes\n",
			ty, INT_MAX);
		n = 1;
	}
	return type(_ARRAY, ty, n * ty->size,
		a ? a : ty->align, NULL);
}
/*_ARRAY类型转_POINTER类型*/
Type atop(Type ty) {
	if (isarray(ty))
		return ptr(ty->type);
	error("type error: %s\n", "array expected");
	return ptr(ty);
}
Type qual(int op, Type ty) {
	if (isarray(ty))
		ty = type(_ARRAY, qual(op, ty->type), ty->size,
			ty->align, NULL);
	else if (isfunc(ty))
		warning("qualified function type ignored\n");
	else if (isconst(ty) && op == _CONST
		|| isvolatile(ty) && op == _VOLATILE)
		error("illegal type `%k %t'\n", op, ty);
	else {
		if (isqual(ty)) {
			op += ty->op;
			ty = ty->type;
		}
		ty = type(op, ty, ty->size, ty->align, NULL);
	}
	return ty;
}

/*创建_FUNCTION类型,返回该类型指针,ty为类型的type域，proto为u.f.proto域，style为u.f.oldstyle域*/
Type func(Type ty, Type* proto, int style) {
	if (ty && (isarray(ty) || isfunc(ty)))
		error("illegal return type `%t'\n", ty);
	ty = type(_FUNCTION, ty, 0, 0, NULL);
	ty->u.f.proto = proto;
	ty->u.f.oldstyle = style;
	return ty;
}
/*函数类型返回ty->type*/
Type freturn(Type ty) {
	if (isfunc(ty))
		return ty->type;
	error("type error: %s\n", "function expected");
	return inttype;
}

/*查找函数原形的末尾是否有void类型,测试函数是否带可变参数列表,返回非0表示有void类型*/
int variadic(Type ty) {
	if (isfunc(ty) && ty->u.f.proto) {
		int i;
		for (i = 0; ty->u.f.proto[i]; i++)
			;
		return i > 1 && ty->u.f.proto[i - 1] == voidtype;
	}
	return 0;
}
/*创建新的类型(STRUCT["tag"])或(UNION["tag"]),返回该类型指针*/
Type newstruct(int op, char* tag) {
	Symbol p;

	assert(tag);
	if (*tag == 0)
		tag = stringd(genlabel(1));
	else
		if ((p = lookup(tag, types)) != NULL && (p->scope == level
			|| p->scope == PARAM && level == PARAM + 1)) {
			if (p->type->op == op && !p->defined)
				return p->type;
			error("redefinition of `%s' previously defined at %w\n",
				p->name, &p->src);
		}
	p = install(tag, &types, level, PERM);
	p->type = type(op, NULL, 0, 0, p);
	if (p->scope > maxlevel)
		maxlevel = p->scope;
	p->src = src;
	return p->type;
}
/*新建一个field结构,将该结构加入到ty->u.sym->u.s.flist指向的链表中,fty为新field结构的类型*/
Field newfield(char* name, Type ty, Type fty) {
	Field p, * q = &ty->u.sym->u.s.flist;

	if (name == NULL)
		name = stringd(genlabel(1));
	for (p = *q; p; q = &p->link, p = *q)
		if (p->name == name)
			error("duplicate field name `%s' in `%t'\n",
				name, ty);
	//NEW0(p, PERM);
	memset(p = (Field)allocate(sizeof * p, PERM), 0, sizeof * p);
	*q = p;
	p->name = name;
	p->type = fty;
	if (xref) {							/* omit */
		if (ty->u.sym->u.s.ftab == NULL)			/* omit */
			ty->u.sym->u.s.ftab = table(NULL, level);	/* omit */
		install(name, &ty->u.sym->u.s.ftab, 0, PERM)->src = src;/* omit */
	}								/* omit */
	return p;
}
/*类型检查,如果ty1和ty2兼容返回1,否则返回0,如果ty1和ty2是不完全类型则返回ret,149*/
int eqtype(Type ty1, Type ty2, int ret) {
	if (ty1 == ty2)
		return 1;
	if (ty1->op != ty2->op)
		return 0;
	switch (ty1->op) {
	case _ENUM: case _UNION: case _STRUCT:
	case _UNSIGNED: case _INT: case _FLOAT:
		return 0;
	case _POINTER:  return eqtype(ty1->type, ty2->type, 1);
	case _VOLATILE: case _CONST + _VOLATILE:
	case _CONST:    return eqtype(ty1->type, ty2->type, 1);
	case _ARRAY:    if (eqtype(ty1->type, ty2->type, 1)) {
		if (ty1->size == ty2->size)
			return 1;
		if (ty1->size == 0 || ty2->size == 0)
			return ret;
	}
			  return 0;
	case _FUNCTION: if (eqtype(ty1->type, ty2->type, 1)) {
		Type* p1 = ty1->u.f.proto, * p2 = ty2->u.f.proto;
		if (p1 == p2)
			return 1;
		if (p1 && p2) {
			for (; *p1 && *p2; p1++, p2++)
				if (eqtype(unqual(*p1), unqual(*p2), 1) == 0)
					return 0;
			if (*p1 == NULL && *p2 == NULL)
				return 1;
		}
		else {
			if (variadic(p1 ? ty1 : ty2))
				return 0;
			if (p1 == NULL)
				p1 = p2;
			for (; *p1; p1++) {
				Type ty = unqual(*p1);
				if (promote(ty) != (isenum(ty) ? ty->type : ty))
					return 0;
			}
			return 1;
		}
	}
				 return 0;
	}
	assert(0); return 0;
}
/*类型提升*/
Type promote(Type ty) {
	ty = unqual(ty);
	switch (ty->op) {
	case _ENUM:
		return inttype;
	case _INT:
		//if (ty->size < inttype->size) 修改
		//	return inttype;
		break;
	case _UNSIGNED:
		//if (ty->size < inttype->size) 修改
		//	return inttype;
		//if (ty->size < unsignedtype->size)
		//	return unsignedtype;
		break;
	case _FLOAT:
		if (ty->size < doubletype->size)
			return doubletype;
	}
	return ty;
}
Type signedint(Type ty) {
	if (ty->op == _INT)
		return ty;
	assert(ty->op == _UNSIGNED);
#define xx(t) if (ty->size == t->size) return t
	xx(chartype); //修改,增加此行
	xx(shorttype); //修改,增加此行
	xx(inttype);
	xx(longtype);
	xx(longlong);
#undef xx
	assert(0); return NULL;
}
/*ty1和ty2为兼容类型,返回复合类型*/
Type compose(Type ty1, Type ty2) {
	if (ty1 == ty2)
		return ty1;
	assert(ty1->op == ty2->op);
	switch (ty1->op) {
	case _POINTER:
		return ptr(compose(ty1->type, ty2->type));
	case _CONST + _VOLATILE:
		return qual(_CONST, qual(_VOLATILE,
			compose(ty1->type, ty2->type)));
	case _CONST: case _VOLATILE:
		return qual(ty1->op, compose(ty1->type, ty2->type));
	case _ARRAY: { Type ty = compose(ty1->type, ty2->type);
		if (ty1->size && (ty1->type->size && ty2->size == 0 || ty1->size == ty2->size))
			return array(ty, ty1->size / ty1->type->size, ty1->align);
		if (ty2->size && ty2->type->size && ty1->size == 0)
			return array(ty, ty2->size / ty2->type->size, ty2->align);
		return array(ty, 0, 0);    }
	case _FUNCTION: { Type* p1 = ty1->u.f.proto, * p2 = ty2->u.f.proto;
		Type ty = compose(ty1->type, ty2->type);
		List tlist = NULL;
		if (p1 == NULL && p2 == NULL)
			return func(ty, NULL, 1);
		if (p1 && p2 == NULL)
			return func(ty, p1, ty1->u.f.oldstyle);
		if (p2 && p1 == NULL)
			return func(ty, p2, ty2->u.f.oldstyle);
		for (; *p1 && *p2; p1++, p2++) {
			Type ty = compose(unqual(*p1), unqual(*p2));
			if (isconst(*p1) || isconst(*p2))
				ty = qual(_CONST, ty);
			if (isvolatile(*p1) || isvolatile(*p2))
				ty = qual(_VOLATILE, ty);
			tlist = append(ty, tlist);
		}
		assert(*p1 == NULL && *p2 == NULL);
		return func(ty, (Type*)ltov(&tlist, PERM), 0); }
	}
	assert(0); return NULL;
}
/*将类型映射为相应的类型后缀*/
int ttob(Type ty) {
	switch (ty->op) {
	case _CONST: case _VOLATILE: case _CONST + _VOLATILE:
		return ttob(ty->type);
	case _VOID: case _INT: case _UNSIGNED: case _FLOAT:
		return ty->op + sizeop(ty->size);
	case _POINTER:
		return _POINTER + sizeop(voidptype->size);
	case _FUNCTION:
		return _POINTER + sizeop(funcptype->size);
	case _ARRAY: case _STRUCT: case _UNION:
		return _STRUCT;
	case _ENUM:
		return _INT + sizeop(inttype->size);
	}
	assert(0); return _INT;
}
/*返回满足optype(op)并且满足size的类型*/
Type btot(int op, int size) {
#define xx(ty) if (size == (ty)->size) return ty;
	switch (optype(op)) {
	case F:
		xx(floattype);
		xx(doubletype);
		xx(longdouble);
		assert(0); return 0;
	case _I:
		if (chartype->op == _INT)
			xx(chartype);
		xx(signedchar);
		xx(shorttype);
		xx(inttype);
		xx(longtype);
		xx(longlong);
		assert(0); return 0;
	case U:
		if (chartype->op == _UNSIGNED)
			xx(chartype);
		xx(unsignedchar);
		xx(unsignedshort);
		xx(unsignedtype);
		xx(unsignedlong);
		xx(unsignedlonglong);
		assert(0); return 0;
	case P:
		xx(voidptype);
		xx(funcptype);
		assert(0); return 0;
	}
#undef xx
	assert(0); return 0;
}
int hasproto(Type ty) {
	if (ty == 0)
		return 1;
	switch (ty->op) {
	case _CONST: case _VOLATILE: case _CONST + _VOLATILE: case _POINTER:
	case _ARRAY:
		return hasproto(ty->type);
	case _FUNCTION:
		return hasproto(ty->type) && ty->u.f.proto;
	case _STRUCT: case _UNION:
	case _VOID:   case _FLOAT: case _ENUM:  case _INT: case _UNSIGNED:
		return 1;
	}
	assert(0); return 0;
}
/* fieldlist - construct a flat list of fields in type ty */
/*返回ty->u.sym->u.s.flist*/
Field fieldlist(Type ty) {
	return ty->u.sym->u.s.flist;
}
/*140*/
/* fieldref - find field name of type ty, return entry */
Field fieldref(const char* name, Type ty) {
	Field p = isfield(name, unqual(ty)->u.sym->u.s.flist);

	if (p && xref) {
		Symbol q;
		assert(unqual(ty)->u.sym->u.s.ftab);
		q = lookup(name, unqual(ty)->u.sym->u.s.ftab);
		assert(q);
		use(q, src);
	}
	return p;
}

/* ftype - return a function type for rty function (ty,...)' */
Type ftype(Type rty, ...) {
	va_list ap;
	Type ty = NULL;
	List list = NULL;
	
	va_start(ap, rty);
	ty = va_arg(ap, Type);
	for (; ty != NULL; ty = va_arg(ap, Type))
		list = append(ty, list);
	va_end(ap);
	return func(rty, (Type*)ltov(&list, PERM), 0);
	
}

/* isfield - if name is a field in flist, return pointer to the field structure */
/*在flist指向的Field链里搜索名为name的对象,并返回该对象的指针*/
static Field isfield(const char* name, Field flist) {
	for (; flist; flist = flist->link)
		if (flist->name == name)
			break;
	return flist;
}

/* outtype - output type ty */
void outtype(Type ty, FILE* f) {
	switch (ty->op) {
	case _CONST + _VOLATILE: case _CONST: case _VOLATILE:
		fprint(f, "%k %t", ty->op, ty->type);
		break;
	case _STRUCT: case _UNION: case _ENUM:
		assert(ty->u.sym);
		if (ty->size == 0)
			fprint(f, "incomplete ");
		assert(ty->u.sym->name);
		if (*ty->u.sym->name >= '1' && *ty->u.sym->name <= '9') {
			Symbol p = findtype(ty);
			if (p == 0)
				fprint(f, "%k defined at %w", ty->op, &ty->u.sym->src);
			else
				fprint(f, p->name);
		}
		else {
			fprint(f, "%k %s", ty->op, ty->u.sym->name);
			if (ty->size == 0)
				fprint(f, " defined at %w", &ty->u.sym->src);
		}
		break;
	case _VOID: case _FLOAT: case _INT: case _UNSIGNED:
		fprint(f, ty->u.sym->name);
		break;
	case _POINTER:
		fprint(f, "pointer to %t", ty->type);
		break;
	case _FUNCTION:
		fprint(f, "%t function", ty->type);
		if (ty->u.f.proto && ty->u.f.proto[0]) {
			int i;
			fprint(f, "(%t", ty->u.f.proto[0]);
			for (i = 1; ty->u.f.proto[i]; i++)
				if (ty->u.f.proto[i] == voidtype)
					fprint(f, ",...");
				else
					fprint(f, ",%t", ty->u.f.proto[i]);
			fprint(f, ")");
		}
		else if (ty->u.f.proto && ty->u.f.proto[0] == 0)
			fprint(f, "(void)");

		break;
	case _ARRAY:
		if (ty->size > 0 && ty->type && ty->type->size > 0) {
			fprint(f, "array %d", ty->size / ty->type->size);
			while (ty->type && isarray(ty->type) && ty->type->type->size > 0) {
				ty = ty->type;
				fprint(f, ",%d", ty->size / ty->type->size);
			}
		}
		else
			fprint(f, "incomplete array");
		if (ty->type)
			fprint(f, " of %t", ty->type);
		break;
	default: assert(0);
	}
}

/* printdecl - output a C declaration for symbol p of type ty */
void printdecl(Symbol p, Type ty) {
	switch (p->sclass) {
	case AUTO:
		fprint(stderr, "%s;\n", typestring(ty, p->name));
		break;
	case STATIC: case EXTERN:
		fprint(stderr, "%k %s;\n", p->sclass, typestring(ty, p->name));
		break;
	case TYPEDEF: case _ENUM:
		break;
	default: assert(0);
	}
}

/* printproto - output a prototype declaration for function p */
void printproto(Symbol p, Symbol callee[]) {
	if (p->type->u.f.proto)
		printdecl(p, p->type);
	else {
		int i;
		List list = 0;
		if (callee[0] == 0)
			list = append(voidtype, list);
		else
			for (i = 0; callee[i]; i++)
				list = append(callee[i]->type, list);
		printdecl(p, func(freturn(p->type), (Type*)ltov(&list, PERM), 0));
	}
	
}

/* prtype - print details of type ty on f with given indent */
static void prtype(Type ty, FILE* f, int indent, unsigned mark) {
	switch (ty->op) {
	default:
		fprint(f, "(%d %d %d [%p])", ty->op, ty->size, ty->align, ty->u.sym);
		break;
	case _FLOAT: case _INT: case _UNSIGNED: case _VOID:
		fprint(f, "(%k %d %d [\"%s\"])", ty->op, ty->size, ty->align, ty->u.sym->name);
		break;
	case _CONST + _VOLATILE: case _CONST: case _VOLATILE: case _POINTER: case _ARRAY:
		fprint(f, "(%k %d %d ", ty->op, ty->size, ty->align);
		prtype(ty->type, f, indent + 1, mark);
		fprint(f, ")");
		break;
	case _STRUCT: case _UNION:
		fprint(f, "(%k %d %d [\"%s\"]", ty->op, ty->size, ty->align, ty->u.sym->name);
		if (ty->x.marked != mark) {
			Field p;
			ty->x.marked = mark;
			for (p = ty->u.sym->u.s.flist; p; p = p->link) {
				fprint(f, "\n%I", indent + 1);
				prtype(p->type, f, indent + 1, mark);
				fprint(f, " %s@%d", p->name, p->offset);
				if (p->lsb)
					fprint(f, ":%d..%d",
						fieldsize(p) + fieldright(p), fieldright(p));
			}
			fprint(f, "\n%I", indent);
		}
		fprint(f, ")");
		break;
	case _ENUM:
		fprint(f, "(%k %d %d [\"%s\"]", ty->op, ty->size, ty->align, ty->u.sym->name);
		if (ty->x.marked != mark) {
			int i;
			Symbol* p = ty->u.sym->u.idlist;
			ty->x.marked = mark;
			for (i = 0; p[i] != NULL; i++)
				fprint(f, "%I%s=%d\n", indent + 1, p[i]->name, p[i]->u.value);
		}
		fprint(f, ")");
		break;
	case _FUNCTION:
		fprint(f, "(%k %d %d ", ty->op, ty->size, ty->align);
		prtype(ty->type, f, indent + 1, mark);
		if (ty->u.f.proto) {
			int i;
			fprint(f, "\n%I{", indent + 1);
			for (i = 0; ty->u.f.proto[i]; i++) {
				if (i > 0)
					fprint(f, "%I", indent + 2);
				prtype(ty->u.f.proto[i], f, indent + 2, mark);
				fprint(f, "\n");
			}
			fprint(f, "%I}", indent + 1);
		}
		fprint(f, ")");
		break;
	}
}

/* printtype - print details of type ty on fd */
void printtype(Type ty, int fd) {
	//static unsigned mark;
	prtype(ty, fd == 1 ? stdout : stderr, 0, ++mark);
	fprint(fd == 1 ? stdout : stderr, "\n");
}

/* typestring - return ty as C declaration for str, which may be "" */

char* typestring(Type ty, char* str) {
	for (; ty; ty = ty->type) {
		Symbol p;
		switch (ty->op) {
		case _CONST + _VOLATILE: case _CONST: case _VOLATILE:
			if (isptr(ty->type))
				str = stringf("%k %s", ty->op, str);
			else
				return stringf("%k %s", ty->op, typestring(ty->type, str));
			break;
		case _STRUCT: case _UNION: case _ENUM:
			assert(ty->u.sym);
			if ((p = findtype(ty)) != NULL)
				return *str ? stringf("%s %s", p->name, str) : p->name;
			if (*ty->u.sym->name >= '1' && *ty->u.sym->name <= '9')
				warning("unnamed %k in prototype\n", ty->op);
			if (*str)
				return stringf("%k %s %s", ty->op, ty->u.sym->name, str);
			else
				return stringf("%k %s", ty->op, ty->u.sym->name);
		case _VOID: case _FLOAT: case _INT: case _UNSIGNED:
			return *str ? stringf("%s %s", ty->u.sym->name, str) : ty->u.sym->name;
		case _POINTER:
			if (!ischar(ty->type) && (p = findtype(ty)) != NULL)
				return *str ? stringf("%s %s", p->name, str) : p->name;
			str = stringf(isarray(ty->type) || isfunc(ty->type) ? "(*%s)" : "*%s", str);
			break;
		case _FUNCTION:
			if ((p = findtype(ty)) != NULL)
				return *str ? stringf("%s %s", p->name, str) : p->name;
			if (ty->u.f.proto == 0)
				str = stringf("%s()", str);
			else if (ty->u.f.proto[0]) {
				int i;
				str = stringf("%s(%s", str, typestring(ty->u.f.proto[0], ""));
				for (i = 1; ty->u.f.proto[i]; i++)
					if (ty->u.f.proto[i] == voidtype)
						str = stringf("%s, ...", str);
					else
						str = stringf("%s, %s", str, typestring(ty->u.f.proto[i], ""));
				str = stringf("%s)", str);
			}
			else
				str = stringf("%s(void)", str);
			break;
		case _ARRAY:
			if ((p = findtype(ty)) != NULL)
				return *str ? stringf("%s %s", p->name, str) : p->name;
			if (ty->type && ty->type->size > 0)
				str = stringf("%s[%d]", str, ty->size / ty->type->size);
			else
				str = stringf("%s[]", str);
			break;
		default: assert(0);
		}
	}
	assert(0); return 0;
}
