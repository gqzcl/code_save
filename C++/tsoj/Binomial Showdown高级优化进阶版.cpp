#include<iostream>
using namespace std;
long long fact(long long a,long long b)
{
	long long t=1;
	if(a==b||b==0)
		t=1;
	else
		t=fact(a,b-1)*(a-b+1)/b;
	return t;
}
int main()
{
	long long a,b;
	while(cin>>a>>b)
	{
		if(a==b&&b==0)
			return 0;
		else
			cout<<fact(a,b)<<endl;
	}
	return 0;
}

