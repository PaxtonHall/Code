#include<iostream>
using namespace std;
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

LNode *front, *rear=NULL;

void creatList(LinkList &L){
    L = new LNode {0,L};
    front=rear=L;
}
int fullorempty(LinkList L){
    //1 means full; 2 means empty; 3means neither;
    if (front==rear) return 1;
    else if (rear->next==front) return 2;
    else return 3;
}
void insert(LinkList &L, int e){
    if (fullorempty(L)==1) {
        LNode *p = new LNode{0,L}; 
        rear ->next = p;
    }
    rear->data = e;
    rear = rear->next;
}

int out(LinkList &L){
    if(fullorempty(L)==2) return;
    int e = front->data;
    front = front->next;
    return e;
}