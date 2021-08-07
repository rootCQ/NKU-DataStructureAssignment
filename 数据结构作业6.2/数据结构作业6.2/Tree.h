#pragma once
#include"TreeNode.h"
#include<iostream>
#include<stack>
using namespace std;

class Tree {
public:
	TreeNode *root;
	bool isOper(char op);
	int getOperPri(char op);
	void generateTree(TreeNode *p,string expr);
	void display(TreeNode *root,int n);
};

bool Tree::isOper(char op) {
	char oper[] = { '(',')','+','-','*','/','^' };
	for (int i = 0; i < sizeof(oper); i++){
		if (op == oper[i]){
			return true;
		}
	}
	return false;
}

int Tree::getOperPri(char op) {
	switch (op){
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '^':
		return 4;
	default:
		return 0;
	}
}

void Tree::display(TreeNode *nod,int n) {
	if (nod == NULL) {
		return;
	}
	else {
		display(nod->right, n + 2);
		for (int i = 0; i < n; i++) {
			cout << " ";
		}
		cout << nod->oper << endl;
		display(nod->left, n + 2);
	}
}

void Tree::generateTree(TreeNode *p,string expr) {
	stack <char> operStack;
	stack <TreeNode*> dataStack;
	char tmpchr, c;
	int idx = 0;

	tmpchr = expr[idx++];
	while (operStack.size() != 0 || tmpchr != '\0')
	{
		if (tmpchr != '\0' && !isOper(tmpchr)){//不是运算符，则进操作数的栈
			p = new TreeNode(tmpchr);
			dataStack.push(p);
			tmpchr = expr[idx++];
		}
		else{
			switch (tmpchr){
			case '('://进栈
				operStack.push('(');
				tmpchr = expr[idx++];
				break;
			case ')'://脱括号
				while (true){
					c = operStack.top();
					operStack.pop();
					if (c == '('){
						break;
					}
					p = new TreeNode(c);
					if (dataStack.size()){
						p->right = dataStack.top();
						dataStack.pop();
					}
					if (dataStack.size()){
						p->left = dataStack.top();
						dataStack.pop();
					}
					dataStack.push(p);
				}
				tmpchr = expr[idx++];
				break;
			default:
				if (operStack.size() == 0 || tmpchr != '\0' && getOperPri(operStack.top()) < getOperPri(tmpchr)){//进栈
					operStack.push(tmpchr);
					tmpchr = expr[idx++];
				}
				else{//出栈
					p = new TreeNode(operStack.top());
					p->oper = operStack.top();
					if (dataStack.size()){
						p->right = dataStack.top();
						dataStack.pop();
					}
					if (dataStack.size()){
						p->left = dataStack.top();
						dataStack.pop();
					}
					dataStack.push(p);
					operStack.pop();
				}
				break;
			}
		}
	}
	p = dataStack.top();
	dataStack.pop();
}