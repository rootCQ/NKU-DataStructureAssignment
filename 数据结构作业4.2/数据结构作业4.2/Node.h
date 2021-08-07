#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;	
public:
	Node<T> *next;
};