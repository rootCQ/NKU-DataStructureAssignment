#include"MaxHeap.h"
#include<iostream>
using namespace std;

int main() {
	MaxHeap<int> h(10,100,-1);
	h.push(2);
	h.push(5);
	h.push(4);
	h.push(1);
	h.print();
	h.pop(5);
	h.print();
	while (1);
	return 0;
}