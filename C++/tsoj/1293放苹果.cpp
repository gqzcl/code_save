#include<iostream>
using namespace std;
int putapple(int m,int n)
{
	if(n==1||m==0)
		return 1;
	if(m<n)
		return putapple(m,m);
	else
		return putapple(m,n-1)+putapple(m-n,n);
}
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		cout<<putapple(m,n)<<endl;
	}
	return 0;
}

