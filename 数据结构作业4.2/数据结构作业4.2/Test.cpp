#include"File.h"
#include"Delete_all.h"
#include<iostream>
using namespace std;

int main() {
	Stack<char>* stack=new Stack<char>;
	char target;
	target = readtxt<char>(stack);
	delete_all(stack, target);
	while (1);
	return 0;
}