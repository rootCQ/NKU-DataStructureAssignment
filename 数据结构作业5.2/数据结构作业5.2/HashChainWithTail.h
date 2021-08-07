#pragma once
#include<iostream>
#include"SortedChain.h"
using namespace std;

template<class E, class K>
class ChainHashTable {
public:
	ChainHashTable(int divisor = 11)
	{
		m = divisor; 
		ht = new SortedChain<E, K>[m];
	}
	~ChainHashTable() { delete ht; }
	bool Search(const K& k, E e) const
	{
		return ht[k % m].DistrictSearch(k, e);
	}
	ChainHashTable<E, K>& Insert(const E& e)
	{
		ht[e % m].DistrictInsert(e);
		return *this;
	}
	ChainHashTable<E, K>& Delete(const K& k, E e)
	{
		ht[k % m].DistrictDelete(k, e); 
		return *this;
	}
	void Output() const  // output the table
	{
		for (int i = 0; i < m; i++) {
			cout << i << ":" ;
			ht[i].DistrictOutput();
			cout << endl;
		}
	}
private:
	int m;                 // divisor
	SortedChain<E, K>* ht;  // array of chains
};
