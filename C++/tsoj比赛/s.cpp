#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int s[124];
		s[0]=1;
		s[1]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<n;j++)
			{
				s[j]+=s[j-1];
				s[j+1]+=s[j]/10;
				s[j]%=10;
			}
		}
		for(int i=n-1;i>0;i--)
		{
			cout<<s[i];
		}
		cout<<endl;
	}
}

