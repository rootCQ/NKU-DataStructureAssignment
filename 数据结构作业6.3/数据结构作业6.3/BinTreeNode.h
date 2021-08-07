#pragma once
#include<iostream>
using namespace std;

template <class T>
class BinTreeNode {
public:
	BinTreeNode() { LeftChild = RightChild = 0; }
	BinTreeNode(T e) { data = e;  LeftChild = RightChild = 0; }
	BinTreeNode(T e, BinTreeNode *l, BinTreeNode *r) { data = e;  LeftChild = l;  RightChild = r; }

public:
	T data;
	BinTreeNode<T> *LeftChild,   // left subtree
		*RightChild;  // right subtree
	int hight;
};
