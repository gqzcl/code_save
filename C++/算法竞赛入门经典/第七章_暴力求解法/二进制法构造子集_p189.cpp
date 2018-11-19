#include<iostream>
using namespace std;
void print_subset(int n,int s){
    for(int i=0;i<n;i++)
        if(s&(1<<i))
            printf("%d ",i+1);
        printf("\n");
}
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n){
        for(int i=0;i<(1<<n);i++)
            print_subset(n,i);
    }    
    return 0;
}
