#include"Deque.h"
#include"readTxt.h"
#include<iostream>
using namespace std;

int main() {
	Deque<int> q;
	q.Creat(10);
	/*
	q.AddLeft(1);
	q.AddLeft(2);
	q.DeleteRight();
	q.isFull();
	q.DeleteLeft();
	q.isEmpty();
	q.AddRight(3);
	q.AddLeft(2);
	q.AddRight(1);*/
	read_and_proceed(q);
	while (1);
	return 0;
}