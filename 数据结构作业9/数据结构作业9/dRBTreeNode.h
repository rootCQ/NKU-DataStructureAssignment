#pragma once
#include<iostream>
using namespace std;

enum dRBTColor { red, black };

template<class T>
class dRBTreeNode {
public:
	T data;
	dRBTreeNode* lchild;
	dRBTreeNode* rchild;
	dRBTreeNode* parent;
	dRBTColor color;
	dRBTreeNode(T value, dRBTColor c, dRBTreeNode *p, dRBTreeNode *l, dRBTreeNode *r) {
		data = value;
		lchild = l;
		rchild = r;
		color = c;
		parent = p;
	}
};