#include<iostream>
#include<queue>
#include"Graph.h"
using namespace std;

int main() {
	int mapsize = 6;
	Graph map(mapsize);
	map.addEgde(1, 2);
	map.addEgde(1, 3);
	map.addEgde(2, 3);
	map.addEgde(3, 4);
	map.addEgde(3, 6);
	map.addEgde(4, 5);
	map.addEgde(6, 5);
	int* resolve1;
	resolve1 = map.findPath(1,5);
	int i = 0;
	while (resolve1[i] != -1) {
		cout << resolve1[i] << " ";
		i++;
	}
	cout << endl;
	int* resolve;
	resolve = map.findPath(4, 6);
	int j = 0;
	if (resolve != NULL) {
		while (resolve[j] != -1) {
			cout << resolve[j] << " ";
			j++;
		}
		cout << endl;
	}
	else {
		cout << "No way!" << endl;
	}
	while (1);
	return 0;
}

