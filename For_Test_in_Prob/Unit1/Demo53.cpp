#include<iostream>
using namespace std;
#define ElemType char

typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode, *LinkList;

int Calc_Length(LinkList L){
    int length=0;
    LNode *l = L;//->next;
    while(l!=NULL){
        l=l->next;
        length++;
    }
    return length;
}

LNode* Same_Place(LinkList &str1, LinkList &str2){
    LNode *p=str1 , *q=str2;
    int length1 = Calc_Length(str1);
    int length2 = Calc_Length(str2);
    if(length1>length2){
        for(int i=0; i<length1-length2; i++) p=p->next;
    }
    else{
        for(int i=0; i<length2-length1; i++) q=q->next;
    }
    while(p!=NULL && q!=NULL && p!=q){
        p=p->next; q=q->next;
    }
    return p;
}
void printList(LNode *L) {
    while (L != NULL) {
        cout << L->data << " ";
        L = L->next;
    }
    cout << endl;
}

int main(){

// 创建共享的节点
LNode* sharedG = new LNode{'g', NULL};
LNode* sharedN = new LNode{'n', NULL};
LNode* sharedI = new LNode{'i', NULL};

// 创建 "loading" 链表
LNode* loadingList = new LNode{'l', 
                        new LNode{'o', 
                            new LNode{'a', 
                                new LNode{'d', 
                                    sharedI}}}};
sharedI->next = sharedN;
sharedN->next = sharedG;

// 创建 "being" 链表
LNode* beingList = new LNode{'b', 
                        new LNode{'e', 
                            sharedI}};
// 注意：sharedI, sharedN, sharedG 的连接已经在 "loading" 链表中设置



printList(loadingList);printList(beingList);
cout<<Same_Place(loadingList,beingList)->data;
}