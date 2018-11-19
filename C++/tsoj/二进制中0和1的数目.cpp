#include<iostream>
using namespace std;
int a[1];
int main()
{
	while(cin>>a[0])
	{
		int one=0,zero=0;
		while(a[0]>0)
		{
			if(a[0]%2==1)
			{
				one++;
				a[0]/=2;
			}
			else if(a[0]%2==0)
			{
				zero++;
				a[0]/=2;
			}
		}
		cout<<one<<endl<<zero<<endl;
	}
	return 0;
}

