#pragma once
#include<iostream>
using namespace std;

class Member {
public:
	Member *next;
	int order;
	Member() {
		order = 0;
	}
	Member(int ord) {
		order = ord;
	}
};