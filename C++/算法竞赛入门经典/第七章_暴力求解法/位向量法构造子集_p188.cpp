#include<iostream>
using namespace std;
void print_subset(int n,int*B,int cur){
    if(cur==n){
        for(int i=0;i<cur;i++)
            if(B[i])
                cout<<i+1<<' ';
            cout<<endl;
        return;
    }
    B[cur]=1;//选第cur个元素
    print_subset(n,B,cur+1);
    B[cur]=0;//不选第cur个元素
    print_subset(n,B,cur+1);
}
int main(){
    int n;
    while(cin>>n){
        int B[n];
        print_subset(n,B,0);
    }
}