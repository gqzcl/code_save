#include<iostream>
using namespace std;
int main()
{
	int a,b,n,r;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		int m;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		cout<<a<<endl;
	}
	return 0;
}

