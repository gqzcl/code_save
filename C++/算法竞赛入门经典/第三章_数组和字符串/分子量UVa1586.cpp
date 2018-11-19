#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
	char s[20];
	char m[]={'C','H','O','N'};
	double mol[]={12.01,1.008,16.00,14.01};
	while(cin>>s)
	{
		double all=0;
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(s[i]==m[j])
				{
					if(isalpha(s[i+1]))
						all+=mol[j];
					else if((i+1)<len&&isdigit(s[i+1]))
					{
						double t=s[++i]-'0';
						while(isdigit(s[++i]))
						{
							t=t*10+s[i]-'0';
						}
						i--;
						all+=(mol[j]*t);
					} 
					else if(i+1>=len&&isalpha(s[i]))
						all+=mol[j];
					break;
				}
			}
		}
		cout<<all<<"g/mol"<<endl;
	}
}

