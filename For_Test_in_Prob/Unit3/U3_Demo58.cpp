#include<iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 1000
typedef struct{
    int SqBiTNode[MAX_SIZE];
    int ElemNum;
}SqBiTree;
bool tree(SqBiTree bt,int i){
    if(i<bt.ElemNum&&bt.SqBiTNode[i]!=-1){
        if(i*2+1<bt.ElemNum) { 
            if(bt.SqBiTNode[2*i+1]>bt.SqBiTNode[i]&&bt.SqBiTNode[i] && bt.SqBiTNode[2*i+1]!=-1) 
            return false;
            if(!tree(bt,2*i+1))
            return false;
        }
        if(i*2+2<bt.ElemNum)  {
            if(bt.SqBiTNode[2*i+2]<bt.SqBiTNode[i]&&bt.SqBiTNode[i] && bt.SqBiTNode[2*i+2]!=-1) 
            return false;
            if(!tree(bt,2*i+2))
            return false;
        }
    }
    return true;
}

void printTree(const SqBiTree& bt) {
    cout << "树的结构：" << endl;
    for (int i = 0; i < bt.ElemNum; i++) {
        if (bt.SqBiTNode[i] == -1) {
            cout << "- ";
        } else {
            cout << bt.SqBiTNode[i] << " ";
        }
    }
    cout << endl;
}

void checkAndPrintTree(const vector<int>& nodes, const string& description) {
    SqBiTree bt;
    bt.ElemNum = nodes.size();
    for (int i = 0; i < bt.ElemNum; i++) {
        bt.SqBiTNode[i] = nodes[i];
    }

    cout << description << endl;
    printTree(bt);
    if (tree(bt, 0)) {
        cout << "该树满足条件。" << endl;
    } else {
        cout << "该树不满足条件。" << endl;
    }
    cout << endl;
}

int main() {
    // 示例1：满足条件的树
    vector<int> tree1 = {5, 3, 7, 1, 4, 6, 8};
    checkAndPrintTree(tree1, "示例1：满足条件的树");

    // 示例2：不满足条件的树（左子节点大于父节点）
    vector<int> tree2 = {5, 6, 7, 1, 4, 6, 8};
    checkAndPrintTree(tree2, "示例2：不满足条件的树（左子节点大于父节点）");

    // 示例3：不满足条件的树（右子节点小于父节点）
    vector<int> tree3 = {5, 3, 4, 1, 4, 6, 8};
    checkAndPrintTree(tree3, "示例3：不满足条件的树（右子节点小于父节点）");

    // 示例4：包含空节点的树
    vector<int> tree4 = {5, 3, 7, -1, 4, -1, 8};
    checkAndPrintTree(tree4, "示例4：包含空节点的树");

    return 1;
}