#include<iostream>
using namespace std;
int sor(int n)
{
	int a,b,c,d,f;
	d=n%10;
	n/=10;
	c=n%10;
	n/=10;
	b=n%10;
	n/=10;
	a=n;
	if(a<=b) a^=b^=a^=b;
	if(a<=c) a^=c^=a^=c;
	if(a<=d) a^=d^=a^=d;
	if(b<=c) b^=c^=b^=c;
	if(b<=d) b^=d^=b^=d;
	if(c<=d) c^=d^=c^=d;
	int maxn=a*1000+b*100+c*10+d;
	int minn=d*1000+c*100+b*10+a;
	return maxn-minn;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int count=0;
		while(n!=6174)
		{
			n=sor(n);
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}

