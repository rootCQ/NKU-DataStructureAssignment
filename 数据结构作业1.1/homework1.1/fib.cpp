//coded bu CQ

#include<iostream>
#include<fstream>
using namespace std;
static unsigned long long  int F[90];
int readTxt();
int Fib(int n);

int main()
{
	int i = 0;
	while (i <= 89)
	{
		F[i] = 0;
		i++;
	}
	F[0] = 1;
	F[1] = 1;
	int n;
	n = readTxt();
	if (n != -1) {
		cout << Fib(n-1) << endl;
	}
	while (1);
	return 0;
}

int readTxt() {
	
	ifstream infile;
	string file;
	file = "D:/imput1.txt";//´æ´¢Â·¾¶
	infile.open(file.data());
	int ret = 0;
	int count = 0;
	char num='s';
	while (infile.peek() != EOF) {
		infile >> num;
		count++;
		if (count > 2) {
			cout << "WRONG" << endl;
			return (-1);
		}
		if ((int)num < 48 || (int)num > 57) {
			cout << "WRONG" << endl;
			return (-1);
		}
		if (count == 2) {
			ret = 10 * ret + (int)num-48;
		}
		else
			ret = (int)num - 48;
	}
	infile.close();
	return ret;
	
}
int Fib(int n) {
	if (n < 0 || n>90) {
		cout << "WRONG";
		return 0;
	}
	else {
		if (F[n] != 0) return F[n];
		else {
			F[n] = Fib(n - 1) + Fib(n - 2);
			return F[n];
		}
	}
}
