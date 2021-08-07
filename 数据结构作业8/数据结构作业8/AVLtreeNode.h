#pragma once
#include<iostream>
using namespace std;

template<class T>
class treeNode {
public:
	T data;
	treeNode* lchild;
	treeNode* rchild;
	int height;
	treeNode() {
		lchild = NULL;
		rchild = NULL;
		height = 0;
	}
	treeNode(T ele) {
		lchild = NULL;
		rchild = NULL;
		height = 1;
		data = ele;
	}
};