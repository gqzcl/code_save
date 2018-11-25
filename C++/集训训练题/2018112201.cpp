#include<iostream>
using namespace std;
int main(){
    int m,n;
    while(cin>>m>>n){
        int a[n][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cin>>a[i][j];
            }
        }
        int b[n][n];
        for(int i=0;i<n;i++){
            b[a[i][0]][a[i][1]]=a[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(b[i][j]>0){
                    cout<<1<<endl;
                }
            }
        }


    }
}