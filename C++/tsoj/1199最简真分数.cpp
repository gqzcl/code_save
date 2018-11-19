#include<iostream>
using namespace std;
int commom(int a,int b)
{
	int count=0;
	if(a==1&&b==1)
		return count; 
	while(b!=0)
	{
		int c=a%b;
		a=b;
		b=c;
	}
	if(a==1)
		count++;
	return count;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		else
		{
		int arr[n];
		int count1=0,count=0;
		for(int i=0;i<n;i++)
			cin>>arr[i];
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
				count+=commom(arr[i],arr[j]);
		}
		cout<<count<<endl;
		}		
	} 
	return 0;
}

