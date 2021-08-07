#pragma once
#include<iostream>
using namespace std;

template<class T>
class MaxHeap {
public:
	MaxHeap(int MaxHeapSize, T maxele, T minele);
	~MaxHeap() { delete heap; }
	int Size() const { return CurrentSize; }
	T Max() {          //²é
		if (CurrentSize == 0) {
			cout << "The stack is empty" << endl;
		}
		return heap[1];
	}
	void push(T theEle);
	void pop(T theEle);
//	void Initialize(T *theHeap, int size);
	void print();
public:
	int CurrentSize, MaxSize;
	T maxElement, minElement;
	T *heap;  // element array
};

template<class T>
MaxHeap<T>::MaxHeap(int MaxHeapSize, T maxele, T minele) {
	MaxSize = MaxHeapSize;
	heap = new T[2*(MaxSize + 1)];
	CurrentSize = 0;
	maxElement = maxele;
	minElement = minele;
	heap[1] = minele;
	heap[0] = maxele;
}

template<class T>
void MaxHeap<T>::push(T theEle) {
	if (CurrentSize == 2 * MaxSize + 1) {
		T *newheap = new T[4 * (MaxSize + 1)];
		for (int i = 0; i <= CurrentSize - 1; i++) {
			newheap[i] = heap[i];
		}
		heap = newheap;
	}
	int currentNode = ++CurrentSize;
	heap[CurrentSize + 1] = maxElement;
	int half = currentNode / 2;
	while (heap[currentNode / 2] < theEle) {
		heap[currentNode] = heap[currentNode / 2];
		currentNode /= 2;
	}
	heap[currentNode] = theEle;
}

template<class T>
void MaxHeap<T>::pop(T theEle) {
	if (CurrentSize == 0) {
		cout << "The stack is empty" << endl;
	}
	else {
		T lastEle = heap[CurrentSize--];
		int currentNode = 1, child = 2;
		while (child <= CurrentSize) {
			if (heap[child] < heap[child + 1]) {
				child++;
			}
			if (lastEle >= heap[child]) {
				break;
			}
			heap[currentNode] = heap[child];
			currentNode = child;
			child *= 2;
		}
		heap[currentNode] = lastEle;
		heap[CurrentSize + 1] = maxElement;
	}
}

template<class T>
void MaxHeap<T>::print() {
	int i = 1;
	while (heap[i]  < maxElement){
		cout << heap[i] << " ";
		i++;
	}
	cout << endl;
}