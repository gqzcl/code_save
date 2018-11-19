#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(int n){

    int c=sqrt(n)+0.5;
    for(int i=2;i<c;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
int main(){
    int n;
    int prime[5000];
    while(cin>>n){
        // int t=0;
        // for(int i=1001;i<10000;i++)
        // {
        //     if(is_prime(i))
        //         cout<<i<<endl;
        // }
        if(is_prime(n))
                 cout<<1<<endl;
    }
    return 0;
}