#pragma once
#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
	int num;
	int back;
	Node* next;
	Node(int n) {
		back = 0;
		num = n;
		next = NULL;
	}
};

class Graph {
private:
	Node** listpoint;
	int pointsize;
	bool rFindPath(Node* s, int* &Path, int* &reach, int destination);
	void clear();
public:
	Graph(int n);
	void addEgde(int i, int j);
	void undirectedTC(int** &tc);
	int* findPath(int source, int destination);
};

Graph::Graph(int n) {
	pointsize = n;
	listpoint = new Node*[pointsize];
	for (int i = 0; i <= n - 1; i++) {
		listpoint[i] = new Node(i + 1);
	}
}

void Graph::addEgde(int i, int j) {
	Node* add = new Node(j);
	Node* add1 = new Node(i);
	Node* tmp = listpoint[i - 1];
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = add;
	Node* tmp1 = listpoint[j - 1];
	while (tmp1->next!=NULL){
		tmp1 = tmp1->next;
	}
	tmp1->next = add1;
}

void Graph::clear() {
	for (int i = 0; i <= pointsize - 1; i++) {
		listpoint[i]->back = 0;
	}
}

bool Graph::rFindPath(Node* source, int* &Path, int* &reach, int destination) {
	reach[source->num] = 1;
	int result = 0;
	Node* tmp = new Node(-1);
	int* reverPath = new int[pointsize];
	for (int i = 0; i <= pointsize - 1; i++) {
		reverPath[i] = -1;
	}
	int length = 0;
	queue<Node*> q;
	q.push(source);
	while (!q.empty()) {
		Node* w = q.front();
		q.pop();
		Node* u = w->next;
		while (u != NULL) {
			if (reach[u->num] == 0) {
				listpoint[u->num - 1]->back = w->num;
				q.push(listpoint[u->num - 1]);
				reach[u->num] = 1;
				if (u->num == destination) {
					result = 1;
					break;
				}
			}
			u = u->next;
		}
		if (result == 1) {
			break;
		}
	}
	tmp = listpoint[destination - 1];
	if (result == 1) {
		int i = 0;
		while (tmp->back != 0) {
			reverPath[i] = tmp->num;
			i++;
			tmp = listpoint[tmp->back - 1];
		}
		int j = 2;
		for (; i >= 1; i--) {
			Path[j] = reverPath[i - 1];
			j++;
		}
	}

	if (result == 1) {
		return true;
	}
	else {
		return false;
	}
}

int* Graph::findPath(int source, int destination) {
	this->clear();
	int* Path = new int[pointsize + 1];
	for (int i = 0; i <= pointsize; i++) {
		Path[i] = -1;
	}
	Path[1] = source;
	int* reach = new int[pointsize + 1];
	for (int i = 1; i <= pointsize; i++) {
		reach[i] = 0;
	}
	Node* begin = this->listpoint[source - 1];
	if (source == destination || rFindPath(begin, Path, reach, destination)) {
		int steps = 1;
		while (Path[steps] != -1) {
			steps++;
		}
		Path[0] = steps - 2;
	}
	else {
		delete Path;
		Path = NULL;
	}
	delete reach;
	return Path;
}

void Graph::undirectedTC(int** &tc) {
	for (int i = 1; i <= pointsize; i++) {
		for (int j = i+1; j <= pointsize; j++) {
			int* resolve;
			resolve = findPath(i, j);
			if (resolve != NULL) {
				if (resolve[0] > 1) {
					tc[i - 1][j - 1] = tc[j - 1][i - 1] = 1;
				}
			}
			delete resolve;
		}
	}
}