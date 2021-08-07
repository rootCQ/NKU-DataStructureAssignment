#include"Graph.h"
#include<iostream>
using namespace std;

int main() {
	int mapsize = 6;
	int** tc;
	tc = new int*[mapsize];
	for (int i = 0; i <= mapsize - 1; i++) {
		tc[i] = new int[mapsize];
	}
	for (int i = 0; i <= mapsize - 1; i++) {
		for (int j = 0; j <= mapsize - 1; j++) {
			tc[i][j] = 0;
		}
	}
	Graph map(mapsize);
	map.addEgde(1, 2);
	map.addEgde(1, 3);
	map.addEgde(2, 3);
	map.addEgde(3, 4);
	map.addEgde(3, 6);
	map.addEgde(4, 5);
	map.addEgde(6, 5);
	map.undirectedTC(tc);
	for (int i = 0; i <= mapsize - 1; i++) {
		for (int j = 0; j <= mapsize - 1; j++) {
			cout << tc[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	while (1);
	return 0;
}