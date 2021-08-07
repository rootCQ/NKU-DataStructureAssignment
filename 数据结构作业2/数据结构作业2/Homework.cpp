#include"Functions.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
	cout << "请选择链表中储存数据的类型" << endl;
	cout << "A:整型" << endl;
	cout << "B:字符型" << endl;
	char form;
	cin >> form;

	cout << endl;
	cout << "请选择要检查的作业题号" << endl;
	cout << "A:第17题" << endl;
	cout << "B:第21题" << endl;
	cout << "C:第22题" << endl;
	char number;
	cin >> number;

	system("cls");

	if (form == 'A' || form == 'a') {  //整型
		test<int> (number);
	}
	else if(form == 'B' || form == 'b') {  //字符型
		test<char>(number);
	}
	else {
		cout << "请输入正确选项" << endl;
	}
	while (1);
	return 0;
}
