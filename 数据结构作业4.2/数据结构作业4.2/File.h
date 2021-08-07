#pragma once
#include"Stack.h"
#include<iostream>
#include<fstream>
using namespace std;

template<class T>
T readtxt(Stack<T>* a) {
	ifstream infile;
	string file = "imput.txt";
	infile.open(file.data());
	char x;
	infile >> x;
	char stackdata;
	while (infile.peek() != EOF) {
		infile >> stackdata;
		a->push(stackdata);
	}
	return x;
	infile.close();
}