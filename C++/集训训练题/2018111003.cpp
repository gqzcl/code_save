#include<iostream>
using namespace std;
int main()  
{  
    int n;
    while(cin>>n){
        int k=1;
        for(int i=0;i<n;i++){
            if(i%2==0)
                k*=-1;
            if(k==1)
                cout<<'a';
            else 
                cout<<'b';
        }
        cout<<endl;
    }   
    return 0;  
}