#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		long long s[1000];
		s[0]=1;
		int flag=0;
		long long a=2,b=3,c=5;
		long long sum1=1;
		for(int i=1;i<n;i++)
		{
			if(a<b&&a<c)
			{
				s[i]=a;
				a*=2;
			}
			else if(b<a&&b<c)
			{
				s[i]=b;
				b*=3;
			}
			else if(c<a&&c<b)
			{
				s[i]=c;
				c*=5;
			}
			sum1+=s[i]%100000;
			if(sum1>=100000)
			{
				sum1%=100000;
				flag=1;
			}
		}
		printf("%lld\n",s[n-1]);
		if(flag)
			printf("%05lld\n",sum1);
		else
			printf("%lld\n",sum1);
	}
	return 0;
}
