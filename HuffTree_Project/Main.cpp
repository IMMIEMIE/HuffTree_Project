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
	cout << "������������д�ȨҶ�ӽڵ�ĸ�����\n";
	cin >> InPutStr;
	while (!IsNumber(InPutStr)) {
		cout << "��ȷ������������֣��������������룺\n";
		cin >> InPutStr;
	}
	HuffTree Tree(stoi(InPutStr));
	Tree.PrintDetail();
	Tree.HuffCode();
	return 0;
}