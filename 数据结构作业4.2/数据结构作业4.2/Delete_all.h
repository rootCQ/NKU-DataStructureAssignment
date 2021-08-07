#pragma once
#include"Stack.h"
#include<iostream>
using namespace std;

template<class T>
void delete_all(Stack<T>* sta , const T &x) {
	Stack<T>* another = new Stack<T>;
	while (!sta->isempt())
	{
		if (sta->top->data == x) {
			sta->pop();
		}
		else{
			if (sta->top->next != 0) {
				cout << sta->top->data << " ";
			}
			else {
				cout << sta->top->data << endl;
			}
			sta->pop();
			if (sta->top != 0) {
				another->push(sta->top->data);
			}
		}
	}
}