#include"SparseMatrix.h"
#include"Term.h"
#include<iostream>
using namespace std;

int main() {
	SparseMatrix<int> first, second,third;
	cout << "��һ������" << endl;	
	cin >> first;
	cout << "�ڶ�������" << endl;
	cin >> second;
	system("cls");
	cout << "��һ������" << endl;
	cout << first;
	cout << "�ڶ�������" << endl;
	cout << second;
	first.Mul(second, third);
	cout << "������˽��Ϊ��" << endl;
	cout << third << endl;
	while (1);
	return 0;
}