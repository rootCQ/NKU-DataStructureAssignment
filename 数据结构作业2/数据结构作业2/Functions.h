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
	cout << "�ںϵ�����cΪ��";
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
	cout << "����λ����ɵ�����Ϊ��";
	a->showchain();
	cout << endl;
	cout << "ż��λ����ɵ�����Ϊ��";
	b->showchain();
}

template<class fod>
void test(char number) {
	//��17��
	if (number == 'A' || number == 'a') {
		extendChain<fod> *chain1 = new extendChain<fod>;
		extendChain<fod> *chain2 = new extendChain<fod>;
		cout << "�����������һ������Ԫ�ظ�����Ԫ��" << endl;
		chain1->build();
		cout << "����������ڶ�������Ԫ�ظ�����Ԫ��" << endl;
		chain2->build();
		melt(chain1, chain2);
	}
	//��21��
	if (number == 'B' || number == 'b') {
		extendChain<fod> *chain = new extendChain<fod>;
		cout << "���������������Ԫ�ظ�����Ԫ��" << endl;
		chain->build();
		split(chain);
	}
	//��22��
	if (number == 'C' || number == 'c') {
		extendChain<fod> *chain = new extendChain<fod>;
		cout << "���������������Ԫ�ظ�����Ԫ��" << endl;
		chain->build();
		chain->split();
	}
}