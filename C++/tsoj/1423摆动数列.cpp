#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n];
		a[0]=1;
		int max=1;
		for(int i=1;i<n;i++)
		{
			if((i+1)%2==0)
			{
				a[i]=a[(i+1)/2-1]+1;
				max=max>a[i]?max:a[i];
			}
			else
			{
				a[i]=a[(i+1)/2-1]+a[(i+1)/2];
				max=max>a[i]?max:a[i];
			}
		}
		cout<<a[n-1]<<endl;
		for(int i=1;i<n;i++)
		{
			if(a[i]==max)
				cout<<i+1<<" ";
		}	
		cout<<endl;
	} 
	return 0;
}

