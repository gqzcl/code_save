#include<iostream>
#include<cstring>
using namespace std;
const int N=150;
int s[101][101][N]={0};
int ss[N];
void mult(int arr1[],int t)
{
	for(int i=0;i<N-1;i++)
	{
		ss[i]=arr1[i]*t;
	}
	for(int i=0;i<N-1;i++)
	{
		if(ss[i]>=10)
		{
			ss[i+1]+=ss[i]/10;
			ss[i]%=10;
		}
	}
}

void plus1(int arr1[],int arr2[],int arr3[])
{
	for(int i=0;i<N-1;i++)
	{
		arr3[i]=arr1[i]+arr2[i];
	}
	for(int i=0;i<N-1;i++)
	{
		if(arr3[i]>=10)
		{
			arr3[i+1]+=arr3[i]/10;
			arr3[i]=arr3[i]%10;
		}
	}
}
void s1(int x,int y)
{
	if(y==1)
	{
		s[x][y][0]=1;
	}
	else if(x==y)
	{
		s[x][y][0]=1;
	}
	else
	{
		mult(s[x-1][y],y);
		plus1(s[x-1][y-1],ss,s[x][y]);
	}
}
void print(int arr1[])
{
	int i=N-1;
	for(;arr1[i]==0;i--);
	for(;i>=0;i--)
	{
		cout<<arr1[i];
	}
	cout<<endl;
}
int main()
{
	memset(ss,0,sizeof(ss));
	memset(s,0,sizeof(s));
	int n,m;
	while(cin>>n>>m)
	{
		if(n<m)
		cout<<'0'<<endl;
		else
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<=i;j++)
				{
					s1(i,j);
				}
			}
		}
		s1(n,m);
		print(s[n][m]);
	}
}
