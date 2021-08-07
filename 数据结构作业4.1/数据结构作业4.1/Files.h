#pragma once
#include<fstream>
#include<iostream>
using namespace std;



int filen() {
	ifstream infile;
	string file = "imput.txt";
	infile.open(file.data());
	int n;
	infile >> n;
	if (n < 3 || n>300) {
		cout << "WRONG!" << endl;
		infile.close();
		return -1;
	}
	else {
		infile.close();
		return n;
	}

}

int filem() {
	ifstream infile;
	string file = "imput.txt";
	infile.open(file.data());
	int m;
	int n;
	infile >> n;
	infile >> m;
	if (m<1 || m>n) {
		cout << "WRONG!" << endl;
		infile.close();
		return -1;
	}
	else {
		infile.close();
		return m;
	}
}