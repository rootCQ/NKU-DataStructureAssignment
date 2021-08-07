#pragma once
#include"Element.h"
#include<iostream>
using namespace std;

template<class T>
class linkedMatrix {
public:
	Ele<T> *head;
	Ele<T> *tail;
	int length;
	int rows, cols;

	linkedMatrix(int r,int c);
	void remove(Ele<T>* p);
	void store(int r, int c, T data);
	void build();
	T take(int r, int c);
	void show();
	void add(linkedMatrix<T> *a, linkedMatrix<T> *result) ;
	void sub(linkedMatrix<T> *a, linkedMatrix<T> *result) ;
	void mul(linkedMatrix<T> *a, linkedMatrix<T> *result) ;
};

template<class T>
linkedMatrix<T>::linkedMatrix(int r,int c) {//几行几列的矩阵
	head = new Ele<T>;
	tail = new Ele<T>;
	head->next = tail;
	head->before = NULL;
	tail->next = NULL;
	tail->before = head;
	length = 0;
	rows = r;
	cols = c;
}

template<class T>
void linkedMatrix<T>::remove(Ele<T> *p) {
	p->before->next = p->next;
	p->next->before = p->before;
	delete p;
}

template<class T>
void linkedMatrix<T>::store(int r, int c, T data) {
	Ele<T> *storedata = new Ele<T>(r,c,data);
	if (length == 0) {
		storedata->next = tail;
		storedata->before = head;
		head->next = storedata;
		tail->before = storedata;
	}
	else {
		Ele<T> *p = head->next;
		while (p != tail->next)
		{
			if (r <= p->row || p == tail) {
				if (r < p->row || p == tail) {
					storedata->next = p;
					storedata->before = p->before;
					p->before->next = storedata;
					p->before = storedata;
					break;
				}
				else {
					for (int i = 0; i < cols; i++) {
						if (c < p->col || p == tail){
							storedata->next = p;
							storedata->before = p->before;
							p->before->next = storedata;
							p->before = storedata;
							break;
						}
						else {
							p = p->next;
						}
					}
					break;
				}
			}
			p = p->next;
		}
	}
	length++;
}

template<class T>
void linkedMatrix<T>::build() {//刚开始建立链表矩阵，数据的输入
	int r, c;
	T imput;
	int len;
	cout << "Please enter the total terms of matrix" << endl;
	cin >> len;
	for (int i = 1; i <= len; i++) {
		cout << "Enter " << i << " row,col and value" << endl;
		cin >> r;
		cin >> c;
		cin >> imput;
		this->store(r, c, imput);
	}
}

template<class T>
T linkedMatrix<T>::take(int r, int c) {
	Ele<T> *p = head;
	while (p != tail->next) {
		if (r <= p->row || p == tail) {
			if (r == p->row) {
				for (int i = 0; i < cols; i++) {
					if (c == p->col) {
						return p->value;
					}
					if (c > p->col) {
						cout << "该元素不存在！！" << endl;
						return 0;
					}
					p = p->next;

				}
			}
			else{		
				cout << "该元素不存在！！" << endl;
				return 0;
			}
		}
		p = p->next;
	}
}

template<class T>
void linkedMatrix<T>::show() {
	Ele<T> *p = this->head->next;
	cout << "Rows=" << this->rows << " , Cols=" << this->cols << endl;
	for (; p != this->tail;p=p->next) {
		cout << "(" << p->row << "," << p->col << ")=" << p->value << endl;
	}
}

template<class T>
void linkedMatrix<T>::add(linkedMatrix<T> *a, linkedMatrix<T> *result) {
	if (a->rows != this->rows || a->cols != this->cols) {
		cout << "Can not add!!" << endl;
	}
	else {
		Ele<T> *pthis = this->head->next;
		Ele<T> *pa = a->head->next;
		while (pthis != this->tail && pa != a->tail) {//没到头
			int orderthis = (pthis->row - 1)*this->cols + pthis->col;
			int ordera = (pa->row - 1)*a->cols + pa->col;
			if (orderthis < ordera) {
				result->store(pthis->row, pthis->col, pthis->value);
				pthis = pthis->next;
			}
			if (orderthis > ordera) {
				result->store(pa->row, pa->col, pa->value);
				pa = pa->next;
			}
			if (orderthis == ordera) {
				if (pthis->value + pa->value != 0) {
					result->store(pa->row, pa->col, pthis->value + pa->value);
				}
				pa = pa->next;
				pthis = pthis->next;
			}
		}
		if (pthis == this->tail) {//this到头了
			while (pa != a->tail) {
				result->store(pa->row, pa->col, pa->value);
				pa = pa->next;
			}
		}
		if (pa == a->tail) {//a到头了
			while (pthis != this->tail) {
				result->store(pthis->row, pthis->col, pthis->value);
				pthis = pthis->next;
			}
		}
	}	
}

template<class T>
void linkedMatrix<T>::sub(linkedMatrix<T> *a, linkedMatrix<T> *result) {//this - a = result
	if (a->rows != this->rows || a->cols != this->cols) {
		cout << "Can not sub!!" << endl;
	}
	else {
		Ele<T> *pthis = this->head->next;
		Ele<T> *pa = a->head->next;
		while (pthis != this->tail && pa != a->tail) {//没到头
			int orderthis = (pthis->row - 1)*this->cols + pthis->col;
			int ordera = (pa->row - 1)*a->cols + pa->col;
			if (orderthis < ordera) {
				result->store(pthis->row, pthis->col, pthis->value);
				pthis = pthis->next;
			}
			if (orderthis > ordera) {
				result->store(pa->row, pa->col, 0 - pa->value);
				pa = pa->next;
			}
			if (orderthis == ordera) {
				if (pthis->value - pa->value != 0) {
					result->store(pa->row, pa->col, pthis->value - pa->value);
				}
				pa = pa->next;
				pthis = pthis->next;
			}
		}
		if (pthis == this->tail) {//this到头了
			while (pa != a->tail) {
				result->store(pa->row, pa->col, 0-pa->value);
				pa = pa->next;
			}
		}
		if (pa == a->tail) {//a到头了
			while (pthis != this->tail) {
				result->store(pthis->row, pthis->col, pthis->value);
				pthis = pthis->next;
			}
		}
	}
}

template<class T>
void linkedMatrix<T>::mul(linkedMatrix<T> *a, linkedMatrix<T> *result) {//this*a=result
	if (this->cols != a->rows || this->rows != this->cols) {
		cout << "Can not mul!!" << endl;
	}
	else {
		Ele<T> *pthis = this->head->next;
		Ele<T> *pa = a->head->next;
		for (; pthis != this->tail; pthis = pthis->next) {//遍历所有相乘
			for (; pa != a->tail; pa = pa->next) {
				if (pthis->col == pa->row) {
					result->store(pthis->row, pa->col, pthis->value*pa->value);
				}
			}
			pa = a->head->next;
		}
		Ele<T> *pres = result->head->next;
		for (; pres != result->tail; pres = pres->next) {//排除相同的
			if (pres->row == pres->next->row&&pres->col == pres->next->col) {
				pres->value += pres->next->value;
				result->remove(pres->next);
				pres = pres->before;
				result->length--;
			}
		}
		Ele<T> *pres2 = result->head->next;
		for (; pres2 != result->tail; pres2 = pres2->next) {//排除相加后为0
			if (pres2->value == 0) {
				result->remove(pres2);
				result->length--;
			}
		}
	}
}