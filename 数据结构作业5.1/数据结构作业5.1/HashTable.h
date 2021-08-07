#pragma once
#include<iostream>
using namespace std;

template<class E, class K>
class HashTable {
public:
	HashTable(int divisor = 11);
	~HashTable() { delete ht;  delete neverused; }
	bool Search(const K& k, E& e) const;
	void Insert(const E& e);
	void Delete(const E& e);
	void Rearrange();
	void Output();// 
private:
	int hSearch(const K& k) const;
	int m; // hash function divisor
	int numoffull;
	E *ht; // hash table array
	bool *neverused; // 1D array
};

template<class E, class K>
HashTable<E, K>::HashTable(int divisor)
{// Constructor.
	m = divisor;

	// allocate hash table arrays
	ht = new E[m];
	neverused = new bool[m];

	// set all buckets to empty
	for (int i = 0; i < m; i++)
		neverused[i] = true;
	for (int i = 0; i < m; i++) {
		ht[i] = NULL;
	}
}

template<class E, class K>
int HashTable<E, K>::hSearch(const K& k) const
{// Search an open addressed table.
 // Return location of k if present.
 // Otherwise return insert point if there is space.
	int i = k % m; // home bucket
	int j = i;     // start at home bucket
	do {
		if (neverused[j] || ht[j] == k) return j;
		j = (j + 1) % m;  // next bucket
	} while (j != i); // returned to home?

	return j;  // table full
}

template<class E, class K>
bool HashTable<E, K>::Search(const K& k, E& e) const
{// Put element that matches k in e.
 // Return false if no match.
	int b = hSearch(k);
	if (neverused[b] || ht[b] != k) return false;
	e = ht[b];
	return true;
}

template<class E, class K>
void HashTable<E, K>::Insert(const E& e)
{// Hash table insert.
	K k = e; // extract key
	int b = hSearch(k);

	// check if insert is to be done
	if (neverused[b]) {
		neverused[b] = false;
		numoffull++;
		ht[b] = e;
	}

	// no insert, check if duplicate or full
	//if (ht[b] == k)  cout<<"BadInput"<<endl; // duplicate
	
	Rearrange();
}

template<class E, class K>
void HashTable<E, K>::Delete(const E& e) {
	int b = hSearch(e);
	if (ht[b] == e) {
		ht[b] = NULL;
	}
	else {
		cout << "The element is not exit!";
	}
}

template<class E,class K>
void HashTable<E, K>::Rearrange() {
	double mid = (double)numoffull / (double)m;
	if (mid >= 0.6) { // need to rearrange
		for (int i = 0; i < m; i++)
			neverused[i] = true;
		E* tmp = new E[m];
		for (int i = 0; i < m; i++) {
			tmp[i] = ht[i];
		}
		for (int i = 0; i < m; i++) {
			if (tmp[i] != NULL) {
				int b = hSearch(tmp[i]);
				if (b != i) {
					ht[b] = tmp[i];
					ht[i] = NULL;
				}
				neverused[b] = false;
			}
		}
	}
}

template<class E,class K>
void HashTable<E, K>::Output() {
	for (int i = 0; i < m; i++) {
		if (ht[i] != NULL) {
			cout << i << ":" << ht[i] << " ";
		}
	}
	cout << endl;
}