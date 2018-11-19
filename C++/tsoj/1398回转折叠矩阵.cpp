#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int arr[n][n];
		for(int i=0;i<n;i++)
		{
			int count=i*i;
			if((i+1)%2==0)
			{
				for(int k=0;k<=i;k++)
				{
					count++;
					arr[k][i]=count;
					if(k==i)
					{
						for(int t=i-1;t>=0;t--)
						{
							count++;
							arr[i][t]=count;
						}
					}
				}
			}
			if((i+1)%2==1)
			{
				for(int k=0;k<=i;k++)
				{
					count++;
					arr[i][k]=count;
					if(k==i)
					{
						for(int t=i-1;t>=0;t--)
						{
							count++;
							arr[t][i]=count;
						}
					}
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j==(n-1))
					cout<<arr[i][j]<<endl;
				else
					cout<<arr[i][j]<<" ";
			}
		}
	}
	return 0;
}

