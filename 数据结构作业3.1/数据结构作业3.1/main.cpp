#include<iostream>
#include"lowerTriangularMatrix.h"
#include"upperTriangularMatrix.h"
using namespace std;

int main() {
	int n;
	cout << "�������ת�õ������Ǿ����γ��"<<endl;
	cin >> n;
	lowerTriangularMatrix<int>* lowmatrix=new lowerTriangularMatrix<int>(n);
	cout << "��������" << n * (n + 1) / 2 << "��Ԫ��" << endl;
	cout << "���������������Ԫ�أ������ǲ��ֵ����������룩" << endl;
	int i = 1;
	while (i<=n*(n+1)/2)
	{
		int data;
		cin >> data;
		lowmatrix->set(i-1, data);
		i++;
	}
	cout << "ԭ�������£�" << endl;
	lowmatrix->showlow();
	upperTriangularMatrix<int>* upmatrix = new upperTriangularMatrix<int>(n);
	upmatrix=lowmatrix->reverse();
	cout << "ת�þ������£�" << endl;
	upmatrix->showup();
//	upmatrix=lowmatrix.reverse();
//	upmatrix.showup();
	while (1);
	return 0;
}