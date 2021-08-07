#pragma once
#include<iostream>
using namespace std;

template<class K,class E>
class PairNode {
public:
	E ele;
	PairNode<K, E>* next;
	PairNode<K, E>* before;

	PairNode<K,E>() {
		next = NULL;
	}
	PairNode<K, E>(E e) {
		next = NULL;
		ele = e;
	}
};