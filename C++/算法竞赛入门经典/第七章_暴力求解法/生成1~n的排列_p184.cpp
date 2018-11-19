#include<iostream>
using namespace std;
void print_permutation(int n,int *A,int cur){
    if(cur==n){
        for(int i=0;i<n;i++)
            cout<<A[i];
        cout<<endl;
    }
    else for(int i=1;i<=n;i++){
            int ok=1;
            for(int j=0;j<cur;j++)
                if(A[j]==i)
                    ok=0;
            if(ok){
                A[cur]=i;
                print_permutation(n,A,cur+1);
            }
        }
}
int main()
{
    int n;
    while(cin>>n){
        int p[n];
        print_permutation(n,p,0);
    }
    return 0;
}
