#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,m,k;
    while(cin>>n>>m>>k){
        int nums[n];
        memset(nums,0,sizeof(nums));
        int j;
        for(int i=0;i<m;i++){
            cin>>j;
            nums[j-1]=1;
        }
        int s,t;
        int flag=0;
        int ll=0;
        j=1;
        for(int i=0;i<k;i++){
            cin>>s>>t;
            if(!flag){
                if(nums[t-1]&&!nums[s-1]){
                    flag=1;
                    ll=t;
                }
            }else{
                if(!nums[s-1])
                    j=t;
            }
            
        }
        if(!flag)    
            cout<<j<<endl;
        else
            cout<<ll<<endl;
    }
}