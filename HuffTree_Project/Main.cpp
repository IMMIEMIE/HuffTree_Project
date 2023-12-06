#include<iostream>
#include<string>
#include"HuffTree.h"
using namespace std;
bool IsNumber(string in) {
	bool result = 1;
	for (int i = 0; i < in.length(); i++) {
		if (in[i] > '9' || in[i] < '0') {
			result = 0;
			break;
		}
	}
	return result;
}
int main() {
	string InPutStr;
	cout << "输入哈夫曼树中带权叶子节点的个数：\n";
	cin >> InPutStr;
	while (!IsNumber(InPutStr)) {
		cout << "请确保输入的是数字！在这里重新输入：\n";
		cin >> InPutStr;
	}
	HuffTree Tree(stoi(InPutStr));
	Tree.PrintDetail();
	Tree.HuffCode();
	return 0;
}