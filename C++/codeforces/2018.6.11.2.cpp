#include<iostream>
using namespace std;
int main()
{
	string s;
	int n,q;
	while(cin>>n>>q)
	{
		cin>>s;
		int len=n-q;
		int count=0;
		for (int i=0;i<len;i++)
		{
			if(s[i]=='.')
			{
				if(s[i+q]=='1')
					s[i]='0';
				if(s[i+q]=='0')
					s[i]='1';
				if(s[i+q]=='.')
					s[i]='1',s[i+q]='0';
			}
			if(s[i]=='1')
			{
				if(s[i+q]=='1')
					count++;
				if(s[i+q]=='.')
					s[i+q]='0';
			}
			if(s[i]=='0')
			{
				if(s[i+q]=='1')
					count++;
				if(s[i+q]=='.')
					s[i+q]='1';
			}
		}
		if(count==(n-q))
			cout<<"No"<<endl;
		else
		{
			for(int i=len;i<(n-len);i++)
				if(s[i]=='.')
					s[i]='0';
			cout<<s<<endl;
		}
		
	} 
}
