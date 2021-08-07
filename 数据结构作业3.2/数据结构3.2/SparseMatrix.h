#pragma once
#include"Term.h"
#include<iostream>
using namespace std;

template<class T>
class SparseMatrix
{
	template<typename U>
	friend std::ostream& operator<<
		(std::ostream&, const SparseMatrix<U>&);
	template<typename U>
	friend std::istream& operator>>
		(std::istream&, SparseMatrix<U>&);
public:
	SparseMatrix(int maxTerms = 10);
	~SparseMatrix() { delete[] a; }
	void Transpose(SparseMatrix<T> &b) const;
	void Mul(const SparseMatrix<T> a2,SparseMatrix<T> &result) const;

	void Append(const Term<T>& t);
	int rows, cols;  // matrix dimensions
	int terms;  // current number of nonzero terms
	Term<T> *a;   // term array
	int MaxTerms; // size of array a;
};

template<class T>
SparseMatrix<T>::SparseMatrix(int maxTerms)
{// Sparse matrix constructor.
	MaxTerms = maxTerms;
	a = new Term<T>[MaxTerms];
	terms = rows = cols = 0;
}


template <typename U>
ostream& operator<<(ostream& out,
	const SparseMatrix<U>& x)
{// Put *this in output stream.
	out << "rows = " << x.rows << " columns = "
		<< x.cols << endl;
	out << "nonzero terms = " << x.terms << endl;

	for (int i = 0; i < x.terms; i++)
		out << "a(" << x.a[i].row << ',' << x.a[i].col
		<< ") = " << x.a[i].value << endl;
	return out;
}


template<typename U>
istream& operator>>(istream& in, SparseMatrix<U>& x)
{// Input a sparse matrix.
	cout << "Enter number of rows, columns, and terms"
		<< endl;
	in >> x.rows >> x.cols >> x.terms;


	for (int i = 0; i < x.terms; i++) {
		cout << "Enter row, column, and value of term "
			<< (i + 1) << endl;
		in >> x.a[i].row >> x.a[i].col >> x.a[i].value;
	}
	return in;
}

template<class T>
void SparseMatrix<T>::Transpose(SparseMatrix<T> &b) const
{// b保存转置结果.

   // make sure b has enough space

	// set transpose characteristics
	b.cols = rows;
	b.rows = cols;
	b.terms = terms;
	// initialize to compute transpose
	int *ColSize, *RowNext;
	ColSize = new int[cols + 1];
	RowNext = new int[cols + 1];

	// find number of entries in each column of *this
	for (int i = 1; i <= cols; i++) // initialize
		ColSize[i] = 0;
	for (int i = 0; i < terms; i++) // 计算每列元素数目
		ColSize[a[i].col]++;

	// 计算转置矩阵每行（原矩阵每列）第一个元素在b中位置
	// 第i行起始位置：行1元素数+…+行i-1元素数
	RowNext[1] = 0;
	for (int i = 2; i <= cols; i++)
		RowNext[i] = RowNext[i - 1] + ColSize[i - 1];
	// perform the transpose copying from *this to b
	for (int i = 0; i < terms; i++) {
		int j = RowNext[a[i].col]++; // a[i]在b中位置
		b.a[j].row = a[i].col;
		b.a[j].col = a[i].row;
		b.a[j].value = a[i].value;
	}
}

template<class T>
void SparseMatrix<T>::Append(const Term<T>& t)
{// Append a nonzero term t to *this.
	a[terms] = t;
	terms++;
}

template<class T>
void SparseMatrix<T>::Mul(SparseMatrix<T> a2, SparseMatrix<T> &finalresult) const 
{
	//this*a2，保存在finalresult中
	if (cols != a2.rows) {
		cout << "该两个矩阵无法相乘！！" << endl;
	}
	else {
		SparseMatrix<T> result(MaxTerms);
		int resterms = 0;
		result.rows = rows;
		result.cols = a2.cols;
		finalresult.rows = rows;
		finalresult.cols = a2.cols;
		finalresult.MaxTerms = MaxTerms;
		if (terms >= a2.terms) {
			result.terms = terms;
		}
		else {
			result.terms = a2.terms;
		}
		for (int t = 0; t < result.terms; t++) {
			result.a[t].value = 0;
		}
		int p2 = 0;
		for (int p1 = 0; p1 < terms; p1++) {
			for (p2 = 0; p2 < a2.terms; p2++) {
				if (a[p1].col == a2.a[p2].row) {
					result.a[resterms].value += a[p1].value*a2.a[p2].value;
					result.a[resterms].row = a[p1].row;
					result.a[resterms].col = a2.a[p2].col;
					resterms++;
				}
			}
		}
		//对列排序
		for (int pre = 0; pre < result.terms; pre++) {
			for (int j = pre; j < result.terms; j++) {
				int mincol = result.a[pre].col;
				if (mincol > result.a[j].col) {
					T temp;
					temp = result.a[pre].value;
					result.a[pre].value = result.a[j].value;
					result.a[j].value = temp;
					int trow, tcol;
					trow = result.a[pre].row;
					tcol = result.a[pre].col;
					result.a[pre].row = result.a[j].row;
					result.a[pre].col = result.a[j].col;
					result.a[j].row = trow;
					result.a[j].col = tcol;
				}
			}
		}
		//对行排序
		for (int pre = 0; pre < result.terms; pre++) {
			for (int j = pre; j < result.terms; j++) {
				int minrow = result.a[pre].row;
				if (minrow > result.a[j].row) {
					T temp;
					temp = result.a[pre].value;
					result.a[pre].value = result.a[j].value;
					result.a[j].value = temp;
					int trow, tcol;
					trow = result.a[pre].row;
					tcol = result.a[pre].col;
					result.a[pre].row = result.a[j].row;
					result.a[pre].col = result.a[j].col;
					result.a[j].row = trow;
					result.a[j].col = tcol;
				}
			}
		}
		
		for (int w = 0; w < result.terms; w++) {
			for (int s = w+1; s < result.terms; s++) {
				if (result.a[w].col == result.a[s].col && result.a[w].row == result.a[s].row) {
					result.a[w].value += result.a[s].value;
					result.a[s].value = 0;
				}
			}
		}
		int finalterm = 0;
		for (int a = 0; a < result.terms; a++) {
			if (result.a[a].value != 0) {
				finalresult.a[finalterm].value = result.a[a].value;
				finalresult.a[finalterm].row = result.a[a].row;
				finalresult.a[finalterm].col = result.a[a].col;
				finalterm++;
			}
		}
		finalresult.terms = finalterm;
	}
}


