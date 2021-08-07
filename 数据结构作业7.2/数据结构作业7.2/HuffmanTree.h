#pragma once
#include"Element.h"
#include  <iostream>
# include <string>
# include <fstream>
# include <stack>
using namespace std;

const int max_size = 56;

class HuffmanTree {
private:
	int num;//文本字符总数
	int w[max_size];//权重
	element huffTree[2 * max_size - 1];
	int indexOf(char ch);
	void Select(int &i1, int &i2);
	string read_file();
	void save_code(int code_cache[], int code_cache_size);
	void CountLetter(string& str);
public:
	HuffmanTree();
//	void print();
	void condense(string str);	// 转码压缩
	void decoding();// 解码
};

//解码
void HuffmanTree::decoding() {
	string str;
	ifstream in("encodedata.txt", ios::in);
	in >> str;
	in.close();
	ofstream out("decodedata.txt", ios::out);
	int root = 2 * num - 2;
	int temp = root;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == '0') {
			if (huffTree[temp].lchild != -1) {
				temp = huffTree[temp].lchild;
				if (huffTree[temp].lchild == -1) {
					out << huffTree[temp].data;
					temp = root;
				}
			}
		}
		else {// is 0
			if (huffTree[temp].rchild != -1) {
				temp = huffTree[temp].rchild;
				if (huffTree[temp].rchild == -1) {
					out << huffTree[temp].data;
					temp = root;
				}
			}
		}
	}
	out.close();
}

//计算频率
void HuffmanTree::CountLetter(string& str) {
	int size = 52;
	char ch[52];
	int weight[52];
	num = 0;
	ch[0] = 'A';
	ch[26] = 'a';
	for (int i = 1; i < size / 2; i++) {
		ch[i] = ch[i - 1] + 1;
		ch[i + 26] = ch[i + 26 - 1] + 1;
	}
	for (int i = 0; i < size; i++) {
		weight[i] = 0;
	}
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) > 64 && str.at(i) < 91) {
			weight[str.at(i) - 'A']++;
		}
		if (str.at(i) > 96 && str.at(i) < 123) {
			weight[26 + str.at(i) - 'a']++;
		}
	}
	for (int i = 0; i < size; i++) {
		if (weight[i] != 0) {
			huffTree[num].data = ch[i];
			huffTree[num].weight = weight[i];
			w[num] = weight[i];
			num++;
		}
	}
}

string HuffmanTree::read_file() {
	string str;
	ifstream in("data.txt", ios::in);
	in >> str;
	in.close();
	return str;
}


//保存转码数据
void HuffmanTree::save_code(int code_cache[], int code_cache_size) {
	ofstream out("encodedata.txt", ios::out);
	for (int i = 0; i < code_cache_size; i++) {
		out << code_cache[i];
	}
	out.close();
}

//转码
void HuffmanTree::condense(string str) {
	int code_cache_max_size = 256;//单个字符最大编码长度
	stack<int> s;
	int code_cache[256];//存放编码的数组
	int code_cache_index = 0;//编码实际长度
	int Judge_Direction; 
	bool isOverflow = false;
	for (int i = 0; i < str.size(); i++) {
		int index = indexOf(str.at(i));
		Judge_Direction = huffTree[index].parent;
		while (Judge_Direction != -1) {
			if (index == huffTree[Judge_Direction].lchild) {
				s.push(0);
			}
			else {
				s.push(1);
			}
			index = Judge_Direction;
			Judge_Direction = huffTree[Judge_Direction].parent;
		}
		while (!s.empty()) {
			code_cache[code_cache_index++] = s.top();
			s.pop();
		}
		if (code_cache_index % code_cache_max_size == code_cache_max_size - 1) {
			save_code(code_cache, code_cache_max_size);
			code_cache_index = 0;
			isOverflow = true;
		}
	}
	if (!isOverflow) {
		save_code(code_cache, code_cache_index);
	}
}

//查找元素在数中的位置
int HuffmanTree::indexOf(char ch) {
	for (int i = 0; i < num; i++) {
		if (huffTree[i].data == ch) {
			return i;
		}
	}
	return -1;
}


// 哈夫曼算法-输出
/*
void HuffmanTree::print() {
	for (int i = 0; i < 2 * num - 1; i++) {
		cout << huffTree[i].weight << "\t" << huffTree[i].parent << "\t" << huffTree[i].lchild << "\t" << huffTree[i].rchild << endl;
	}
}
*/

//选择当前权重最小的两个元素
void HuffmanTree::Select(int &i1, int &i2) {
	int i;
	bool button = true;
	for (i = 0; i < 2 * num - 1; i++) {
		if (button) {
			if (huffTree[i].parent == -1) {
				i1 = i;
				button = false;
			}
		}
		else {
			if (huffTree[i].parent == -1) {
				i2 = i;
				break;
			}
		}

	}
	for (i = 0; i < 2 * num - 1; i++) {
		if (i2 != i && huffTree[i].parent == -1 && huffTree[i].weight > 0) {
			if (huffTree[i1].weight > huffTree[i].weight) {
				i1 = i;
			}
		}
	}
	for (i = 0; i < 2 * num - 1; i++) {
		if (i1 != i && huffTree[i].parent == -1 && huffTree[i].weight > 0) {
			if (huffTree[i2].weight > huffTree[i].weight) {
				i2 = i;
			}
		}
	}
}


 //  构造哈夫曼树
HuffmanTree::HuffmanTree() {
	string str = read_file();
	CountLetter(str);
	for (int i = 0; i < 2 * num - 1; i++) {
		huffTree[i].parent = -1;
		huffTree[i].lchild = -1;
		huffTree[i].rchild = -1;
	}
	for (int i = 0; i < 2 * num - 1; i++) {
		if (i < num) {
			huffTree[i].weight = w[i];
		}
		else {
			huffTree[i].weight = 0;
		}
	}
	for (int k = num; k < 2 * num - 1; k++) {
		int i1, i2;
		// 权重最小的两个根节点，下标为i1和i2
		Select(i1, i2);

		huffTree[i1].parent = k;
		huffTree[i2].parent = k;
		huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
		huffTree[k].lchild = i1;
		huffTree[k].rchild = i2;
	}
//	print();
	condense(str);
	decoding();
}