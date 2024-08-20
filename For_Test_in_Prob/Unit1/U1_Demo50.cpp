//计算三元组中最小距离
#include<iostream>
#include<cmath>
using namespace std;
#define MaxSize 5000
typedef int ElemType;

typedef struct{
    ElemType data [MaxSize];
    int length;
}SqList;

int Calc_Distance(SqList A, SqList B, SqList C){
    //距离等于两倍的最大值到最小值的距离
    int min = INT_MAX;
    int i, j, k = 0;
    int distance;
    while(i<A.length && j<B.length && k<C.length){
        distance=abs(A.data[i]-B.data[j]) + abs(A.data[i]-C.data[j]) + abs(C.data[i]-B.data[j]);
        if(distance<min) min = distance;
        if(A.data[i] < B.data[j] && A.data[i] < C.data[j]) i++;
        else if (B.data[i] < A.data[j] && B.data[i] < C.data[j]) j++;
        else k++;
    }
    return min;
}

void init(SqList &List){
    List.length=0;
}
void add(SqList &List, ElemType Elem){
    List.data[List.length]=Elem;
    List.length++;
}

int main(){
    SqList A,B,C;
    init(A);init(B);init(C);
    for(int i = 1; i<10; i=i+2) add(A,i);
    for(int i = 0; i<18; i=i+5) add(B,i);
    for(int i = 0; i<30; i=i+3) add(C,i);
    cout<<Calc_Distance(A,B,C);
}