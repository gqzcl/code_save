#include<iostream>
using namespace std;
void print_subset(int n,int* A,int cur){
    for(int i=0;i<cur;i++)
        cout<<A[i]+1<<' ';
    cout<<endl;
    int s=cur?A[cur-1]+1:0;//确定当前元素的最小可能值
    for(int i=s;i<n;i++){
        A[cur]=i;
        print_subset(n,A,cur+1);//递归构造子集
    }
}
int main(){
    int n;
    while(cin>>n){
        int a[n];
        // for(int i=0;i<n;i++){
        //     cin>>a[i];
        // }
        print_subset(n,a,0);//输出的是1~n的集合的子集
    }
}