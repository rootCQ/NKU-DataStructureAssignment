#include"linkedMatrix.h"
#include"Element.h"
#include<iostream>
using namespace std;

int main() {
	cout << "Enter the cols and rows of first" << endl;
	int a1, a2;
	cin >> a1 >> a2;
	linkedMatrix<int> *first = new linkedMatrix<int>(a1, a2);
	first->build();
	cout << "Enter the cols and rows of second" << endl;
	int b1, b2;
	cin >> b1 >> b2;
	linkedMatrix<int> *second = new linkedMatrix<int>(b1, b2);
	second->build();
	linkedMatrix<int> *third = new linkedMatrix<int>(a1, a2);	
	char keywords;
	cout << "Please enter the keywords(+ - *);" << endl;
	cin >> keywords;
	system("cls");
	first->show();
	cout << keywords << endl;
	second->show();	
	switch (keywords)
	{
	case '+':
		first->add(second, third);
		break;
	case '-':
		first->sub(second, third);
	case'*':
		first->mul(second, third);
	default:
		break;
	}
	cout << "RESULT:" << endl;
	third->show();
	while (1);
	return 0;
}