#include"AVLtree.h"
#include<iostream>
using namespace std;

int main() {
	AVLtree<int>* avl = new AVLtree<int>(23);
	avl->InsertEle(15);
	avl->InsertEle(13);
	avl->InsertEle(60);
	avl->InsertEle(14);
	avl->InsertEle(11);
	avl->InsertEle(1);
	avl->PrintTree();
	avl->GetNearestLeaves();
	cout << "The height of tree:" << endl;
	cout << avl->GetHeight() << endl;
	while (1);
	return 0;
}