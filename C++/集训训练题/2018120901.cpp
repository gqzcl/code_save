#include<iostream>
using namespace std;
int main(){
    int n,m,k;
    while(cin>>n>>m>>k){
        int nums[n];
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        int flag=0;
        int j=m;
        int dis=0;
        if(j<n){
            for(j;j<n;j++){
                if(nums[j]!=0&&nums[j]<=k){
                    dis+=10;
                    flag=1;
                    break;
                }else
                    dis+=10;
            }
        }
        int min=10000;
        if(flag)        
            min=dis;
        dis=0;
        j=m-2;
        flag=0;
        if(j>=0){
            for(j;j>=0;j--){
                if(nums[j]!=0&&nums[j]<=k){
                    dis+=10;
                    flag=1;
                    break;
                }else{
                    dis+=10;
                }
                
            }
        }
        
        if(dis>0&&flag)
            min=min<dis?min:dis;
        cout<<min<<endl;
    }
}