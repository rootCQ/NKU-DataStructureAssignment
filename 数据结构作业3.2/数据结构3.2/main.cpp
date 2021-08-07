#include"SparseMatrix.h"
#include"Term.h"
#include<iostream>
using namespace std;

int main() {
	SparseMatrix<int> first, second,third;
	cout << "第一个矩阵：" << endl;	
	cin >> first;
	cout << "第二个矩阵：" << endl;
	cin >> second;
	system("cls");
	cout << "第一个矩阵：" << endl;
	cout << first;
	cout << "第二个矩阵：" << endl;
	cout << second;
	first.Mul(second, third);
	cout << "矩阵相乘结果为：" << endl;
	cout << third << endl;
	while (1);
	return 0;
}