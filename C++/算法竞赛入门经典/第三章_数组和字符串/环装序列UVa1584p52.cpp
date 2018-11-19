#include<iostream>
#include<cstring> 
using namespace std;
const int maxn=105;
int less1(const char* s,int p,int q)
{
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[(p+i)%n]!=s[(q+i)%n])
			return s[(p+i)%n]<s[(q+i)%n];
	}
	return 0;
}
int main()
{
	int T;
	char s[maxn];
	cin>>T;
	while(T--)
	{
		cin>>s;
		int ans=0;
		int n=strlen(s);
		for(int i=1;i<n;i++)
			if(less1(s,i,ans))
				ans=i;
		for(int i=0;i<n;i++)
			putchar(s[(i+ans)%n]);
		putchar('\n');
	}
	return 0;
}

