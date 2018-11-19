#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int S[n];
		int n1=n;
		int j=0;
		while(n1--)
		{
			cin>>S[j++];
		}
		bool ju[n-1];
		for(int i=0;i<n-1;i++)
		{
			ju[i]=false;
		}
		for(int i=0;i<n-1;i++)
		{
			int b=abs(S[i+1]-S[i]);
			ju[b-1]=true;
		}
		bool flag=true;
		for(int i=0;i<n-1;i++)
		{
			if(ju[i]==false)
			{
				cout<<"not jally"<<endl;
				flag=false;
				break;
			}
			
		}
		if(flag)
			cout<<"jally"<<endl;
	}
}

