#pragma once
#include<iostream>
using namespace std;

enum RBTColor { RED, BLACK };

template<class T>
class RBTreeNode {
public:
	T data;
	RBTreeNode* lchild;
	RBTreeNode* rchild;
	RBTreeNode* parent;
	RBTColor color;
	RBTreeNode(T value, RBTColor c, RBTreeNode *p, RBTreeNode *l, RBTreeNode *r) {
		data = value;
		lchild = l;
		rchild = r;
		color = c;
		parent = p;
	}
};