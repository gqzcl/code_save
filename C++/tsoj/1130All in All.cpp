#include<iostream>
using namespace std;
int main()
{
	string s,t;
	while(cin>>s>>t)
	{
		int len=s.length();
		int len1=t.length();
		int j=0,i=0;
		for(i;i<len;i++)
		{
			while(j<len1)
			{
				if(s[i]==t[j])
				{
					j++;
					break;
				}
				else
					j++;
			}
			if(j==len1&&i<len-1)
			{
				cout<<"No"<<endl;
				break;
			}
		}
		if(i==len)
		cout<<"Yes"<<endl;
	}
 } 

