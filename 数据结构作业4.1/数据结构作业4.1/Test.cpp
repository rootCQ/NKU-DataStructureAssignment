#include"Files.h"
#include"JosephusChain.h"
#include<iostream>
using namespace std;

void outgame(int total,int circul) {
	int all[300];
	for (int i = 0; i <= total - 1; i++) {
		all[i] = 1;
	}
	for (int i = total; i <= 299; i++) {
		all[i] = -1;
	}
	int stillalive = total;
	int num = 0;//
	int count = 1;//Êýµ½¼¸
	int start = 0;
	int out = 0;
	while (stillalive != 0){
//		start = num + 1;
		while (count <= circul) {
			if (all[num] == 1) {
				out = num;
				count++;
				num++;
			}
 			else {
				if (all[num] == 0) {
					num++;
				}
			}
			if (num > total - 1) {
				num = num - total;
			}
		}
		count = 1;
		stillalive--;
		all[out] = 0;
		cout << out+1 << " ";
	}
}

int main() {
	int n = filen();
	int m = filem();
	JosephusChain *A = new JosephusChain(n);
	A->outofgame(m);
	cout << endl;
	outgame(n, m);
	while (1);
	return 0;
}