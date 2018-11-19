#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[80];
	while(cin>>s)
	{
		int len=strlen(s);
		int p=1,q=0;
		int all=0;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='O')
				all+=p++;
			if(s[i]=='X')
			{
				all+=q;
				p=1;
			}
		}
		cout<<all<<endl;
	}
}

