#pragma once
#include<iostream>
#include"lowerTriangularMatrix.h"
using namespace std;

template<class T>
class upperTriangularMatrix
{
public:
	upperTriangularMatrix(int n);
	~upperTriangularMatrix();
	void showup();
//	upperTriangularMatrix<T>& operator=(const upperTriangularMatrix<T>&);
	T *eleup;
	T sizeup;
};

template<class T>
upperTriangularMatrix<T>::upperTriangularMatrix(int n)
{
		int term = n*(n+1)/2;
		eleup = new T[term];
		sizeup = n;
	
}

template<class T>
upperTriangularMatrix<T>::~upperTriangularMatrix()
{
	delete[]eleup;
}

template<class T>
void upperTriangularMatrix<T>::showup() {
	int i = 0;
	int elenum = 0;
	int ele = this->sizeup;
	while (i<=this->sizeup-1)
	{
		int zero = 0;
		while (zero<i)
		{
			cout << 0 << " ";
			zero++;
		}
		while (ele>0)
		{
			cout << this->eleup[elenum] << " ";
			ele--;
			elenum++;
		}
		i++;
		ele = this->sizeup - i;
		cout << endl;
	}
}