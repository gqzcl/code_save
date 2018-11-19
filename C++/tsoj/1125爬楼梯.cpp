#include<iostream>
using namespace std;
int stair(int n)
{
	int count=0;
	if(n==1)
		count=1;
	else if(n==2)
		count=2;
	else
		count=stair(n-1)+stair(n-2);
	return count;
}
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<stair(n)<<endl;
	}
	return 0;
}

