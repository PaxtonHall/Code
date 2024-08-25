#include<iostream>
#include <cstring>
using namespace std;

typedef struct node{
    char data[10];
    struct node *left, *right;
}BTree;

void print_BTree(BTree *T,int depth){
    if (T == NULL) return;
    else if (T -> left == NULL&& T->left == NULL) {cout<<T->data;return;}

    
    if(depth!=1)        cout << '(';
    if (T->left != NULL) {

        print_BTree(T->left,depth+1);
    }
    
    cout << T->data;
    
    if (T->right != NULL) {
        print_BTree(T->right,depth+1);
    }
        if(depth!=1)        cout << ')';
    

}

BTree* createNode(const char* data) {
    BTree* newNode = new BTree;
    strncpy(newNode->data, data, 9);
    newNode->data[9] = '\0';  // 确保字符串以空字符结尾
    newNode->left = newNode->right = nullptr;
    return newNode;
}

int main() {
    // 创建一个简单的表达式树：(2+3)*4
    BTree* root = createNode("*");
    root->left = createNode("+");
    root->right = createNode("4");
    root->left->left = createNode("2");
    root->left->right = createNode("3");

    // 使用树...
print_BTree(root,1);
    // 删除树（这里只是示例，实际使用时需要递归删除所有节点）
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}