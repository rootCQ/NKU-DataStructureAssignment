#pragma once
#include"PairNode.h"
#include<iostream>
using namespace std;

template<class E, class K>
class SortedChain {
public:
	SortedChain() {
		head = new PairNode<K, E>;
		tail = new PairNode<K, E>;
		head->next = tail;
		head->before = NULL;
		tail->next = NULL;
		tail = NULL;
	}
	~SortedChain() {
		delete head;
		delete tail;
	}
	bool DistrictSearch(K k, E e) {
		PairNode<K, E>* cur = head;
		while (cur != NULL && cur->ele != e) {
			cur = cur->next;
		}
		if (cur != NULL && cur->ele == e) {
			return true;
		}
		return false;
	}
	void DistrictInsert(E e) {
		PairNode<K, E>* cur = head;
		PairNode<K, E>* add = new PairNode<K, E>(e);
		while (cur->next != tail) {
			cur = cur->next;
		}
		add->next = cur->next;
		add->before = cur;
		cur->next = add;

	}
	void DistrictDelete(K k, E e) {
		PairNode<K, E>* cur = head;
		while (cur != NULL && cur->ele != e) {
			cur = cur->next;
		}
		if (cur == NULL) {
			cout << "No element to delete!" << endl;
		}
		if (cur->ele == e) {
			cur->before->next = cur->next;
			if (cur->next != tail) {
				cur->next->before = cur->before;
			}		
			delete cur;
		}
	}
	void DistrictOutput() {
		PairNode<K, E>* cur = head->next->next;
		while (cur != tail) {
			cout << cur->ele << " ";
			cur = cur->next;
		}
	}

	PairNode<E, K>* head;
	PairNode<E, K>* tail;
};