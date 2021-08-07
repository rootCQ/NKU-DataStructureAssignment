#pragma once
#include"BinTreeNode.h"
#include<queue>
#include<iostream>
using namespace std;

template<class T>
class BinTree {
public:
	BinTree() { root = 0;};
	~BinTree() {};
	bool IsEmpty() { return ((root) ? false : true); };
	void MakeTree2(T element, BinTree<T> *left, BinTree<T> *right);
	void MakeTree(T element, BinTreeNode<T> *leff, BinTreeNode<T> *right);
	void LOrder();
	void Exchange(BinTreeNode<T> *t);
	int get_wid();
	int LeafCount(BinTreeNode<T> *t);
	int hight;

public:
	BinTreeNode<T> *root;  // pointer to root
};

template<class T>
void BinTree<T>::MakeTree2(T element, BinTree<T> *left, BinTree<T> *right) {
	this->root = new BinTreeNode<T>(element, left->root, right->root);
	left->root = right->root = 0;
}

template<class T>
void BinTree<T>::MakeTree(T element, BinTreeNode<T> *left, BinTreeNode<T> *right) {
	this->root = new BinTreeNode<T>(element);
	this->root->LeftChild = left;
	this->root->RightChild = right;
}

template<class T>
int BinTree<T>::LeafCount(BinTreeNode<T> *t) {
	int count = 0;
	if (t->LeftChild == NULL && t->RightChild == NULL) {
		return 1;
	}
	else {
		count = LeafCount(t->RightChild) + LeafCount(t->LeftChild);
	}
	return count;
}

template<class T>
void BinTree<T>::Exchange(BinTreeNode<T> *t) {
	if (t != NULL) {
		BinTreeNode<T> *tmp = new BinTreeNode<T>;
		tmp = t->LeftChild;
		t->LeftChild = t->RightChild;
		t->RightChild = tmp;
		Exchange(t->LeftChild);
		Exchange(t->RightChild);
	}
}

template<class T>
void BinTree<T>::LOrder() {
	if (root == NULL) {
		cout << "The tree is empty" << endl;
	}
	else {
		queue<BinTreeNode<T> *> Box;
		BinTreeNode<T> *po = new BinTreeNode<T>;
		Box.push(root);
		while (!Box.empty())
		{
			po = Box.front();
			cout << po->data << " ";
			Box.pop();
			if (po->LeftChild != NULL) {
				Box.push(po->LeftChild);
			}
			if (po->RightChild != NULL) {
				Box.push(po->RightChild);
			}
		}
	}
}

template<class T>
int BinTree<T>::get_wid() {
	if (root == NULL) {
		cout << "The tree is empty" << endl;
		return 0;
	}
	else {
		int curwid = 0;
		int lastwid = 0;
		int maxwide = 1;
		queue<BinTreeNode<T> *> Box;
		BinTreeNode<T> *tmp;
		Box.push(root);
		lastwid = 1;

		while (!Box.empty()) {
			for (int i = lastwid; i > 0; i--) {
				tmp = Box.front();
				Box.pop();
				if (tmp->LeftChild != NULL) {
					Box.push(tmp->LeftChild);
				}
				if (tmp->RightChild != NULL) {
					Box.push(tmp->RightChild);
				}
			}
			curwid = Box.size();
			maxwide = (curwid > lastwid) ? curwid : lastwid;
			lastwid = curwid;
		}
		return maxwide;
	}
}