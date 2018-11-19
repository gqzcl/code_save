#include<iostream>
using namespace std;
long long fact(int a,int b)
{
	long long t=1;
	while(b--)
	{
		t*=a;
	}
	return t;
}
int main()
{
	int n,a,b,i;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		long long s=0; 
		for(i=1;i<=a;i++)
		{
			s+=fact(i,b);
		}
		s%=10000;
		cout<<s<<endl;
	}
	return 0;
}

