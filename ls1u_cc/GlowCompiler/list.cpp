#include "c.h"

static char rcsid[] = "$Id$";

static List freenodes;		/* free list nodes *//*�����б�ڵ�*/

void list_init(void)
{
	freenodes = 0;;
}

/* append - append x to list, return new list */
/*append-��x׷�ӵ��б��������б�*/
List append(void* x, List list) {
	List _new;

	if ((_new = freenodes) != NULL)
		freenodes = freenodes->link;
	else
		//NEW(_new, PERM);
	    _new = (List) allocate(sizeof * _new, PERM);
	if (list) {
		_new->link = list->link;
		list->link = _new;
	}
	else
		_new->link = _new;
	_new->x = x;
	return _new;
}

/* length - # elements in list */
/*�б�Ԫ�ظ���*/
int length(List list) {
	int n = 0;

	if (list) {
		List lp = list;
		do
			n++;
		while ((lp = lp->link) != list);
	}
	return n;
}

/* ltov - convert list to an NULL-terminated vector allocated in arena */
/*ltov-���б�ת��Ϊarena�з������NULL��β������*/
void* ltov(List* list, unsigned arena) {
	int i = 0;
	void** array = (void**)newarray(length(*list) + 1, sizeof array[0], arena);

	if (*list) {
		List lp = *list;
		do {
			lp = lp->link;
			array[i++] = lp->x;
		} while (lp != *list);
#ifndef PURIFY
		lp = (*list)->link;
		(*list)->link = freenodes;
		freenodes = lp;
#endif
	}
	*list = NULL;
	array[i] = NULL;
	return array;
}