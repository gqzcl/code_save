#include<iostream>
#include<cmath>
using namespace std;
int judge(int x,int n,int m)
{
	int t;
	t=n*x+m;
	for(int i=1;i<=n;i++)
		t=t*n/(n-1)+m;
	return t;
}
int main()
{
	int m,n;
	while(cin>>n>>m)
	{
		int s=pow(n-1,n)-m;
		int b=s>1?s:1;
		cout<<judge(b,n,m)<<endl;
		cout<<b<<endl;
	}
	return 0;
}

