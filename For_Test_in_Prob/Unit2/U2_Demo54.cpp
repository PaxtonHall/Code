#include<iostream>
using namespace std;

int Min_Z(int A[], int n){
    int *h = new int[n]();
    for(int i=0;i<n;i++){
        if (A[i]>0&&A[i]<=n) h[A[i]-1]=1;
    }    
    for(int i=0;i<n;i++){
        if(h[i]==0) return i+1;
    }
    return n+1;
    delete[] h;
}

int main(){
    int B[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    // for (int i=0; i<15;i++){
    //     cin>>A[i];
    // }
    cout<<Min_Z(B,17);
}