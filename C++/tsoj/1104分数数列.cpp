#include<iostream>
using namespace std;
long long print(long long n)
{
	long long a=2,b=1,c;
	for(int i=1;i<n;i++)
	{
		c=a;
		a=a+b;
		b=c;		
	}
	if(n%2==0)
		cout<<-a<<"/"<<b<<endl;
	else
		cout<<a<<"/"<<b<<endl;
}
int main()
{
	long long n;
	while(cin>>n)
		print(n);
	return 0;
}

