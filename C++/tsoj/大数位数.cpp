#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		double count=0.0;
		for(int i=1;i<=n;i++)
		{
			count+=log10(i);
		}
		cout<<(int)count+1<<endl;
	}
}

