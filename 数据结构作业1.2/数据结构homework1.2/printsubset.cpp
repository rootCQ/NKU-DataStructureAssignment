#include<fstream>
#include<iostream>
using namespace std;
void print_subset(int point,int n);
int readTxt();
char set[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
int state[26] = { 0 };
int main() {
	int n;
	n = readTxt();
	print_subset(n-1,n);
	while (1);
	return 0;
}
int readTxt() {

	ifstream infile;
	string file;
	file = "D:/imput2.txt";//´æ´¢Â·¾¶
	infile.open(file.data());
	int ret = 0;
	int count = 0;
	char num = 's';
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
			ret = 10 * ret + (int)num - 48;
		}
		else
			ret = (int)num - 48;
	}
	infile.close();
	return ret;

}
void print_subset(int point,int n) {
	if (n > 26 || n < 1) {
		cout << "WRONG";
		return;
	}
	if (point < 0) {
		for (int i = 0; i <= n - 1; i++) {
			if (state[i] != 0) {
				cout << set[i];
			}
		}
		cout << endl;
	}
	else {
		state[point] = 1;
		print_subset(point - 1, n);
		state[point] = 0;
		print_subset(point - 1, n);
	}
}




