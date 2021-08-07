#include"BinTree.h"
#include<iostream>
#include<math.h>
#include<queue>
using namespace std;

int main() {
	cout << "If the position is vacant , enter 0" << endl;
	cout << "Please enter the hight of binarytree!" << endl;
	int hight;
	cin >> hight;
	int elebox[300];
	for (int i = 0; i < 300; i++) {
		elebox[i] = -1;
	}
	BinTree<int> *btree;
	int end = 0;
	end = pow(2,hight) - 1;
	cout << "Enter "<<end<<" elements" << endl;
	for (int i = 0; i < end ; i++) {
		cin >> elebox[i];
	}//imput 0 means the position is null
	queue<BinTree<int> *> imputque;



	//int ground = 2 ^ (hight - 1);
	int ground = pow(2, hight - 2);
	for (int i = 0; i < ground; i++) {
		BinTree<int> *tmptree = new BinTree<int>;
		int group = 3 * i;
		BinTreeNode<int> *nodel = new BinTreeNode<int>(elebox[group]);
		BinTreeNode<int> *noder = new BinTreeNode<int>(elebox[group + 1]);
		tmptree->MakeTree(elebox[group + 2], nodel, noder);
		imputque.push(tmptree);
	}
	int point = 3 * ground ;
	while (point != end) {
		BinTree<int> *tmptree = new BinTree<int>;
		BinTree<int> *tmp1 = imputque.front();
		imputque.pop();
		BinTree<int> *tmp2 = imputque.front();
		imputque.pop();
		tmptree->MakeTree2(elebox[point], tmp1, tmp2);
		imputque.push(tmptree);
		point++;
	}

	btree = imputque.front();
	cout << "Binary Tree" << endl;
	btree->LOrder();
	cout << endl;
	cout << "After exchange" << endl;
	btree->Exchange(btree->root);
	btree->LOrder();
	cout << endl;
	cout << "Count leafs" << endl;
	cout << btree->LeafCount(btree->root) << endl;
	cout << "Width" << endl;
	cout << btree->get_wid ()<< endl;
	while (1);
	return 0;
}