#pragma once
#include"AVLtreeNode.h"
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

template<class T>
class AVLtree {
public:
	AVLtree(T ele) {
		root = new treeNode<T>(ele);
	};
	void InsertEle(T ele);
	int GetHeight();
	void GetNearestLeaves();
	void PrintTree();
//	void Delete(T ele);


private:
	treeNode<T> *root;

	treeNode<T>* LLRotate(treeNode<T>* node);
	treeNode<T>* LRRotate(treeNode<T>* node);
	treeNode<T>* RLRotate(treeNode<T>* node);
	treeNode<T>* RRRotate(treeNode<T>* node);
	treeNode<T>* Insert(T ele, treeNode<T>* node);

	int get_height(treeNode<T> *node);

	void print(treeNode<T>* node, int n);

	void nearest(stack<treeNode<T>* > box,stack<int> boxofsteps);
	void get_leaves(treeNode<T>* node, stack<treeNode<T>* >& box,int& steps,stack<int>& boxofsteps);
};

template<class T>
treeNode<T>* AVLtree<T>::LLRotate(treeNode<T>* node) {
	treeNode<T>* node1 = node->lchild;
	node->lchild = node1->rchild;
	node1->rchild = node;

	node->height = (get_height(node->lchild) > get_height(node->rchild) ? get_height(node->lchild) : get_height(node->rchild)) + 1;
	node1->height = (get_height(node1->lchild) > get_height(node1->rchild) ? get_height(node1->lchild) : get_height(node1->rchild)) + 1;
	
	return node1;
}

template<class T>
treeNode<T>* AVLtree<T>::RRRotate(treeNode<T>* node) {
	treeNode<T>* node1 = node->rchild;
	node->rchild = node1->rchild;
	node1->lchild = node;

	node->height = (get_height(node->lchild) > get_height(node->rchild) ? get_height(node->lchild) : get_height(node->rchild)) + 1;
	node1->height = (get_height(node1->lchild) > get_height(node1->rchild) ? get_height(node1->lchild) : get_height(node1->rchild)) + 1;

	return node1;
}

template<class T>
treeNode<T>* AVLtree<T>::LRRotate(treeNode<T>* node) {
	treeNode<T>* node1 = node->lchild;
	node1 = RRRotate(node1);
	return LLRotate(node);
}

template<class T>
treeNode<T>* AVLtree<T>::RLRotate(treeNode<T>* node) {
	treeNode<T>* node1 = node->rchild;
	node1 = LLRotate(node1);
	return RRRotate(node);
}

template<class T>
treeNode<T>* AVLtree<T>::Insert(T ele,treeNode<T>* node) {
	if (node == NULL)
	{
		node = new treeNode<T>(ele);
		if (node == NULL)
		{
			cout << "ERROR: create avltree node failed!" << endl;
			return NULL;
		}
	}
	else if (ele < node->data) 
	{
		node->lchild = Insert(ele,node->lchild);
		//adjust
		if (get_height(node->lchild) - get_height(node->rchild) == 2)
		{
			if (ele < node->lchild->data)
				node = LLRotate(node);
			else
				node = LRRotate(node);
		}
	}
	else if (ele > node->data) 
	{
		node->rchild = Insert(ele,node->rchild);
		if (get_height(node->rchild) - get_height(node->lchild) == 2)
		{
			if (ele > node->rchild->data)
				node = RRRotate(node);
			else
				node = RLRotate(node);
		}
	}
	else 
	{
		cout << "Error:Duplication!" << endl;
	}
	node->height = (get_height(node->rchild) > get_height(node->rchild) ? get_height(node->rchild) : get_height(node->lchild)) + 1;
	return node;
}

template<class T>
void AVLtree<T>::InsertEle(T ele) {
	root = Insert(ele, root);
}

template<class T>
int AVLtree<T>::get_height(treeNode<T>* node) {
	if (node != NULL) {
		return node->height;
	}
	else {
		return 0;
	}
}

template<class T>
int AVLtree<T>::GetHeight() {
	return get_height(root);
}

template<class T>
void AVLtree<T>::get_leaves(treeNode<T>* node,stack<treeNode<T>* >& box,int& steps,stack<int>& boxofsteps) {//streps = 0
	if (node->rchild == NULL && node->lchild == NULL) {
		box.push(node);
		boxofsteps.push(steps);
	}
	else {
		int p = steps;
		if (node->rchild != NULL) {
			steps++;
			get_leaves(node->rchild,box,steps,boxofsteps);
		}
		steps = p;
		if (node->lchild != NULL) {
			steps++;
			get_leaves(node->lchild, box,steps,boxofsteps);
		}
	}
}

template<class T>
void AVLtree<T>::nearest(stack<treeNode<T>*> box,stack<int> boxofsteps) {
	//stack<treeNode<T>*> boxofsteps1;
	queue<int> boxofsteps1;
	int min_step = boxofsteps.top();

	while (!boxofsteps.empty()) {
		min_step = boxofsteps.top() < min_step ? boxofsteps.top() : min_step;
		boxofsteps1.push(boxofsteps.top());
		boxofsteps.pop();
	}

	while (!box.empty()) {
		if (boxofsteps1.front() == min_step) {
			cout << box.top()->data << " ";
			box.pop();
			boxofsteps1.pop();
		}
		else {
			box.pop();
			boxofsteps1.pop();
		}
	}
}

template<class T>
void AVLtree<T>::GetNearestLeaves() {
	stack<treeNode<T>* > box;
	stack<int> boxofsteps;
	int step = 0;
	get_leaves(root, box, step, boxofsteps);
	cout << "The value of nearest leave(s):" << endl;
	nearest(box, boxofsteps);
	cout << endl;
}

template<class T>
void AVLtree<T>::print(treeNode<T>* node, int n) {
	if (node == NULL) {
		return;
	}
	else {
		print(node->rchild, n + 2);
		for (int i = 0; i < n; i++) {
			cout << " ";
		}
		cout << node->data << endl;
		print(node->lchild, n + 2);
	}
}

template<class T>
void AVLtree<T>::PrintTree() {
	print(root, 2);
}