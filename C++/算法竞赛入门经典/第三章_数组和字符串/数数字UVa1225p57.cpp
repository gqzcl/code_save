#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[10000];	
	while(cin>>s)
	{
		int m[10];
		memset(m,0,sizeof(m));
		int len=strlen(s);
		for(int i=0;i<len;i++)
			m[s[i]-'0']++;
		for(int i=0;i<9;i++)
			cout<<m[i]<<ends;
		cout<<m[9]<<endl;
	}
}

