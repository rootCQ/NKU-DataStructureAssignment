#pragma once
#include"Deque.h"
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

template<class T>
void read_and_proceed(Deque<T> q) {
	ifstream infile;
	string file;
	file = "D:/imput.txt";//´æ´¢Â·¾¶
	infile.open(file.data());

	string s;
	stringstream ss;
	string opt;
	int i=0;
	while (1)
	{
		getline(infile, s);
		ss.clear();
		ss.str(s);
		ss >> opt;
		if (opt == "End") {
			break;
		}
		else {
			if (!ss.fail()) {
				ss >> i;
			}
		}
		if (opt == "AddLeft") {
			q.AddLeft(i);
		}
		if (opt == "AddRight") {
			q.AddRight(i);
		}
		if (opt == "IsFull") {
			q.isFull();
		}
		if (opt == "IsEmpty") {
			q.isEmpty();
		}
		if (opt == "DeleteRight") {
			q.DeleteRight();
		}
		if (opt == "DeleteLeft") {
			q.DeleteLeft();
		}
	}
	infile.close();
}
