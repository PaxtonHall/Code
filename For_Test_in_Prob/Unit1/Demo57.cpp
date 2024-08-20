#include<iostream>
using namespace std;
#define ElemType int

typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode, *LinkList;

LinkList Intersection(LinkList L1, LinkList L2){
    LinkList L3= new LNode;
    L3->next=NULL;
    LNode *r=L1->next,*q=L2->next,*p=L3;
    while(r!=NULL && q!=NULL){
        if(r->data > q->data) q=q->next;
        else if(r->data < q->data) r=r->next;
        else if(r->data == q->data) {
            p->next = new LNode{r->data,NULL};
            r=r->next; q=q->next;
            p=p->next;
        }
    }
    p=NULL;
    return L3;
}

// 初始化链表函数（带头结点）
LinkList InitListWithHead(ElemType arr[], int size) {
    LinkList L = new LNode; // 创建头结点
    L->next = NULL;
    LNode *tail = L; // 用于保存链表的最后一个节点

    for (int i = 0; i < size; i++) {
        LNode *newNode = new LNode;
        newNode->data = arr[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }

    return L;
}

// 打印链表
void PrintList(LinkList L) {
    LNode *p = L->next; // 从头结点的下一个节点开始打印
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    ElemType arr1[] = {1, 2, 4, 6, 8,112};
    ElemType arr2[] = {2, 4, 6, 10, 12,112};

    LinkList L1 = InitListWithHead(arr1, 6);
    LinkList L2 = InitListWithHead(arr2, 6);

    cout << "List 1: ";
    PrintList(L1);

    cout << "List 2: ";
    PrintList(L2);

    LinkList L3 = Intersection(L1, L2);

    cout << "Intersection List: ";
    PrintList(L3);

    return 0;
}