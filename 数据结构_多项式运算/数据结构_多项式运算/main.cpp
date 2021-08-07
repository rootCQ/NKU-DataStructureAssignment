//习题一
//作业一多项式
#include <iostream>
#include<fstream>
#include <cmath>
#include <string>
using namespace std;
#define EPS 1E-6
typedef struct item {        //链表多项式类
	double coefficient;
	int power;
	struct item *next;
} *POLYNOMIAL, *pItem;
POLYNOMIAL Create(POLYNOMIAL p, double co, int po, int terms) { // 新建多项式
	pItem head;
	head = p;
	for (int i = 0; i < terms; i++)
	{
		p = p->next; if (!p->next) p->next = new item;
	}
	p->next->coefficient = co;
	p->next->power = po;
	p = p->next;
	p->next = NULL;
	return head;
}
void Sort(POLYNOMIAL head) { // 降序排列
	pItem pt, q, p = head;
	while (p->next) {
		q = p->next;
		while (q->next) {
			if (p->next->power < q->next->power) {
				pt = p->next;
				p->next = q->next;
				q->next = p->next->next;
				p->next->next = pt;
			}
			else q = q->next;
		}
		p = p->next;
	}
}
void Show(POLYNOMIAL head, ostream& out) {
	POLYNOMIAL p = head->next;
	int flag = 1;
	if (p == NULL) return;
	while (p) {
		if (flag) {
			if (p->coefficient == 0) { out << "0" << endl; break; }
			if (p->power == 0) out << p->coefficient;
			else if (p->power == 1) {
				if (p->coefficient == 1.0) out << "x ";
				else if (p->coefficient == -1.0) out << "-x ";
				else out << p->coefficient << "x ";
			}
			else if (p->coefficient == 1.0) out << "x" << p->power << " ";
			else if (p->coefficient == -1.0) out << "-x" << p->power << " ";
			else out << p->coefficient << "x" << p->power << " ";
			flag = 0;
		}
		else if (p->coefficient > 0.0 && fabs(p->coefficient) >= EPS) {
			if (p->power == 0) out << "+ " << p->coefficient << " ";
			else if (p->power == 1) {
				if (p->coefficient == 1.0) out << "+ x ";
				else out << "+ " << p->coefficient << "x ";
			}
			else if (p->coefficient == 1.0) out << "+ x" << p->power << " ";
			else out << "+ " << p->coefficient << "x" << p->power << " ";
		}
		else if (p->coefficient < 0.0 && fabs(p->coefficient) >= EPS) {
			if (p->power == 0) out << "- " << -p->coefficient << " ";
			else if (p->power == 1) {
				if (p->coefficient == -1.0) out << "- x ";
				else out << "- " << -p->coefficient << "x ";
			}
			else if (p->coefficient == -1.0) out << "- " << "x" << p->power << " ";
			else out << "- " << -p->coefficient << "x" << p->power << " ";
		}
		p = p->next;
	}
	out << endl;
}
POLYNOMIAL Copy(POLYNOMIAL A) {
	POLYNOMIAL head, t, p;
	head = t = new item;
	for (p = A->next; p; p = p->next) {
		t->next = new item;
		t->next->coefficient = p->coefficient;
		t->next->power = p->power;
		t = t->next;
	}
	t->next = NULL;
	return head;
}
POLYNOMIAL  Attach(float c, int e, POLYNOMIAL d)//连接
{
	POLYNOMIAL head, x;
	head = d;
	x = new item;
	x->next = NULL;
	x->coefficient = c; x->power = e; head->next = x;
	return head;
}
POLYNOMIAL Additive(POLYNOMIAL A, POLYNOMIAL B) { // 加
	POLYNOMIAL head, p, q, t;
	t = new item;
	t->next = new item;
	p = B; q = A;
	head = t;
	while (q->next&&p->next)
	{
		if (p->next->power == q->next->power)
		{
			t->next = new item;
			t->next->coefficient = p->next->coefficient + q->next->coefficient;
			t->next->power = q->next->power;
			p = p->next; q = q->next; t = t->next;
		}
		else if (q->next->power > p->next->power)
		{
			t = Attach(q->next->coefficient, q->next->power, t);
			q = q->next; t = t->next;
		}
		else
		{
			t = Attach(p->next->coefficient, p->next->power, t);
			p = p->next; t = t->next;
		}
	}
	while (q->next)
	{
		t = Attach(q->next->coefficient, q->next->power, t);
		q = q->next; t = t->next;
	}
	while (p->next)
	{
		t = Attach(p->next->coefficient, p->next->power, t);
		p = p->next; t = t->next;
	}
	t->next = NULL;
	Sort(head);
	return head;
}
POLYNOMIAL  Nega(POLYNOMIAL d)      //变为相反数
{
	POLYNOMIAL head;
	head = d;
	for (; d->next; d = d->next)
	{
		d->next->coefficient = -d->next->coefficient;
	}
	Sort(head);
	return head;
}
POLYNOMIAL Subtract(POLYNOMIAL A, POLYNOMIAL B) { // 减
	POLYNOMIAL head, p, q, result;
	head = result = new item;
	q = A;
	p = Nega(B);
	result = Additive(q, p);
	Sort(result);
	return result;
}
POLYNOMIAL Multiplication(POLYNOMIAL A, POLYNOMIAL B) { // 乘
	POLYNOMIAL head, t, p = new item, q = new item;
	head = t = new item;
	for (p = A->next; p; p = p->next) {
		for (q = B->next; q; q = q->next) {
			t->next = new item;
			t->next->coefficient = p->coefficient * q->coefficient;
			t->next->power = p->power + q->power;
			t = t->next;
		}
	}
	t->next = NULL;
	Sort(head);
	p = head;
	while (p->next) { // 合并同类项
		q = p->next;
		while (q->next) {
			if (p->next->power == q->next->power) {
				p->next->coefficient += q->next->coefficient;
				t = q->next;
				q->next = t->next;
				free(t);
			}
			else q = q->next;
		}
		p = p->next;
	}
	return head;
}
POLYNOMIAL DifferentialCoefficient(POLYNOMIAL A) {//微分
	POLYNOMIAL head, p, t;
	head = t = new item;
	for (p = A->next; p; p = p->next)
	{
		t->next = new item;
		t->next->coefficient = p->coefficient *p->power;
		t->next->power = p->power - 1;
		t = t->next;
	}
	t->next = NULL;
	Sort(head);
	return head;
}
POLYNOMIAL Division(POLYNOMIAL A, POLYNOMIAL B) { // 除
	ofstream outfile;
	outfile.open("outputfile.txt", ios::out);
	POLYNOMIAL head, P = A->next, Q = B->next, result, remainder = A, Mid;
	head = result = new item;
	remainder = A;
	Mid = new item;
	if (P->power < Q->power) {
		result->next->coefficient = 0; result->next->power = 0; result->next->next = NULL;
		cout << "商H(x)= ";
		Show(head, cout);
		Show(head, outfile);
		cout << "余数R(x) = ";
		Show(remainder, cout);
		Show(remainder, outfile);
		return head;
	}
	while (P->power >= Q->power)
	{
		result->next = new item;
		result->next->coefficient = P->coefficient / Q->coefficient;
		result->next->power = P->power - Q->power;
		result->next->next = NULL;
		Mid = Multiplication(B, result);
		result = result->next;
		remainder = Subtract(remainder, Mid);
		Mid = Nega(Mid);
		Sort(remainder);
		remainder = remainder->next;
		P = remainder->next;
	}
	cout << "商H(x)= ";
	Show(head, cout);
	Show(head, outfile);
	cout << "余数R(x) = ";
	Show(remainder, cout);
	Show(remainder, outfile);
	return head;
}
void input(istream& infile, double* num1, int* num2)
{
	char c;
	infile >> c;
	infile >> *num1;
	infile >> c;
	infile >> *num2;
	infile >> c;
}
void input0(istream& infile, char* a, char* b, char* d, char* e)
{
	char c;
	infile >> *a;
	infile >> *b;
	infile >> *d;
	infile >> c;
	infile >> *e;
	infile >> c;
	infile >> *e;
	infile >> c;
}
int main() {
	double num1; int num2;
	POLYNOMIAL k1, k2, k3, k4;
	char a, b, c, d;
	k1 = new item; k1->next = new item;
	int terms = 0;
	ifstream infile1("D://inputfile.txt");
	ofstream outfile;
	outfile.open("D://outputfile.txt", ios::out);
	input(infile1, &num1, &num2);
	while (1)
	{
		if (num1 == 0 && num2 == 0) break;
		k1 = Create(k1, num1, num2, terms);
		Sort(k1);
		terms++;
		input(infile1, &num1, &num2);
	}
	input(infile1, &num1, &num2);
	k2 = new item; k2->next = new item; k2->next->next = NULL; terms = 0;
	while (1)
	{
		if (num1 == 0 && num2 == 0) break;
		k2 = Create(k2, num1, num2, terms);
		Sort(k2);
		terms++;
		input(infile1, &num1, &num2);
	}
	input0(infile1, &a, &b, &c, &d);
	if ((a == 'A'&&b == 'N'&&c == 'D'&&d == '#'))      //加法
	{
		k3 = Additive(k1, k2);
		Show(k3, cout);
		Show(k3, outfile);
		infile1.close();
		outfile.close();
	}
	else if ((a == 'S'&&b == 'U'&&c == 'B'&&d == '#'))      //减法
	{
		k3 = Subtract(k1, k2);
		Show(k3, cout);
		Show(k3, outfile);
		infile1.close();
		outfile.close();
	}
	else if ((a == 'M'&&b == 'U'&&c == 'L'&&d == '#'))      //乘法
	{
		k3 = Multiplication(k1, k2);
		Show(k3, cout);
		Show(k3, outfile);
		infile1.close();
		outfile.close();
	}
	else if ((a == 'D'&&b == 'I'&&c == 'V'&&d == '#'))      //除法
	{
		k3 = Division(k1, k2);
		infile1.close();
		outfile.close();
	}
	else
	{                      //微分
		k3 = DifferentialCoefficient(k1);
		Show(k3, cout);
		Show(k3, outfile);
		k4 = DifferentialCoefficient(k2);
		Show(k4, cout);
		Show(k4, outfile);
		infile1.close();
		outfile.close();
	}
	system("pause");
	return 0;
}