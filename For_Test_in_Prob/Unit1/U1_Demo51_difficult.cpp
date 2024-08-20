#include<iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}NODE;

void modify(NODE* L) {
    if (L == NULL || L->next == NULL) return; // 处理空链表或只有一个节点的情况

    // 1. 找到中间节点
    NODE *slow = L, *fast = L;
    while (fast->next != NULL) {
        slow = slow->next;
        fast = fast->next; if (fast->next!=NULL)fast = fast->next;
    }

    //翻转节点
    NODE *p=fast,*curr=slow->next, *next=NULL;
    while(next!=fast){
        next=curr->next;
        curr->next=fast->next;
        fast->next=curr;
        curr=next;
    }
    slow->next=fast;
    curr=L;
    while(fast!=NULL){
         slow->next=fast->next;
         fast->next=curr->next;
         curr->next=fast;
         curr=fast->next;
         fast=slow->next;
     }
}
void printList(NODE *L) {
    while (L != NULL) {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

int main() {
    // 创建测试链表 1->2->3->4->5->6
    NODE *L = new NODE{1, new NODE{2, new NODE{3, new NODE{4, new NODE{5, new NODE{6,NULL}}}}}};

    cout << "Original List: ";
    printList(L);

    // 修改链表，翻转后半部分
    modify(L);

    cout << "Modified List: ";
    printList(L);

    return 0;
}