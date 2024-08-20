#include<iostream>
using namespace std;
#define ElemType int

typedef struct LNode{
    ElemType data;
    LNode *link;
}LNode, *LinkList;

void Del_Same(LinkList &HEAD, int n){
    int *times = new int [n]();
    LNode *q = HEAD, *next=NULL;
    while(q->link!=NULL){
        if(times[q->link->data>0 ? q->link->data : -q->link->data]==0){
            times[q->link->data>0 ? q->link->data : -q->link->data] = 1;
            q=q->link;
        }
        else {
            next=q->link;
            q->link = next->link;
            delete next;
        }
    }
}


void printList(LNode *L) {
    L=L->link;
    while (L != NULL) {
        cout << L->data << " ";
        L = L->link;
    }
    cout << endl;
}

int main() {
    // 创建测试链表 1->2->3->4->5->6
    LinkList L = new LNode{0, new LNode{2, new LNode{6, new LNode{-4, new LNode{4, new LNode{6,NULL}}}}}};

    cout << "Original List: ";
    printList(L);

    // 修改链表，翻转后半部分
    Del_Same(L,100);

    cout << "Modified List: ";
    printList(L);

    return 0;
}
