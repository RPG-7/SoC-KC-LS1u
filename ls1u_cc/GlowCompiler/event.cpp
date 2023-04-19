#include "c.h"

static char rcsid[] = "$Id$";

struct entry {
	Apply func;
	void* cl;
};

Events events;

void event_init(void)
{
	events = {0,0,0,0,0,0,0,0};
}

void attach(Apply func, void* cl, List* list) {
	struct entry* p;

	//
	(p, PERM);
	p = (entry*)allocate(sizeof * p, PERM);

	p->func = func;
	p->cl = cl;
	*list = append(p, *list);
}
void apply(List event, void* arg1, void* arg2) {
	if (event) {
		List lp = event;
		do {
			struct entry* p = (entry*)lp->x;
			(*p->func)(p->cl, arg1, arg2);
			lp = lp->link;
		} while (lp != event);
	}
}

