#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a,b;
    while(cin>>a>>b){
        vector<int> S;
        int i=1;
        while(a>0){
            S.push_back(i);
            a-=i;
            i++;
            if(i>b)
                break;
        }
        int m;
        while(a>b){
            int c=a/b;
            a=a%b;
            m=fact(c);
        }
        if(a==0){
            //S.push_back(a);
        }
        else    
            S.push_back(a);
        cout<<S.size()+m<<endl;
    }
}