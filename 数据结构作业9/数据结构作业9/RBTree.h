#pragma once
#include"RBTreeNode.h"
#include<iostream>
using namespace std;

template<class T>
class RBTree {
private:
	RBTreeNode<T> *mRoot;
public:
	RBTree() { mRoot = NULL; };
	void Ascend();
	RBTreeNode<T>* Find(T val);
	void Insert(T val);
	void  Delete(T val);
private:
	void inOrder(RBTreeNode<T>* tree) const;
	void LRotate(RBTreeNode<T>* &root, RBTreeNode<T>* x);
	void RRotate(RBTreeNode<T>* &root, RBTreeNode<T>* x);
	void insertFixUp(RBTreeNode<T>* &root, RBTreeNode<T>* node);
	void insert(RBTreeNode<T>* &root, RBTreeNode<T>* node);
	void remove(RBTreeNode<T>* &root, RBTreeNode<T> *node);
	void removeFixUp(RBTreeNode<T>* &root, RBTreeNode<T> *node, RBTreeNode<T> *parent);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};
//遍历
template<class T>
void RBTree<T>::inOrder(RBTreeNode<T>* tree) const {
	if (tree != NULL) {
		inOrder(tree->lchild);
		cout <<tree->data<< " ";
		inOrder(tree->rchild);
	}
}
template<class T>
void RBTree<T>::Ascend() {
	inOrder(mRoot);
	cout << endl;
}
//查找
template<class T>
RBTreeNode<T>* RBTree<T>::Find(T val) {
	RBTreeNode<T>* x = mRoot;
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
//左旋
template<class T>
void RBTree<T>::LRotate(RBTreeNode<T>* &root, RBTreeNode<T>* x) {
	RBTreeNode<T>* y = x->rchild;
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
//右旋
template<class T>
void RBTree<T>::RRotate(RBTreeNode<T>* &root, RBTreeNode<T>* y) {
	RBTreeNode<T>* x = y->lchild;
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
//插入后调整
template<class T>
void RBTree<T>::insertFixUp(RBTreeNode<T>* &root, RBTreeNode<T>* node) {
	RBTreeNode<T> *parent, *gparent;
	// 若“父节点存在，并且父节点的颜色是红色”
	while ((parent = rb_parent(node)) && rb_is_red(parent)){
		gparent = rb_parent(parent);
		//若“父节点”是“祖父节点的左孩子”
		if (parent == gparent->lchild)
		{
			// Case 1条件：叔叔节点是红色
			{
				RBTreeNode<T> *uncle = gparent->rchild;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2条件：叔叔是黑色，且当前节点是右孩子
			if (parent->rchild == node)
			{
				RBTreeNode<T> *tmp;
				LRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3条件：叔叔是黑色，且当前节点是左孩子。
			rb_set_black(parent);
			rb_set_red(gparent);
			RRotate(root, gparent);
		}
		else//若“z的父节点”是“z的祖父节点的右孩子”
		{
			// Case 1条件：叔叔节点是红色
			{
				RBTreeNode<T> *uncle = gparent->lchild;
				if (uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
					rb_set_black(parent);
					rb_set_red(gparent);
					node = gparent;
					continue;
				}
			}

			// Case 2条件：叔叔是黑色，且当前节点是左孩子
			if (parent->lchild == node)
			{
				RBTreeNode<T> *tmp;
				RRotate(root, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}

			// Case 3条件：叔叔是黑色，且当前节点是右孩子。
			rb_set_black(parent);
			rb_set_red(gparent);
			LRotate(root, gparent);
		}
	}

	// 将根节点设为黑色
	rb_set_black(root);
}
//插入
template<class T>
void RBTree<T>::insert(RBTreeNode<T>* &root, RBTreeNode<T>* node) {
	RBTreeNode<T> *y = NULL;
	RBTreeNode<T> *x = root;

	while (x != NULL){
		y = x;
		if (node->data < x->data)
			x = x->lchild;
		else
			x = x->rchild;
	}

	node->parent = y;
	if (y != NULL){
		if (node->data < y->data)
			y->lchild = node;
		else
			y->rchild = node;
	}
	else
		root = node;
	node->color = RED;
	insertFixUp(root, node);
}
template<class T>
void RBTree<T>::Insert(T val) {
	RBTreeNode<T> *z = NULL;
	RBTreeNode<T>* p = Find(val);
	if ((z = new RBTreeNode<T>(val, BLACK, NULL, NULL, NULL)) == NULL)
		return;
	if (p != NULL) {
		cout << "Error!The element "<<val<<" has doubled." << endl;
		return;
	}
	else {
		insert(mRoot, z);
	}
}
//删除后调整
template <class T>
void RBTree<T>::removeFixUp(RBTreeNode<T>* &root, RBTreeNode<T> *node, RBTreeNode<T> *parent)
{
	RBTreeNode<T> *other;

	while ((!node || rb_is_black(node)) && node != root)
	{
		if (parent->lchild == node)
		{
			other = parent->rchild;
			if (rb_is_red(other))
			{
				// Case 1: x的兄弟w是红色的  
				rb_set_black(other);
				rb_set_red(parent);
				LRotate(root, parent);
				other = parent->rchild;
			}
			if ((!other->lchild || rb_is_black(other->lchild)) &&
				(!other->rchild || rb_is_black(other->rchild)))
			{
				// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->rchild || rb_is_black(other->rchild))
				{
					// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
					rb_set_black(other->lchild);
					rb_set_red(other);
					RRotate(root, other);
					other = parent->rchild;
				}
				// Case 4: x的兄弟w是黑色的；并且w的右孩子是红色的，左孩子任意颜色。
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
				// Case 1: x的兄弟w是红色的  
				rb_set_black(other);
				rb_set_red(parent);
				RRotate(root, parent);
				other = parent->lchild;
			}
			if ((!other->lchild || rb_is_black(other->lchild)) &&
				(!other->rchild || rb_is_black(other->rchild)))
			{
				// Case 2: x的兄弟w是黑色，且w的俩个孩子也都是黑色的  
				rb_set_red(other);
				node = parent;
				parent = rb_parent(node);
			}
			else
			{
				if (!other->lchild || rb_is_black(other->lchild)){
					// Case 3: x的兄弟w是黑色的，并且w的左孩子是红色，右孩子为黑色。  
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
//删除
template <class T>
void RBTree<T>::remove(RBTreeNode<T>* &root, RBTreeNode<T> *node)
{
	RBTreeNode<T> *child, *parent;
	RBTColor color;

	// 被删除节点的"左右孩子都不为空"的情况。
	if ((node->lchild != NULL) && (node->rchild != NULL))
	{
		// 被删节点的后继节点。(称为"取代节点")
		// 用它来取代"被删节点"的位置，然后再将"被删节点"去掉。
		RBTreeNode<T> *replace = node;

		// 获取后继节点
		replace = replace->rchild;
		while (replace->lchild != NULL)
			replace = replace->lchild;

		// "node节点"不是根节点(只有根节点不存在父节点)
		if (rb_parent(node))
		{
			if (rb_parent(node)->lchild == node)
				rb_parent(node)->lchild = replace;
			else
				rb_parent(node)->rchild = replace;
		}
		else
			// "node节点"是根节点，更新根节点。
			root = replace;

		// child是"取代节点"的右孩子，也是需要"调整的节点"。
		// "取代节点"肯定不存在左孩子！因为它是一个后继节点。
		child = replace->rchild;
		parent = rb_parent(replace);
		// 保存"取代节点"的颜色
		color = rb_color(replace);

		// "被删除节点"是"它的后继节点的父节点"
		if (parent == node)
		{
			parent = replace;
		}
		else
		{
			// child不为空
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

		if (color == BLACK)
			removeFixUp(root, child, parent);
		delete node;
		return;
	}

	if (node->lchild != NULL)
		child = node->lchild;
	else
		child = node->rchild;

	parent = node->parent;
	// 保存"取代节点"的颜色
	color = node->color;

	if (child)
		child->parent = parent;

	// "node节点"不是根节点
	if (parent)
	{
		if (parent->lchild == node)
			parent->lchild = child;
		else
			parent->rchild = child;
	}
	else
		root = child;

	if (color == BLACK)
		removeFixUp(root, child, parent);
	delete node;
}
template <class T>
void RBTree<T>::Delete(T key)
{
	RBTreeNode<T> *node;
	// 查找key对应的节点(node)，找到的话就删除该节点
	if ((node = Find(key)) != NULL)
		remove(mRoot, node);
}