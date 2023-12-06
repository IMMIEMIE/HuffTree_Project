#include "HuffTree.h"

int* HuffTree::SecletTwo() {//����û�и�ĸ�Ľڵ��������Сֵ���±�
    int Result[2];
    int index1 = maxroot, index2 = maxroot;
    for (int i = 0; i < RealLength; i++) {
        if (Nodes[i].parent == -1) {
            if (Nodes[i].weight <=Nodes[index1].weight) index1 = i;
        }
    }
    for (int i = 0; i < RealLength; i++) {
        if (Nodes[i].parent == -1) {
            if (Nodes[i].weight <=Nodes[index2].weight&&i!=index1) index2 = i;
        }
    }
    Result[0] = index1;
    Result[1] = index2;
    return Result;
}

void HuffTree::PrintTable() {
    cout << "=========================================\n";
    cout << "�±�\t|" << "Ȩֵ\t|" << "˫��\t|" << "����\t|" << "�Һ���\t|\n";
    cout << "=========================================\n";
    for (int i = 0; i < RealLength; i++) {
        cout << '|' << i << "\t|" << Nodes[i].weight << "\t|" << Nodes[i].parent << "\t|" << Nodes[i].lchild << "\t|" << Nodes[i].rchild << "\t|\n";
        cout << "=========================================\n";
    }
}

void HuffTree::BuildTree(int num) {
    if (num <= 100 && num > 0) {
        int index = 0; int index2 = 0;
        //��ʼ���ڵ㣻
        for (int i = 0; i < num; i++) {
            int weight;
            cout << "����ڵ��Ȩֵ��\n";
            cin >> weight;
            element NewNode;
            NewNode.weight = weight;
            NewNode.lchild = -1; NewNode.rchild = -1;
            NewNode.parent = -1;
            Nodes[i] = NewNode;
            if (Nodes[i].weight > Nodes[maxroot].weight) maxroot = i;
            length++; RealLength++;
        }
        while (RealLength != length * 2 - 1) {
            //���ɲ�����˫�׽ڵ�
            int* Arr = SecletTwo();
            int i1 = Arr[0]; int i2 = Arr[1];
            RealLength++;
            element NewNode; NewNode.weight = Nodes[i1].weight + Nodes[i2].weight;
            NewNode.lchild = i1; NewNode.rchild = i2;
            NewNode.parent = -1;
            Nodes[RealLength - 1] = NewNode;
            Nodes[i1].parent = RealLength - 1; Nodes[i2].parent = RealLength - 1;           
            if (NewNode.weight > Nodes[maxroot].weight) maxroot = RealLength - 1;
        }         
    }
    else cout << "����������������һ��100���ڵ�������\n";
}

void HuffTree::CodeTheTree() {
    cout << "���������룺\n";
    cout << "\n----------------\n";
    cout << "Ȩֵ\t|" << "����\t|\n";
    cout << "________________\n";
    for (int i = 0; i < length; i++) {
        string result = ""; stack<int> roots;       
        cout << Nodes[i].weight <<"\t|";
        int j = i;
        while (Nodes[j].parent != -1) {
            roots.push(j);
            j = Nodes[j].parent;
            if (Nodes[j].parent == -1) {
                roots.push(j);
            }
        }
        while (roots.top() != i) {
            int x = roots.top();
            roots.pop();
            if (Nodes[x].lchild == roots.top()) {
                result += '0';
            }
            else result += '1';
        }
        cout << result;
        cout<<"\t|" << '\n';
        cout << "----------------\n";
    }
}
