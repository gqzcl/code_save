#include<iostream>
using namespace std;
int main()
{
	char arr[11];
	int a[11];
	while(cin>>arr)
	{
		for(int i=0;i<11;i++)
		{
			a[i]=arr[i]-'0';
		}
		int b=600000+10000*a[6]+1000*a[7]+100*a[8]+10*a[9]+a[10];
		cout<<b<<endl;
	}
	return 0;
}

