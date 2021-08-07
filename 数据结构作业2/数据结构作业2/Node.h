#pragma once
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node<T> *next;
	Node<T> *before;
	Node() {};
	Node(T num) {
		data = num;
	};
};