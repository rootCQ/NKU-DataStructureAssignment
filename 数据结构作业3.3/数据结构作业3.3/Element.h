#pragma once
#include<iostream>
using namespace std;

template<class T>
class Ele {
public:
	int col, row;
	T value;
	Ele<T> *next;
	Ele<T> *before;
	Ele() {};
	Ele(int r, int c, T data) {
		row = r;
		col = c;
		value = data;
	}
};