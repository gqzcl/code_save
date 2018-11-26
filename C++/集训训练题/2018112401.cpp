#include<iostream>
#include<string>
using namespace std;
int change(string &s,int i,int len){
    for(i;i<len;i++){
                if(s[i]!=s[len-i-1]){
                    s[i]=s[len-i-1];
                    break;
                }
            }
    return i+1;
}
int main(){
    string s;
    while(cin>>s){
        int len=s.length();
        int flag=1;
        for(int i=0;i<len;i++){
            if(s[i]!=s[len-i-1])
                flag=0;
        }
        if(flag){
            if(len%2)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }     
        else{
            int k=0;
            int flag2=1;
            while(k<len-1){
                string s3=s;
                k=change(s3,k,len);
                int flag1=1;
                for(int i=0;i<len;i++){
                    if(s3[i]!=s3[len-i-1])
                        flag1=0;
                }
                if(flag1){
                    cout<<"YES"<<endl;
                    flag2=0; 
                    break;
                }
            }
            if(flag2)
                cout<<"NO"<<endl;
        }                      
            
    }
}