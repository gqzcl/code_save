#include<iostream>
using namespace std;
const int MAXSTRLEN=255;
typedef unsigned char SString[MAXSTRLEN+1];
int Index(SString S,SString T,int pos){
    int i=pos;
    int j=1;
    while(i<=S[0]&&j<=T[0]){
        if(S[i]==T[j]){
            ++i;++j;
        }else{
            i=i-j+2;j=1;
        }
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}
bool Concat(SString &T,SString S1,SString S2){
    bool uncut;
    if(S1[0]+S2[0]<=MAXSTRLEN){
        for(int i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(int i=1;i<=S2[0];i++)
            T[S1[0]+i]=S2[i];
        T[0]=S1[0]+S2[0];
        uncut=true;
    }else if(S1[0]<MAXSTRLEN){
        for(int i=1;i<=S1[0];i++)
            T[i]=S1[i];
        for(int i=S1[0]+1;i<=MAXSTRLEN;i++)
            T[i]=S2[i-S1[0]];
        T[0]=MAXSTRLEN;
        uncut=false;
    }else{
        for(int i=0;i<=MAXSTRLEN;i++)
            T[i]=S1[i];
        uncut=false;
    }
    return uncut;
}
int main(){
    SString T,S1,S2;
    S1[0]=10;
    S2[0]=10;
    for(int i=1;i<=10;i++)
        cin>>S1[i];
    for(int i=1;i<=10;i++)
        cin>>S2[i];
    if(Concat(T,S1,S2)){
        for(int i=1;i<=T[0];i++)
            cout<<T[i];
    }
    cout<<endl;
    cout<<Index(S1,S2,0)<<endl;
}