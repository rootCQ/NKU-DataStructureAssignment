#include"HashChainWithTail.h"
#include<iostream>
using namespace std;

int main() {
	ChainHashTable<int, int> table;
	cout << "After insert" << endl;
	table.Insert(35);
	table.Insert(46);
	table.Insert(22);
	table.Insert(57);
	table.Insert(15);
	table.Output();
	cout << table.Search(15,15) << endl;
	cout << "After delete" << endl;
	table.Delete(35, 35);
	table.Delete(15, 15);
	table.Output();
	cout << table.Search(15, 15) << endl;
	while (1);
	return 0;
}