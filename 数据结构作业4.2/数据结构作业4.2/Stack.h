#pragma once
#include"Node.h"
#include<iostream>
using namespace std;

template<class T>
class Stack {
public:
	Node<T> *top;
public:
	Stack();
	bool isempt();
	Stack* push(T a);
	Stack* pop();
	T topdata();
};

template<class T>
Stack<T>::Stack() {
	top = 0;
}

template<class T>
Stack<T>* Stack<T>::push(T a) {
	Node<T> *p = new Node<T>;
	p->data = a;
	p->next = top;
	top = p;
	return this;
}

template<class T>
Stack<T>* Stack<T>::pop() {
	Node<T> *p = top;
	top = top->next;
	delete p;
	return this;
}

template<class T>
bool Stack<T>::isempt() {
	return top == 0;
}

template<class T>
T Stack<T>::topdata() {
	return top->data;
}