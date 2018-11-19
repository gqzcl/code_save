#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[10000];
	while(cin>>s)
	{
		int len=strlen(s);
		bool ff=true;
		for(int i=0;i<len;i++)
		{
			if(s[i]!=0)
			{
				bool flag=true;
				for(int j=i+1;j<len;j++)
				{
					if(s[j]!=0&&s[j]==s[i])
					{
						flag=false;
						s[j]=0;
					}
				}
				if(flag)
				{
					ff=false;
					cout<<s[i];
				}
			}
		}
		if(ff)
			cout<<-1;
		cout<<endl;
	}
}

