#pragma once
#include"dRBTreeNode.h"
#include<iostream>
using namespace std;

template<class T>
class dRBTree {
private:
	dRBTreeNode<T> *mRoot;
public:
	dRBTree() { mRoot = NULL; };
	void Ascend();
	dRBTreeNode<T>* Find(T val);
	void Insert(T val);
	void  Delete(T val);
private:
	void inOrder(dRBTreeNode<T>* tree) const;
	void LRotate(dRBTreeNode<T>* &root, dRBTreeNode<T>* x);
	void RRotate(dRBTreeNode<T>* &root, dRBTreeNode<T>* x);
	void insertFixUp(dRBTreeNode<T>* &root, dRBTreeNode<T>* node);
	void insert(dRBTreeNode<T>* &root, dRBTreeNode<T>* node);
	void remove(dRBTreeNode<T>* &root, dRBTreeNode<T> *node);
	void removeFixUp(dRBTreeNode<T>* &root, dRBTreeNode<T> *node, dRBTreeNode<T> *parent);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==red)
#define rb_is_black(r)  ((r)->color==black)
#define rb_set_black(r)  do { (r)->color = black; } while (0)
#define rb_set_red(r)  do { (r)->color = red; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};
//����
template<class T>
void dRBTree<T>::inOrder(dRBTreeNode<T>* tree) const {
	if (tree != NULL) {
		inOrder(tree->lchild);
		cout << tree->data << " ";
		inOrder(tree->rchild);
	}
}
template<class T>
void dRBTree<T>::Ascend() {
	inOrder(mRoot);
	cout << endl;
}
//����
template<class T>
dRBTreeNode<T>* dRBTree<T>::Find(T val) {
	dRBTreeNode<T>* x = mRoot;
	while (x != NULL && x->data != val) {
		if (val < x->data) {
			x = x->lchild;
		}
		else {
			x = x->rchild;
		}
	}
	return x;
}
//����
template<class T>
void dRBTree<T>::LRotate(dRBTreeNode<T>* &root, dRBTreeNode<T>* x) {
	dRBTreeNode<T>* y = x->rchild;
	x->rchild = y->lchild;
	if (y->lchild != NULL) {
		y->lchild->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL) {
		root = y;
	}
	else {
		if (x->parent->lchild == x) {
			x->parent->lchild = y;
		}
		else {
			x->parent->rchild = y;
		}
	}
	y->lchild = x;
	x->parent = y;
}
//����
template<class T>
void dRBTree<T>::RRotate(dRBTreeNode<T>* &root, dRBTreeNode<T>* y) {
	dRBTreeNode<T>* x = y->lchild;
	y->lchild = x->rchild;
	if (x->rchild != NULL) {
		x->rchild->parent = y;
	}
	x->parent = y->parent;
	if (y->parent == NULL) {
		root = x;
	}
	else {
		if (y->parent->rchild == y) {
			y->parent->rchild = x;
		}
		else {
			y->parent->lchild = x;
		}
	}
	x->rchild = y;
	y->parent = x;
}
//��������
template<class T>
void dRBTree<T>::insertFixUp(dRBTreeNode<T>* &root, dRBTreeNode<T>* node) {
	dRBTreeNode<T> *parent, *gparent;
	// �������ڵ���ڣ����Ҹ��ڵ����ɫ�Ǻ�ɫ��
	while ((parent = rb_parent(node)) && rb_is_red(parent)) {
		gparent = rb_parent(parent);
		//�������ڵ㡱�ǡ��游�ڵ�����ӡ�
		if (parent == gparent->lchild)
		{
			// Case 1����������ڵ��Ǻ�ɫ
			{
				dRBTreeNode<T> *uncle = gparent->rchild;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ���
			if (parent->rchild == node)
			{
				dRBTreeNode<T> *tmp;
				LRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ������ӡ�
			rb_set_black(parent);
			rb_set_red(gparent);
			RRotate(root, gparent);
		}
		else//����z�ĸ��ڵ㡱�ǡ�z���游�ڵ���Һ��ӡ�
		{
			// Case 1����������ڵ��Ǻ�ɫ
			{
				dRBTreeNode<T> *uncle = gparent->lchild;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2�����������Ǻ�ɫ���ҵ�ǰ�ڵ�������
			if (parent->lchild == node)
			{
				dRBTreeNode<T> *tmp;
				RRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3�����������Ǻ�ɫ���ҵ�ǰ�ڵ����Һ��ӡ�
			rb_set_black(parent);
			rb_set_red(gparent);
			LRotate(root, gparent);
		}
	}

	// �����ڵ���Ϊ��ɫ
	rb_set_black(root);
}
//����
template<class T>
void dRBTree<T>::insert(dRBTreeNode<T>* &root, dRBTreeNode<T>* node) {
	dRBTreeNode<T> *y = NULL;
	dRBTreeNode<T> *x = root;

	while (x != NULL) {
		y = x;
		if (node->data < x->data)
			x = x->lchild;
		else
			x = x->rchild;
	}

	node->parent = y;
	if (y != NULL) {
		if (node->data < y->data)
			y->lchild = node;
		else
			y->rchild = node;
	}
	else
		root = node;
	node->color = red;
	insertFixUp(root, node);
}
template<class T>
void dRBTree<T>::Insert(T val) {
	dRBTreeNode<T> *z = NULL;
	if ((z = new dRBTreeNode<T>(val, black, NULL, NULL, NULL)) == NULL)
		return;
	insert(mRoot, z);
}
//ɾ�������
template <class T>
void dRBTree<T>::removeFixUp(dRBTreeNode<T>* &root, dRBTreeNode<T> *node, dRBTreeNode<T> *parent)
{
	dRBTreeNode<T> *other;

	while ((!node || rb_is_black(node)) && node != root)
	{
		if (parent->lchild == node)
		{
			other = parent->rchild;
			if (rb_is_red(other))
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��  
				rb_set_black(other);
				rb_set_red(parent);
				LRotate(root, parent);
				other = parent->rchild;
			}
			if ((!other->lchild || rb_is_black(other->lchild)) &&
				(!other->rchild || rb_is_black(other->rchild)))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��  
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->rchild || rb_is_black(other->rchild))
				{
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��  
					rb_set_black(other->lchild);
					rb_set_red(other);
					RRotate(root, other);
					other = parent->rchild;
				}
				// Case 4: x���ֵ�w�Ǻ�ɫ�ģ�����w���Һ����Ǻ�ɫ�ģ�����������ɫ��
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->rchild);
				LRotate(root, parent);
				node = root;
				break;
			}
		}
		else
		{
			other = parent->lchild;
			if (rb_is_red(other))
			{
				// Case 1: x���ֵ�w�Ǻ�ɫ��  
				rb_set_black(other);
				rb_set_red(parent);
				RRotate(root, parent);
				other = parent->lchild;
			}
			if ((!other->lchild || rb_is_black(other->lchild)) &&
				(!other->rchild || rb_is_black(other->rchild)))
			{
				// Case 2: x���ֵ�w�Ǻ�ɫ����w����������Ҳ���Ǻ�ɫ��  
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->lchild || rb_is_black(other->lchild)) {
					// Case 3: x���ֵ�w�Ǻ�ɫ�ģ�����w�������Ǻ�ɫ���Һ���Ϊ��ɫ��  
					rb_set_black(other->rchild);
					rb_set_red(other);
					LRotate(root, other);
					other = parent->lchild;
				}
				rb_set_color(other, rb_color(parent));
				rb_set_black(parent);
				rb_set_black(other->lchild);
				RRotate(root, parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		rb_set_black(node);
}
//ɾ��
template <class T>
void dRBTree<T>::remove(dRBTreeNode<T>* &root, dRBTreeNode<T> *node)
{
	dRBTreeNode<T> *child, *parent;
	dRBTColor color;

	// ��ɾ���ڵ��"���Һ��Ӷ���Ϊ��"�������
	if ((node->lchild != NULL) && (node->rchild != NULL))
	{
		// ��ɾ�ڵ�ĺ�̽ڵ㡣(��Ϊ"ȡ���ڵ�")
		// ������ȡ��"��ɾ�ڵ�"��λ�ã�Ȼ���ٽ�"��ɾ�ڵ�"ȥ����
		dRBTreeNode<T> *replace = node;

		// ��ȡ��̽ڵ�
		replace = replace->rchild;
		while (replace->lchild != NULL)
			replace = replace->lchild;

		// "node�ڵ�"���Ǹ��ڵ�(ֻ�и��ڵ㲻���ڸ��ڵ�)
		if (rb_parent(node))
		{
			if (rb_parent(node)->lchild == node)
				rb_parent(node)->lchild = replace;
			else
				rb_parent(node)->rchild = replace;
		}
		else
			// "node�ڵ�"�Ǹ��ڵ㣬���¸��ڵ㡣
			root = replace;

		// child��"ȡ���ڵ�"���Һ��ӣ�Ҳ����Ҫ"�����Ľڵ�"��
		// "ȡ���ڵ�"�϶����������ӣ���Ϊ����һ����̽ڵ㡣
		child = replace->rchild;
		parent = rb_parent(replace);
		// ����"ȡ���ڵ�"����ɫ
		color = rb_color(replace);

		// "��ɾ���ڵ�"��"���ĺ�̽ڵ�ĸ��ڵ�"
		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			// child��Ϊ��
			if (child)
				rb_set_parent(child, parent);
			parent->lchild = child;

			replace->rchild = node->rchild;
			rb_set_parent(node->rchild, replace);
		}

		replace->parent = node->parent;
		replace->color = node->color;
		replace->lchild = node->lchild;
		node->lchild->parent = replace;

		if (color == black)
			removeFixUp(root, child, parent);
		delete node;
		return;
	}

	if (node->lchild != NULL)
		child = node->lchild;
	else
		child = node->rchild;

	parent = node->parent;
	// ����"ȡ���ڵ�"����ɫ
	color = node->color;

	if (child)
		child->parent = parent;

	// "node�ڵ�"���Ǹ��ڵ�
	if (parent)
	{
		if (parent->lchild == node)
			parent->lchild = child;
		else
			parent->rchild = child;
	}
	else
		root = child;

	if (color == black)
		removeFixUp(root, child, parent);
	delete node;
}
template <class T>
void dRBTree<T>::Delete(T key)
{
	dRBTreeNode<T> *node;
	// ����key��Ӧ�Ľڵ�(node)���ҵ��Ļ���ɾ���ýڵ�
	while ((node = Find(key)) != NULL)
		remove(mRoot, node);
}