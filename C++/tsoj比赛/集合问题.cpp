#include<iostream>
using namespace std;
const int N=10000007;
long long k[100000];
int main()
{
	k[1]=1;
	k[2]=2;
	for(int i=3;i<100000;i++)
	{
		k[i]=k[i-1]+k[i-2]+1;
		k[i]%=N;
	}
	int n;
	while(cin>>n)
	{
		cout<<k[n]<<endl;;
	}
	return 0;
}

