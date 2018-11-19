#include<iostream>
using namespace std;
const int N=128;
int fact(int count,int p[])
{
	for(int i=count;i>0;)
	{
		if(i/8>0)
		{
			i-=8;
			for(int j=N-1;j>=0;j--)
				p[j]*=256;
		}
		else if(i/4>0)
		{
			i-=4;
			for(int j=N-1;j>=0;j--)
				p[j]*=16;
		}
		else if(i/2>0)
		{
			i-=2;
			for(int j=N-1;j>=0;j--)
				p[j]*=4;
		}
		else
		{
			i-=1;
			for(int j=N-1;j>=0;j--)
				p[j]*=2;
		}
		for(int j=N-1;j>=0;j--)
		{
			if(p[j]>=10)
			{
				p[j-1]+=p[j]/10;
				p[j]%=10;
			}
		}
	}
	p[N-1]-=1;
}

int print(int arr[])//Êä³öÊı×é 
{
	int flag=0;
	for(int i=0;i<N;i++)
	{
		if(flag)
			cout<<arr[i];
		else if(arr[i])
		{
			cout<<arr[i];
			flag=1;
		}
	}
	cout<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int result[N];
		for(int i=0;i<N;i++)
			result[i]=0;
		result[N-1]=1;
		fact(n,result);
		print(result);
	}
	return 0;
}

