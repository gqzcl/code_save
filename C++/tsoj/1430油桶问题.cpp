#include<iostream>
using namespace std;
int sp(int n,int m,int *p)
{
	if(n==0)
		return 0;
	else if(p[n]==m)
		return 1;
	else 
	{
		if(sp(n-1,m-p[n],p))
			return 1;
		if(sp(n-1,m,p))
			return 1;
	}
	return 0;
}
int main()
{
	int m,n;
	while(cin>>n>>m)
	{
		int s[n+1];
		for(int i=1;i<=n;i++)
			cin>>s[i];
		if(sp(n,m,s))
			cout<<"yes"<<endl;
		else 
			cout<<"no"<<endl;
	}
}
