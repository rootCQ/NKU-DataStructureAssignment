#pragma once
#include<iostream>
using namespace std;

class TreeNode {
public:
	char oper;
	TreeNode *left;
	TreeNode *right;
	TreeNode(){
		left = right = NULL;
		oper = 0;
	}
	TreeNode(char op){
		left = right = NULL;
		oper = op;
	}
};