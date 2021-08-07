#pragma once
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
#define EPS 1E-6

class Polynomial {
private:
	double coefficient;
	int power;
	Polynomial *next;
public:

	friend void Create();

	void Sort(Polynomial head);
	void Show(Polynomial head);
	void Insert(Polynomial p, Polynomial h);
	double Value(Polynomial head, double x);
	Polynomial Copy(Polynomial A);
	Polynomial Additive(Polynomial A, Polynomial B);
	Polynomial Subtract(Polynomial A, Polynomial B);
	Polynomial Multiplication(Polynomial A, Polynomial B);
	Polynomial Different(Polynomial A);
	Polynomial Division(Polynomial A, Polynomial B);
}
