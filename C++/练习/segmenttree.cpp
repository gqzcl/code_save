#include<iostream>
#include<algorithm>
using namespace std;

#define MAXN 200000
#define INF 10000000+5

int nMax,nMin;//最大，最小值 

struct Node
{
    int l,r;//左，右端点 
    int nMin,nMax;//存储各个区间的最大值和最小值
}segTree[MAXN*4];

int a[MAXN];

void Build(int i,int l,int r) //结点i上的为区间(l,r)
{
    segTree[i].l=l;
    segTree[i].r=r;
    if(l==r)  //到达叶子结点 
    {
        segTree[i].nMin=segTree[i].nMax=a[l];
        return;
    } 
    int mid=(l+r)/2;
    Build(2*i,l,mid);  //到达叶节点时无须求最值
    Build(2*i|1,mid+1,r);
    segTree[i].nMin=min(segTree[2*i].nMin,segTree[2*i+1].nMin);//未到达叶节点时，取各个区间的最值
    segTree[i].nMax=max(segTree[2*i].nMax,segTree[2*i+1].nMax);
}

void Search(int i,int l,int r)//查询结点i上l-r的最大值和最小值
{
    if(segTree[i].nMax<=nMax&&segTree[i].nMin>=nMin)  //无须更新
        return;
    if(segTree[i].l==l&&segTree[i].r==r) //刚好符合
    {
        nMax=max(segTree[i].nMax,nMax);
        nMin=min(segTree[i].nMin,nMin);
        return;
    }
    int mid=(segTree[i].l+segTree[i].r)/2;//继续向下寻找
    if(r<=mid)   
        Search(i*2,l,r);
    else if(l>mid)  
        Search(i*2+1,l,r);
    else
    {
        Search(i*2,l,mid);
        Search(i*2+1,mid+1,r);
    }      
}
int main()
{
    int m,n; //m头牛，分n组
    int l,r; 
    while(cin>>m>>n)
    {
        for(int i=1;i<=m;i++)
            cin>>a[i];
        Build(1,1,m); //建树
        for(int i=1;i<=n;i++)
        {
            cin>>l>>r; //输入要查询的区间范围
            nMax=-INF;nMin=INF; //初始化最大值最小值
            Search(1,l,r); 
            cout<<nMax-nMin<<endl; 
        }    
    }   
}
