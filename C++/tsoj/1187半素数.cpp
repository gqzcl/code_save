#include<iostream>
#include<cmath>
using namespace std;
int prime(int n)
{
	int judge=1;
	int s=sqrt(n);
	if(n==2||n==3)
		return judge;
	else
	{
		for(int i=2;i<=s;i++)
			if(n%i==0)
				judge=0;
	}
	return judge;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int t=sqrt(n)+1;
		for(int i=2;i<=t;i++)
		{
			if(prime(i))
			{
				if(n%i==0)
					if(prime(n/i))
					{
						cout<<"Yes"<<endl;
						break;
					}
			}
			if(i==t)
				cout<<"No"<<endl;
		}
	}
	return 0;
}

