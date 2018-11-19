#include<iostream>
#include<cmath>
using namespace std;
long long a[65];
long long t[64];
void fun()
{
	a[0]=0;
	a[1]=1;
	a[2]=3;
	a[3]=5;
	a[4]=9;
	for(int i=0;i<64;i++)
		t[i]=pow(2,i)-1;
	for(int n=5;n<=64;n++)
	{
		for(int k=n/2+1;k>0;k--)
		{
			int l=n-1-k;
			long long s=(2*a[l]+2*t[k]+1);
			if(k==n/2+1)
				a[n]=s;
			a[n]=a[n]<s?a[n]:s;
		}
	}
}
int main()
{
	int n;
	fun();
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}
}
