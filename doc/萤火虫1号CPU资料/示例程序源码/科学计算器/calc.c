/**********************************************/
/*
/*			科学计算器		2022.10 龙少
/*
/**********************************************/

#include "calc.h"
#include "math.h"
#include "stdlib.h"
#include "string.h"

/* 内存分配区大小 */
#define MemAllocBufSize	4096

static unsigned char DegRad;
static unsigned short MemAllocCp;
static char MemAllocBuf[MemAllocBufSize];

typedef enum {
	BRACE, ADD, SUB, MUL, DIV, POW, LN, LOG, SIN, COS, TAN, ASIN, ACOS, ATAN, SQRT, POSI, MINUS, NUM
} OpSym;

typedef struct node* Node;

typedef struct node {
	OpSym op;
	double value;
	Node back;
	Node l;
	Node r;
};

/* 分配内存 */
static void* Memalloc(unsigned short size) {
	void* p;

	if (MemAllocCp + size > (unsigned short)MemAllocBufSize)
		return 0;
	p = &MemAllocBuf[MemAllocCp];
	MemAllocCp += size;
	return p;
}

/* 生成新节点 */
static Node NewNode(OpSym op, double value, Node back, Node l, Node r) {
	Node p;

	p = Memalloc(sizeof(*p));
	if (p == 0)
		return 0;
	p->op = op;
	p->value = value;
	p->back = back;
	p->l = l;
	p->r = r;
	return p;
}

/* 插入双目运算符节点 */
static Node InsNode(Node CurrentNode, OpSym op, OpSym prior) {
	Node p;

	for (; CurrentNode->back != 0 && CurrentNode->back->op >= prior; CurrentNode = CurrentNode->back)
		;
	p = NewNode(op, 0, CurrentNode->back, CurrentNode, 0);
	if (CurrentNode->back != 0)
		CurrentNode->back->r = p;
	CurrentNode->back = p;
	return p;
}

/* 处理树 */
static double DeclTree(Node p) {
	if (p != 0) {
		switch (p->op) {
		case ADD: return DeclTree(p->l) + DeclTree(p->r);
		case SUB: return DeclTree(p->l) - DeclTree(p->r);
		case MUL: return DeclTree(p->l) * DeclTree(p->r);
		case DIV: return DeclTree(p->l) / DeclTree(p->r);
		case LN: return log(DeclTree(p->r));
		case LOG: return log10(DeclTree(p->r));
		case SIN: return sin(DeclTree(p->r) / (DegRad == (unsigned char)1 ? (180.0 / M_PI) : 1.0));
		case COS: return cos(DeclTree(p->r) / (DegRad == (unsigned char)1 ? (180.0 / M_PI) : 1.0));
		case TAN: return tan(DeclTree(p->r) / (DegRad == (unsigned char)1 ? (180.0 / M_PI) : 1.0));
		case ASIN: return asin(DeclTree(p->r)) * (DegRad == (unsigned char)1 ? (180.0 / M_PI) : 1.0);
		case ACOS: return acos(DeclTree(p->r)) * (DegRad == (unsigned char)1 ? (180.0 / M_PI) : 1.0);
		case ATAN: return atan(DeclTree(p->r)) * (DegRad == (unsigned char)1 ? (180.0 / M_PI) : 1.0);
		case SQRT: return sqrt(DeclTree(p->r));
		case POW: return pow(DeclTree(p->l), DeclTree(p->r));
		case POSI: return DeclTree(p->r);
		case MINUS: return -DeclTree(p->r);
		case NUM: return p->value;
		}
	}
	return 0.0;
}

#define NumLen 32

