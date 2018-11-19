#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=7;
char p1[N], q1[N], r1[2*N];
int p[N],q[N],r[2*N];
int result[2*N];
void replace(char p1[],int p2[])
{
	memset(p2,0,sizeof(p2));
	cin>>p1;
	int strl=strlen(p1);
	int j=0;
	for(int i=strl-1;i>=0;i--)
		p2[j++]=p1[i]-'0';
}
int mult(int p[],int q[],int B)
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			result[i+j]+=q[j]*p[i];
	}
	for(i=0;i<2*N;i++)
	{
		if(result[i]>=B)
		{
			result[i+1]+=result[i]/B;
			result[i]%=B;
		}
	}
}
int compare(int a[],int b[])
{
	bool comp=true;
	for(int i=0;i<2*N;i++)
	{
		if(a[i]!=b[i])
		{
			comp=false;
			break;
		}
	}
	return comp;
}
int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		replace(p1,p);
		replace(q1,q);
		replace(r1,r);
		memset(result,0,sizeof(result));
		bool comp;
		for(int B=2;B<17;B++)
		{
			mult(p,q,B);
			comp=compare(result,r);
			if(comp)
			{
				cout<<B<<endl;
				break;
			}
			memset(result,0,sizeof(result));
		}
			
		if(!comp)
			cout<<0<<endl;
	}
	return 0;
}

