#include<iostream>
#include<algorithm>
using namespace std;
int selection(double* a,int n){
    int x;
    double min=a[0];
    for(int i=0;i<n;i++){
        if(min>=a[i]){
            min=a[i];
            x=i;
        }
    }
    return x;
}
int selection1(double* a,int n,double min){
    int x=0;
    int min1=a[0];
    for(int i=0;i<n;i++){
        if(min1>=a[i]||min<a[i]){
            min1=a[i];
            x=i;
        }
    }
    return x;
}
bool isok(double* a,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]-0<=10e5){
            count++;
        }
    }
    if(count>=1)
        return true;
    else
        return false;
}
int main(){
    int n;
    double p;
    while(cin>>n>>p){
        double a[n],b[n],pp[n],c[n];
        for(int i=0;i<n;i++){
            cin>>a[i]>>b[i];
            pp[i]=p/a[i];
            c[i]=b[i]/a[i];
        }
        double time=0;
        int j=selection(c,n);
        int k=selection1(c,n,c[j]);
        if(pp[j]<c[k]){
                time+=c[j]/pp[j];
                cout<<time<<endl;
                continue;
            }
        c[j]+=pp[j]*c[k];
        if(pp[j]>1){
            cout<<-1<<endl;
            continue;
        }
        
        time+=c[k];
        while(c[j]!=0||c[k]!=0){
            c[j]-=c[k];
            c[k]=0;           
            int j=selection(c,n);
            int k=selection1(c,n,c[j]);
            if(pp[j]<c[k]){
                time+=c[j]/pp[j];
                cout<<1;
                break;
            }
            if(pp[j]>1)
                break;
            c[j]+=pp[j]*c[k];
            time+=c[k];
            if(isok(c,n))
                break;
        }
        cout<<time<<endl;
    }
}