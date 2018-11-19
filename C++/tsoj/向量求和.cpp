#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n],b[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>b[i];
			a[i]+=b[i];
			cout<<a[i]<<" ";
		}
		cout<<endl;	
	}
	return 0; 
}

