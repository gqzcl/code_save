#include<iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int count=1;
		int c,d;
		while(a!=b)
		{
			c=a<b?a:b;
			d=a>b?a:b;
			a=c;
			b=d-c;
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}

