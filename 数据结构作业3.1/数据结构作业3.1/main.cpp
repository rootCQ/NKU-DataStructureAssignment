#include<iostream>
#include"lowerTriangularMatrix.h"
#include"upperTriangularMatrix.h"
using namespace std;

int main() {
	int n;
	cout << "请输入待转置的下三角矩阵的纬度"<<endl;
	cin >> n;
	lowerTriangularMatrix<int>* lowmatrix=new lowerTriangularMatrix<int>(n);
	cout << "共需输入" << n * (n + 1) / 2 << "个元素" << endl;
	cout << "请依次输入矩阵中元素（上三角部分的零无需输入）" << endl;
	int i = 1;
	while (i<=n*(n+1)/2)
	{
		int data;
		cin >> data;
		lowmatrix->set(i-1, data);
		i++;
	}
	cout << "原矩阵如下：" << endl;
	lowmatrix->showlow();
	upperTriangularMatrix<int>* upmatrix = new upperTriangularMatrix<int>(n);
	upmatrix=lowmatrix->reverse();
	cout << "转置矩阵如下：" << endl;
	upmatrix->showup();
//	upmatrix=lowmatrix.reverse();
//	upmatrix.showup();
	while (1);
	return 0;
}