#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int arr[n][n];
		for(int i=0;i<n;i++)
			for(int j=0;j<i+1;j++)
				cin>>arr[i][j];
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<i+1;j++)
			{
				int a=arr[i][j]+arr[i+1][j];
				int b=arr[i][j]+arr[i+1][j+1];
				arr[i][j]=a<b?a:b;
			}				
		}
		cout<<arr[0][0]<<endl;
	}
	return 0;
}

