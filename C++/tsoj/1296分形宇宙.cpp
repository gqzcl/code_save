#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
const int N=100;
char s[N][N];
int main()
{
	int n;
	while(cin>>n)
	{
		int t=pow(3,n-1);		
		memset(s,0,sizeof(s));
		s[0][0]='X';
		for(int k=2;k<=n;k++)
		{
			int h=pow(3,k-1);
			int s1=h/3,s2=2*h/3;
			int p1=0,p2=0;
			for(int i=s1;i<s2;i++)//中间 
			{
				for(int j=s1;j<s2;j++)
					s[i][j]=s[p1][p2++];
				p2=0;
				p1++;				
			}
			p1=0,p2=0;
			for(int i=0;i<s1;i++)//右上 
			{
				for(int j=s2;j<h;j++)
					s[i][j]=s[p1][p2++];
				p2=0;
				p1++;				
			}
			p1=0,p2=0;
			for(int i=s2;i<h;i++)//左下 
			{
				for(int j=0;j<s1;j++)
					s[i][j]=s[p1][p2++];
				p2=0;
				p1++;				
			}
			p1=0,p2=0;
			for(int i=s2;i<h;i++)//右下 
			{
				for(int j=s2;j<h;j++)
					s[i][j]=s[p1][p2++];
				p2=0;
				p1++;				
			}
		}
		for(int i=0;i<t;i++)
		{
			for(int j=0;j<t;j++)
				cout<<s[i][j];
			cout<<endl;
		}
		cout<<'-'<<endl;
	}
	return 0;
}
