#include<iostream>
#include<cstdio>
#include<string> 
#include<algorithm> 
using namespace std;
const int maxn=10000;
int main()
{
	int n,q,x,a[maxn],kase=0;
	while(scanf("%d%d",&n,&q)==2&&n)
	{
		printf("case# %d:\n",++kase);
		//cout<<++kase<<endl;
		for(int i=0;i<n;i++)
			//scanf("%d",&a[i]);
			cin>>a[i];
		sort(a,a+n);
		while(q--)
		{
			//scanf("%d",&x);
			cin>>x;
			int p=lower_bound(a,a+n,x)-a;
			cout<<a<<endl<<a+1<<endl<<lower_bound(a,a+n,x)<<endl<<p<<endl;
			if(a[p]==x)
				//printf("%d found at %d\n",x,p+1);
				cout<<x<<"found at "<<p+1<<endl;
			else 
				//printf("%d not found\n",x);
				cout<<x<<"not found"<<endl;
		}
	}
	return 0;
}

