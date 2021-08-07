#pragma once
#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class extendChain {
public:
	Node<T> *head;
	int length;

	extendChain() {
		head = new Node<T>;
		head->next = head;
		head->before = head;
	};

	void build() {//有问题
		T imput;
		int len;
		cin >> len;
		for (int i = 0; i <= len - 1; i++) {
			cin >> imput;
			this->insert(imput, this->head);
		}
	}

	void insert(T data, Node<T> *inser) {  //插入数据(放到前面)，位置
		Node<T> *inserdata = new Node<T>(data);
		if (length == 0) {
			head->next = inserdata;
			head->before = inserdata;
			inserdata->before = head;
			inserdata->next = head;
		}
		else if (length == 1) {
			inserdata->next = head;
			head->next->next = inserdata;
			inserdata->before = head->next;
			head->before = inserdata;
		}
		else {
			Node<T> *t = inser->before;
			inserdata->before = t;
			inserdata->next = inser;
			inser->before = inserdata;
			t->next = inserdata;
		}
		length++;
	};

	void delet(Node<T> *del) {
		del->before->next = del->next;
		del->next->before = del->before;
		delete del;
	}

	void showchain() {
		Node<T> *cur;
		cur = this->head->next;
		while (cur != head) {
			cout << cur->data << " ";
			cur = cur->next;
		}
	};

	void split() {
		Node<T> *curp;
		extendChain<T> *b=new extendChain<T>;
		curp = this->head->next;
		while (curp->next!=this->head && curp!=this->head)
		{
			curp = curp->next;
			b->insert(curp->data, b->head);
			Node<T> *tmp = new Node<T>;
			tmp = curp;
			curp = curp->next;
			this->delet(tmp);
		}
		cout << "由原链表拆分的链表为：";
		this->showchain();
		cout << endl;
		cout << "新生成的链表为：";
		b->showchain();
	}
};