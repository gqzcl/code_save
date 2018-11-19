#include<iostream>
#include<cstring> 
using namespace std;
const int maxn=100005;
int ans[maxn]; 
int main()
{
	int T,n;
	memset(ans,0,sizeof(ans));
	for(int m=1;m<maxn;m++)
	{
		int x=m,y=m;
		while(x>0)
		{
			y+=x%10;
			x/=10;
		}
		if(ans[y]==0||m<ans[y])
			ans[y]=m;
	}
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<ans[n]<<endl;
	}
}