/* 处理表达式,str输入表达式字符串,Deg:mode=1,Rad:mode=0,返回值为计算结果 */
double DealExpr(char* str, unsigned char mode) {
	unsigned char BraceCount = 0;
	double Error;
	Node CurrentNode = 0;
	Node p;

	DegRad = mode;
	*((long long*)&Error) = 0x7ff8000000000000;
	MemAllocCp = 0;

	while (*str) {
		if ((unsigned char)(*str - (char)'0') < (unsigned char)10 || *str == (char)'.') {
			char buf[NumLen];
			unsigned char i;
			unsigned char PointCount = 0;
			unsigned char eCount = 0;

			for (i = 0; (unsigned char)(str[i] - (char)'0') < (unsigned char)10 || str[i] == (char)'.'; ++i) {
				if (i == (unsigned char)NumLen || (str[i] == (char)'.' && ++PointCount > (unsigned char)1))
					return Error;
			label_0:
				buf[i] = str[i];
			}
			if ((str[i] == (char)'e' || str[i] == (char)'E') && (str[i + 1] == (char)'+' || str[i + 1] == (char)'-')) {
				buf[i] = str[i]; ++i;
				if (i == (unsigned char)NumLen || ++eCount > (unsigned char)1)
					return Error;
				buf[i] = str[i]; ++i;
				if((unsigned char)(str[i] - (char)'0') > (unsigned char)9)
					return Error;
				goto label_0;
			}
			buf[i] = 0;
			p = NewNode(NUM, atof(buf), CurrentNode, 0, 0);
			str += i;
		label_1:
			if (CurrentNode != 0)
				CurrentNode->r = p;
			CurrentNode = p;
		} else if (*str == (char)'(') {
			if(++BraceCount == (unsigned char)0)
				return Error;
			p = NewNode(BRACE, 0, CurrentNode, 0, 0);
			++str;
			goto label_1;
		} else if (*str == (char)')') {
			if (BraceCount-- == (unsigned char)0)
				return Error;
			for (; CurrentNode->op != BRACE; CurrentNode = CurrentNode->back)
				;
			CurrentNode->r->back = CurrentNode->back;
			*CurrentNode = *CurrentNode->r;
			++str;
		} else if (*str == (char)'+' || *str == (char)'-') {
			if (CurrentNode != 0 && (CurrentNode->op == NUM || CurrentNode->r != 0))
				CurrentNode = InsNode(CurrentNode, *str++ == (char)'+' ? ADD : SUB, ADD);
			else {
				p = NewNode(*str++ == (char)'+' ? POSI : MINUS, 0, CurrentNode, 0, 0);
				goto label_1;
			}
		} else if (*str == (char)'*' || *str == (char)'/') {
			if (CurrentNode != 0 && (CurrentNode->op == NUM || CurrentNode->r != 0))
				CurrentNode = InsNode(CurrentNode, *str++ == (char)'*' ? MUL : DIV, MUL);
			else
				return Error;
		} else if (*str == (char)'^') {
			if (CurrentNode != 0 && (CurrentNode->op == NUM || CurrentNode->r != 0))
				CurrentNode = InsNode(CurrentNode, POW, POW);
			else
				return Error;
			++str;
		} else if (strncmp(str, "ln", 2) == 0) {
			p = NewNode(LN, 0, CurrentNode, 0, 0);
			str += 2;
			goto label_1;
		} else if (strncmp(str, "log", 3) == 0) {
			p = NewNode(LOG, 0, CurrentNode, 0, 0);
			str += 3;
			goto label_1;
		} else if (strncmp(str, "sin", 3) == 0) {
			p = NewNode(SIN, 0, CurrentNode, 0, 0);
			str += 3;
			goto label_1;
		} else if (strncmp(str, "cos", 3) == 0) {
			p = NewNode(COS, 0, CurrentNode, 0, 0);
			str += 3;
			goto label_1;
		} else if (strncmp(str, "tan", 3) == 0) {
			p = NewNode(TAN, 0, CurrentNode, 0, 0);
			str += 3;
			goto label_1;
		} else if (strncmp(str, "asin", 4) == 0) {
			p = NewNode(ASIN, 0, CurrentNode, 0, 0);
			str += 4;
			goto label_1;
		} else if (strncmp(str, "acos", 4) == 0) {
			p = NewNode(ACOS, 0, CurrentNode, 0, 0);
			str += 4;
			goto label_1;
		} else if (strncmp(str, "atan", 4) == 0) {
			p = NewNode(ATAN, 0, CurrentNode, 0, 0);
			str += 4;
			goto label_1;
		} else if (strncmp(str, "sqrt", 4) == 0) {
			p = NewNode(SQRT, 0, CurrentNode, 0, 0);
			str += 4;
			goto label_1;
		} else
			return Error;
		if (CurrentNode == 0)
			return Error;
	}
	if (BraceCount > (unsigned char)0)
		return Error;
	for (; CurrentNode->back != 0; CurrentNode = CurrentNode->back)
		;
	return DeclTree(CurrentNode);
}
