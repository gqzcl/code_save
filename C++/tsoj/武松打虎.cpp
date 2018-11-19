#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	long long n,t;
	while(cin>>n>>t)
	{
		long long k[n];
		for(int i=0;i<n;i++)
			cin>>k[i];
		sort(k,k+n);
		int i=0,count=0;
		while(t>0)
		{
			t-=k[i++];
			if(t>=0)
			count++;
		}
		cout<<count<<endl;
	}
	return 0;
}

