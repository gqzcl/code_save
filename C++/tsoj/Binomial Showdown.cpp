#include<iostream>
using namespace std;
int fact(int a,int b)
{
	int t=1;
	if(a==b||b==0)
		return 1;
	else
		t=fact(a-1,b)+fact(a-1,b-1);
	return t;
		
} 
int main()
{
	int n,k;
	while(cin>>n>>k)
	{
		if(n==k&&k==0)
			return 0;
		else
			cout<<fact(n,k)<<endl;
	}

	return 0;
}

