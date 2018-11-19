#include<iostream>
#include<algorithm>
long long pow(int a,int b)
{
	long long s=1;
	while(b--)
	{
		s*=a;
	}
	return s;
}
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int j=0;
		long long a[1000];
		a[0]=1;
		int t=1;
		int flag=0;
		int s;
		for(int sum1=1;;sum1++)
		{
			for(int i=sum1;i>=0;i--)
			{
				if(pow(2,i)*pow(3,sum1-i)<=n)
				{
					a[t]=pow(2,i)*pow(3,sum1-i);
					t++;
				}
				if(pow(2,sum1)*pow(3,0)>n)
				{
					flag=1;
					break;
				}
			}
			s=sum1;
			if(flag)
				break;			
		}
		cout<<t<<endl;
//		cout<<s<<endl;
		sort(a,a+t-1);
//		for(int i=0;i<m;i++)
//			cout<<a[i]<<endl;
		cout<<a[m-1]<<endl;
	}
}
