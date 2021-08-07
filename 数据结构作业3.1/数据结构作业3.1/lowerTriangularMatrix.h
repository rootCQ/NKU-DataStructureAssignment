#pragma once
#include<iostream>
#include"upperTriangularMatrix.h"
using namespace std;

template<class T>
class lowerTriangularMatrix
{
public:
	lowerTriangularMatrix(int n);
	~lowerTriangularMatrix();
	void set(int position,T value);
	void showlow();
	upperTriangularMatrix<T>* reverse();
	T *elelow;
	T sizelow;
};

template<class T>
lowerTriangularMatrix<T>::lowerTriangularMatrix(int n)
{
	int term = n * (n + 1) / 2;
	elelow = new T[term];
	sizelow = n;
}

template<class T>
lowerTriangularMatrix<T>::~lowerTriangularMatrix()
{
	delete[]elelow;
}

template<class T>
void lowerTriangularMatrix<T>::showlow() {
	int i = 1;
	int elenum = 0;
	int ele = 0;
	while (i <= this->sizelow)
	{
		ele = 0;
		while (ele < i)
		{
			cout << this->elelow[elenum] << " ";
			ele++;
			elenum++;
		}
		int zero = this->sizelow - i;
		while (zero > 0)
		{
			cout << 0 << " ";
			zero--;
		}
		i++;
		cout << endl;
	}
}

template<class T>
void lowerTriangularMatrix<T>::set(int position, T value) {
	elelow[position] = value;
}

template<class T>
upperTriangularMatrix<T>* lowerTriangularMatrix<T>::reverse()
{
	upperTriangularMatrix<T>* result;
	result = new upperTriangularMatrix<T>(this->sizelow);
	/*原来（i,j）position：i*（i-1）/2+j-1*/
	/*现在（i，j）position：*/
	int count = 0;
	//int total = this->sizelow*(1 + this->showlow) / 2;
	int n = this->sizelow;
	for (int a = 0; a < n; a++) {
		for (int b = 1+a; b <= n; b++) {
			result->eleup[count] = this->elelow[a + b * (b - 1) / 2 ];
			count++;
		}
	}
	return result;
}


