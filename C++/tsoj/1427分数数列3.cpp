#include<iostream>
#include<cstring>
using namespace std;
char s[10000];
int a[5000];
int main()
{
	int n;
	while(cin>>n)
	{
		int max=1;
		memset(s,0,sizeof(s));
		a[1]=1;
		s[2]=s[1]=1;
		int t=1;
		for(int i=2;i<=n;i++)
		{
			while(s[t]!=0)
			{
				t++;
			}
			s[t]=1;
			a[i]=t;
			s[t+i]=1;
			if(a[max]*(t+i)<(a[max]+max)*t)
				max=i;
		} 
		cout<<a[n]<<'/'<<a[n]+n<<endl;
		cout<<a[max]<<'/'<<a[max]+max<<endl;
		int emax=1;
		for(emax;emax<=n;emax++)
		{
			if(a[emax]*(a[max]+max)==(a[emax]+emax)*a[max]&&emax!=max)
				cout<<a[emax]<<'/'<<a[emax]+emax<<endl;
		}
	}
} 
