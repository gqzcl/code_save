#include<iostream>
using namespace std;
const int N=100000007;
int f[20000+1];
int s(int n,int m)
{
	
	if(n==1||m==1) 
	{
		return 1;
	}
	if(n<1||m<1)
	{
		return 0;
	}
	if(n<m)
	{
		int t=f[n]%N; 
		return t;
	 } 
	if(n==m)
	{
		int t=1+s(n,m-1);
		return t;
	 } 
	if(n>m) 
	{
		int t=s(n-m,m)+s(n,m-1);
		return t;
	 } 
}
int main()
{
	int n;
	
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=s(i,i)%N;
		}
		cout<<f[n]<<endl;;
	}
}
