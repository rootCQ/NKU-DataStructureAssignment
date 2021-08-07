#include"extendChain.h"
using namespace std;


template<class T>
void melt(extendChain<T> *a, extendChain<T> *b) {
	extendChain<T> *c = new extendChain<T>;
	Node<T> *curpa, *curpb;
	curpa = a->head;
	curpb = b->head;
	while (curpa->next != a->head && curpb->next != b->head)
	{
		c->insert(curpa->next->data, c->head);
		c->insert(curpb->next->data, c->head);
		curpa = curpa->next;
		curpb = curpb->next;
	}
	if (curpa->next == a->head) {
		while (curpb->next != b->head)
		{
			c->insert(curpb->next->data, c->head);//!!!!
			curpb = curpb->next;
		}
	}
	if (curpb->next == b->head) {
		while (curpa->next != a->head)
		{
			c->insert(curpa->next->data, c->head);//!!!!
			curpa = curpa->next;
		}
	}
	cout << "融合的链表c为：";
	c->showchain();
}

template<class T>
void split(extendChain<T> *c) {
	extendChain<T> *a = new extendChain<T>;
	extendChain<T> *b = new extendChain<T>;
	Node<T> *curpc;
	curpc = c->head->next;
	while (curpc->next != c->head && curpc != c->head)
	{
		a->insert(curpc->data, a->head);
		b->insert(curpc->next->data, b->head);
		curpc = curpc->next->next;
	}
	a->insert(curpc->data, a->head);
	cout << "奇数位置组成的链表为：";
	a->showchain();
	cout << endl;
	cout << "偶数位置组成的链表为：";
	b->showchain();
}

template<class fod>
void test(char number) {
	//第17题
	if (number == 'A' || number == 'a') {
		extendChain<fod> *chain1 = new extendChain<fod>;
		extendChain<fod> *chain2 = new extendChain<fod>;
		cout << "请依次输入第一条链的元素个数和元素" << endl;
		chain1->build();
		cout << "请依次输入第二条链的元素个数和元素" << endl;
		chain2->build();
		melt(chain1, chain2);
	}
	//第21题
	if (number == 'B' || number == 'b') {
		extendChain<fod> *chain = new extendChain<fod>;
		cout << "请依次输入链表的元素个数和元素" << endl;
		chain->build();
		split(chain);
	}
	//第22题
	if (number == 'C' || number == 'c') {
		extendChain<fod> *chain = new extendChain<fod>;
		cout << "请依次输入链表的元素个数和元素" << endl;
		chain->build();
		chain->split();
	}
}