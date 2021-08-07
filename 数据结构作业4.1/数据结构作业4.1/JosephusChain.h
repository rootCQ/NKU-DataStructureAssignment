#pragma once
#include"Member.h"
#include<iostream>
using namespace std;

class JosephusChain {
public:
	Member *head;
	int stillalive;

	JosephusChain();
	JosephusChain(int total);
	void remove(Member *a);
	void outofgame(int m);
};

JosephusChain::JosephusChain() {
	head = new Member();
	stillalive = 0;
}

JosephusChain::JosephusChain(int total) {
	stillalive = total;
	head = new Member();
	Member *temp = head;
	for (int i = 1; i <= total; i++) {
		temp->next = new Member(i);
		temp = temp->next;
	}
	temp->next = head;
}

void JosephusChain::remove(Member *a) {
	stillalive--;
	Member *abefore = head->next;
	while (abefore->next != a) {
		abefore = abefore->next;
	}
	abefore->next = a->next;
	delete a;
}

void JosephusChain::outofgame(int m){
	Member *temp = head;
	while (stillalive != 0) {
		for (int i = 1; i <= m - 1; i++) {
			temp = temp->next;
			if (temp == head) {
				temp = temp->next;
			}
		}
		if (temp->next == head) {
			temp = temp->next;
		}
		cout << temp->next->order << " ";
		this->remove(temp->next);
	}
}