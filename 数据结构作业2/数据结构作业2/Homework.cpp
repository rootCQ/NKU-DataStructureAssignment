#include"Functions.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
	cout << "��ѡ�������д������ݵ�����" << endl;
	cout << "A:����" << endl;
	cout << "B:�ַ���" << endl;
	char form;
	cin >> form;

	cout << endl;
	cout << "��ѡ��Ҫ������ҵ���" << endl;
	cout << "A:��17��" << endl;
	cout << "B:��21��" << endl;
	cout << "C:��22��" << endl;
	char number;
	cin >> number;

	system("cls");

	if (form == 'A' || form == 'a') {  //����
		test<int> (number);
	}
	else if(form == 'B' || form == 'b') {  //�ַ���
		test<char>(number);
	}
	else {
		cout << "��������ȷѡ��" << endl;
	}
	while (1);
	return 0;
}
