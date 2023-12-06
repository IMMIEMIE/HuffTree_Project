#pragma once
#include<iostream>
#include<string>
#include<stack>
using namespace std;
struct element
{
    int weight;
    int lchild, rchild, parent;
};
class HuffTree
{
private:
    int* SecletTwo();
    int maxroot = 0;
    int RealLength = 0;
    int length = 0;
    element Nodes[199];
    void PrintTable();
    void BuildTree(int num);
    void CodeTheTree();
public:
    HuffTree(int num) {
        BuildTree(num);
    }
    bool isEmpty() {
        return length == 0;
    }
    bool isFull() {
        return length == 100;
    }
    void PrintDetail() { PrintTable(); }  
    void HuffCode() { CodeTheTree(); }
};

