#include<iostream>
using namespace std;
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		int a[n],b[n];
		for(int i=0;i<n;i++)
		{
			a[i]=b[i]=i+1;
		}
		
		for(int t=2;t<=k;t++)
		{
			for(int i=0;i<n;i++)
			{
				if(a[i]%t==0)
				{
					if(b[i]!=0)
						b[i]=0;
					else
						b[i]=i+1;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
		if(b[i]!=0)
			cout<<b[i]<<endl;
		}
	}
	return 0;
}
