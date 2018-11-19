#include<iostream>
using namespace std;
int f(int n)
{
	int count=0;
	while(n!=1)
	{
		if(n%2==0)
			n/=2;
		else if(n%2==1)
			n=(3*n+1)/2;
		count++; 
	}
	cout<<count<<endl;
}
int main()
{
	int n;
	while(cin>>n)
		f(n);
	return 0;
}

