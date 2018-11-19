#include<iostream>
#include<algorithm>
using namespace std;
void print_permutation(int n,int *p,int *A,int cur){
    if(cur==n){
        for(int i=0;i<n;i++)
            cout<<A[i];
        cout<<endl;
    }
    else for(int i=0;i<n;i++)
        if(!i||p[i]!=p[i-1]){           
            int c1=0,c2=0;
            for(int j=0;j<cur;j++)
                if(A[j]==p[i])
                    c1++;
            for(int j=0;j<n;j++)
                if(p[i]==p[j])
                    c2++;
            if(c1<c2){
                A[cur]=p[i];
                print_permutation(n,p,A,cur+1);
            }
        }
}
int main()
{
    int n;
    while(cin>>n){
        int p[n],a[n];
        for(int i=0;i<n;i++){
            cin>>p[i];
        }
        sort(p,p+n);
        print_permutation(n,p,a,0);
    }
    return 0;
}
