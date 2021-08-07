#include"RBTree.h"
#include"dRBTree.h"
#include<iostream>
using namespace std;

int main() {
	cout << "Please enter the number of RBTree element(s)" << endl;
	int number;
	cin >> number;
	RBTree<int>* tree = new RBTree<int>();
	int i = 1;
	while (i <= number) {
		cout << "Enter " << i << " element" << endl;
		int ele;
		cin >> ele;
		tree->Insert(ele);
		i++;
	}
	cout << "The RBTree is:" << endl;
	tree->Ascend();
	cout << "Need to Delete?Yes(1)/No(0)" << endl;
	int judge;
	cin >> judge;
	if (judge == 1) {
		cout << "Enter the element you want to delete" << endl;
		int delEle;
		cin >> delEle;
		tree->Delete(delEle);
		cout << "The results are:" << endl;
		tree->Ascend();
	}

	cout << "Do you want to test dRBTree?Yes(1)/No(0)" << endl;
	int ifnext = 0;
	cin >> ifnext;

	if (ifnext == 1) {
		system("cls");
		cout << "Please enter the number of dRBTree element(s)" << endl;
		int dnumber;
		cin >> dnumber;
		dRBTree<int>* dtree = new dRBTree<int>();
		int j = 1;
		while (j <= dnumber) {
			cout << "Enter " << j << " element" << endl;
			int ele;
			cin >> ele;
			dtree->Insert(ele);
			j++;
		}
		cout << "The dRBTree is:" << endl;
		dtree->Ascend();
		cout << "Need to Delete?Yes(1)/No(0)" << endl;
		int djudge;
		cin >> djudge;
		if (djudge == 1) {
			cout << "Enter the element you want to delete" << endl;
			int delEle;
			cin >> delEle;
			dtree->Delete(delEle);
			cout << "The results are:" << endl;
			dtree->Ascend();
		}
	}
	else {
		system("cls");
		cout << "Goodbye!" << endl;
	}
	/*	tree->Insert(10);
	tree->Insert(40);
	tree->Insert(30);
	tree->Insert(70);
	tree->Insert(60);
	tree->Insert(90);
	tree->Insert(70);
	tree->Insert(20);
	tree->Insert(50);
	tree->Insert(80);
	tree->Ascend();
	cout << endl;
	tree->Delete(20);
	tree->Ascend();
	cout << endl;*/
	/*	dRBTree<int> *dtree = new dRBTree<int>();
	dtree->Insert(10);
	dtree->Insert(40);
	dtree->Insert(30);
	dtree->Insert(70);
	dtree->Insert(60);
	dtree->Insert(90);
	dtree->Insert(70);
	dtree->Insert(20);
	dtree->Insert(50);
	dtree->Insert(80);
	dtree->Ascend();
	cout << endl;
	dtree->Delete(70);
	dtree->Ascend();
	cout << endl;*/
	while (1);
	return 0;
}