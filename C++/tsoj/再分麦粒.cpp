#include<iostream>
#include<cstdlib>
using namespace std;
const int N=500;
void fact(int n,int p[],int q[])
{
	for(int i=1;i<=n;i++)
	{
		for(int i=N;i>0;i--)
		{
			p[i]*=2; 			
		}
		for(int i=N;i>0;i--)
		{	
			if(p[i]>=10)
			{
				p[i]%=10;
				p[i-1]++;
			}
			q[i]+=p[i];
			if(q[i]>=10)
			{
				q[i]%=10;
				q[i-1]++;
			}			
		}
	}		
}
int print(int arr[])//输出数组 
{
	for(int i=1;i<=N;i++)
		cout<<arr[i];
	cout<<endl;
}
int main()
{
	string n;
	while(cin>>n)
	{ 
		int arr[N+1];
		for(int i=0;i<N+1;i++) 
			arr[i]=0;
		arr[N]=1; 
		int arr1[N+1];
		for(int i=0;i<N+1;i++) 
			arr1[i]=0;
		arr1[N]=1;
		int a=atoi(n.c_str());//字符转整 
		fact(a-1,arr,arr1);//求a次后数组的后五百位 
		print(arr1);	
	}
	return 0;
}
