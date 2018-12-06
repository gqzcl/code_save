#include<iostream>
#include<cmath>
using namespace std;
const int Mod=1000000007;
int as(int x,int i,int n){
    int ans=1;
    while(i>0){ 
        if(i%2){
            ans*=x;
            ans%=n;
        }
        i>>1;
        x*=x;
        x%=n;
    }
    return ans;
}
int main(){
    long long n;
    while(cin>>n){
        int flag=1;
        for(int i=1;i<10;i++){
            cout<<as(2,i,n)<<endl;
            if(as(2,i,n)%n==1){
                printf("2^%d mod %lld = 1\n",i+1,n);
                flag=0;
                break;
            }
        }
        if(flag){
            printf("2^? mod %lld = 1\n",n);
        }
    }
}