#include<iostream>
using namespace std;
int pow(int a,int b)
{
	int c=1;
	while(b>0)
	{
		if(b%2==1)
			c=(c*a)%10000;
		b/=2;
		a=(a*a)%10000;
	}
	return c;
 } 
int print(int a,int b)
{
	int c=0;
	for(int i=1;i<=a;i++)
	{
		c+=pow(i,b);
		c%=10000;
	}
	cout<<c<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			int a,b;
			while(cin>>a>>b)
			{
				print(a,b);
			}
		}
	}
	return 0;
}

