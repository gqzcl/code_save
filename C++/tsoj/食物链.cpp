#include<iostream>
using namespace std;
int n=0;
int count=0;
void Lookfor(int j,int *a)
{
	int flag=0;
	for(int i=0;i<2*n;i+=2)
	{
		if(a[i]==j)
		{
			Lookfor(a[i+1],a);
			flag=1;
		}
	}
	if(!flag)
		count++;
}
bool search(int s,int *b)
{
	bool flag=true;
	for(int i=1;i<2*n;i+=2)
	{
		if(s==b[i])
		{
			flag=false;
			break;
		}
	}
	return flag;
} 
int main()
{
	int m;
	while(cin>>m>>n)
	{
		count=0;
		int chain[2*n];
		for(int i=0;i<n;i++)
			cin>>chain[2*i]>>chain[2*i+1];
		for(int i=0;i<2*n;i+=2)
		{
			if(search(chain[i],chain))
			{
				Lookfor(chain[i+1],chain);
			}
		}
		cout<<count<<endl;
	} 
}

