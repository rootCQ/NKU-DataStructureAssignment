#pragma once
#include<iostream>
using namespace std;

template<class T>
class Deque {
public:
	T *deque;
	int length;
	int size;
	int front;
	int rear;


	void Creat(int a);
	void Print();
	bool isFull();
	bool isEmpty();
	T Right();
	T Left();
	void AddLeft(T adddata);
	void AddRight(T adddata);
	void DeleteLeft();
	void DeleteRight();
};

template<class T>
void Deque<T>::Creat(int a) {
	length = 0;
	size = a;
	deque = new T[size];
	for (int i = 0; i <= size - 1; i++) {
		deque[i] = NULL;
	}
	front = 0;
	rear = 0;
}

template<class T>//polish
void Deque<T>::Print() {
	int i = front;
	while (i != rear) {
		cout << deque[i] <<" ";
		i++;
		if (i > size - 1) {
			i = i - size;
		}
	}
	cout << deque[rear] << endl;
}

template<class T>
bool Deque<T>::isFull() {
	if (length == size) {
		cout << "Yes" << endl;
		return true;
	}
	else {
		cout << "No" << endl;
		return false;
	}
}

template<class T>
bool Deque<T>::isEmpty() {
	if (length == 0) {
		cout << "Yes" << endl;
		return true;
	}
	else {
		cout << "No" << endl;
		return false;
	}
}

template<class T>
T Deque<T>::Right() {
	cout << deque[rear] << endl;
	return deque[rear];
}

template<class T>
T Deque<T>::Left() {
	cout << deque[front] << endl;
	return deque[front];
}

template<class T>
void Deque<T>::AddLeft(T adddata) {
	if (length == size) {
		cout << "Full" << endl;
	}
	else {
		if (length == 0) {
			deque[front] = adddata;
			length++;
			Print();
		}
		else {
			front--;
			if (front < 0) {
				front = size + front;
			}
			deque[front] = adddata;
			length++;
			Print();
		}
	}
}

template<class T>
void Deque<T>::AddRight(T adddata) {
	if (length == size) {
		cout << "Full" << endl;
	}
	else {
		if (length == 0) {
			deque[front] = adddata;
			length++;
			Print();
		}
		else {
			rear++;
			if (rear > size - 1) {
				rear = rear - size;
			}
			deque[rear] = adddata;
			length++;
			Print();
		}
	}
}

template<class T>
void Deque<T>::DeleteLeft() {
	if (length == 0) {
		cout << "Empty" << endl;
	}
	else {
		deque[front] = NULL;
		length--;
		if (length != 0) {
			front++;
			if (front > size - 1) {
				front = front - size;
			}
			Print();
		}
		else {
			cout << endl;
		}
	}
}

template<class T>
void Deque<T>::DeleteRight() {
	if (length == 0) {
		cout << "Empty" << endl;
	}
	else {
		deque[rear] = NULL;
		length--;
		if (length != 0) {
			rear--;
			if (rear < 0) {
				rear = rear + size;
			}
			Print();
		}
		else {
			cout << endl;
		}
	}
}