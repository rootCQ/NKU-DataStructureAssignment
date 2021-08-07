#include"Tree.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
	Tree *tr=new Tree;
	string expression;
	ifstream fin("D:/imput2.txt");
	getline(fin, expression);
	tr->generateTree(tr->root, expression);
	tr->display(tr->root, 1);
	while (1);
	return 0;
}