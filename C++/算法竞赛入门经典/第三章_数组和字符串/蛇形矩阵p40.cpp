#include <stdio.h>
#include<string.h>
#include<iostream>
#include<iomanip>
const int N=20;
using namespace std;
int a[N][N];
int main()
{
   int n,x,y,tot=0;
   cin>>n;
   memset(a,0,sizeof(a));
   tot=a[x=0][y=n-1]=1;
   //cout<<1;
   while(tot<n*n)
   {
   	//cout<<1;
   		while(x+1<n&&!a[x+1][y])	a[++x][y]=++tot;
   		while(y-1>=0&&!a[x][y-1])	a[x][--y]=++tot;
   		while(x-1>=0&&!a[x-1][y])	a[--x][y]=++tot;
   		while(y+1<n&&!a[x][y+1])	a[x][++y]=++tot;
   }
   for(x=0;x<n;x++)
   {
   		for(y=0;y<n;y++)
   			cout<<setw(4)<<a[x][y];
   		cout<<endl;
   		cout<<endl;
   }
}
