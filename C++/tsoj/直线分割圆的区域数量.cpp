#include<iostream>
using namespace std;
int what(int n)
{
	int t;
	t=n*(n+1)/2+1;
	return t;
} 
int main()
{
	int n;
	while(cin>>n)
	{
		int t;
		t=what(n);
		cout<<t<<endl;
	}
	return 0;
}

