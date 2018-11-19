#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=1,t=0;i<=n;i++,t++)
		{
			for(int j=n;j>0;j--)
			{
				if((j+t)>n)
				{
					if((j+t)%2==0)
						cout<<n*n-(2*n-j-t)*(2*n-j-t-1)/2+t-n+1<<" ";
					else
						cout<<n*n-(2*n-j-t)*(2*n-j-t+1)/2+n-t<<" ";
				}
				else if((j+t)%2==0&&(j+t)<=n)
					{
					if(j==1)
						cout<<(j+t)*(j-1+t)/2+1+t;
					else
						cout<<(j+t)*(j-1+t)/2+1+t<<" ";
					}
				else
				{
					if(j==1)
						cout<<(j+t)*(j+1+t)/2-t;
					else
						cout<<(j+t)*(j+1+t)/2-t<<" ";
				}
			}
			cout<<endl;
		}
	} 
	return 0;
}

