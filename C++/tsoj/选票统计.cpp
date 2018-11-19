#include<iostream>
using namespace std;
int arr[10000];
int arr1[1000];
int main()
{
	for(int i=0;i<10000;i++)
	{
		cin>>arr[i];
		arr1[arr[i]-1]++;
		if(arr[i]==-1)
			break;
	}
	for(int i=0;i<1000;i++)
	{
		if(arr1[i]!=0)
			cout<<i+1<<" "<<arr1[i]<<endl;
	}
	return 0;
}

