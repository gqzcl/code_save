#include<iostream>
using namespace std;
int main()
{
	int n,s;
	int arr[100];
	cin>>n;
	for(s=1;s<=n;s++)
	{
		cin>>arr[s-1];
	}
	for (int i = 0; i < n; i++)
	 {
		for (int j = 0; j < n-1-i;j++) 
		{
			if (arr[j] > arr[j+1]) 
			{
			int temp =arr[j+1];
			arr[j+1]=arr[j];
			arr[j]=temp;
			}
		}
	}
	
	cout<<sizeof(arr)<<endl;

}
