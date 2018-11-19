#include<iostream>
#include<cmath>
using namespace std;
/*int pow(int a,int b)
{
	int t=1;
	while(b>0)
	{
		t*=a;
		b--;
	}
	return t;
}*/
int main()
{
	int n;
	while(cin>>n)
	{
		int b;
		if(n==1)
			b=3;
		else
			b=pow(2,n)+2*pow(-1,n+2);
		cout<<b<<endl;
	}
	return 0;
}

