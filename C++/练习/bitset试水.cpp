#include<iostream>
#include<bitset>
using namespace std;
int main()
{
	bitset<100> foo;
	while(cin>>foo)
	{
	unsigned long long f=foo.to_ulong();
	if(f%3==0)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	}
	return 0;
}

