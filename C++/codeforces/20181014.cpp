#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n+1];
		a[1]=0;
		for(int i=2;i<=n;i++)
		{
			cin>>a[i];
		}
		int j=n;
		int k=0;
		while(j!=1)
		{
			k=a[j];
			a[j]=0;	
			j=k;		
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
				cout<<i<<" ";
		}
		cout<<endl;
	}
}

