#include<iostream>
using namespace std;
int main()
{
	string s;
	while(cin>>s)
	{
		int len=s.length()-1;
		int flag=1;
		for (int i=1;i<len;i++)
		{
		 if(s[i]=='A')
			{
				if((s[i-1]=='B'&&s[i+1]=='C')||(s[i-1]=='C'&&s[i+1]=='B'))
				{
					flag=0;
					cout<<"Yes"<<endl;
					break;
				}
			}
			
			if(s[i]=='B')
			{
				if((s[i-1]=='A'&&s[i+1]=='C')||(s[i-1]=='C'&&s[i+1]=='A'))
				{
					flag=0;
					cout<<"Yes"<<endl;
					break;
				}
			}
			
			if(s[i]=='C')
			{
				if((s[i-1]=='B'&&s[i+1]=='A')||(s[i-1]=='A'&&s[i+1]=='B'))
				{
					flag=0;
					cout<<"Yes"<<endl;
					break;
				}
			}
			
		}
		if(flag)
			{
				cout<<"No"<<endl;
				
			}
	} 
}

