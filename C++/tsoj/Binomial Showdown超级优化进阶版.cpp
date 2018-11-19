#include<iostream>
using namespace std;
long long sum;
int main()
{
	int k,n,m;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
			return 0;
		sum =1;
		m = m<(n-m)?m:n-m;
		for(k =1;k <= m;k++)
			sum =(sum*(n-m+k))/k;
		cout<<sum<<endl;
	}
return 0;
}
