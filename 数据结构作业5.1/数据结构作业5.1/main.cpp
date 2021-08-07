#include"HashTable.h"
#include<iostream>
using namespace std;

int main() {
	HashTable<int, int> table;
	table.Insert(10);
	table.Insert(22);
	table.Insert(35);
	table.Insert(33);
	table.Output();
	table.Delete(35);
	table.Delete(1);
	table.Output();
	table.Insert(35);
	table.Output();
	table.Insert(48);
	table.Output();
	table.Insert(49);
	table.Output();
	while (1);
	return 0;
}