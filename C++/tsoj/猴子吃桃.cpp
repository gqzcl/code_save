#include<iostream>
using namespace std;
int fact(int a,int n)
{
	int t=1;
	while(n--)
	{
		t*=a;
	}
	return t;
}
int eatpeach(int t)
{
	int sum;
	sum=3*fact(2,t-1)-2;
	return sum;
} 
int main()
{
	int a;
	while(cin>>a)
	{
	cout<<eatpeach(a);
	cout<<endl;
	}
}
