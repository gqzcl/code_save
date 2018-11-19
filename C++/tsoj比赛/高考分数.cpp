#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			int s;
			int t[20];
			int i=0;
			while(cin>>s&&s!=-1)
			{
				t[i++]=s;
			}
			sort(t+3,t+i,compare);
			int all=0;
			for(int j=0;j<6;j++)
			{
				all+=t[j];
			}
			cout<<all<<endl;
		}
	 } 
}

