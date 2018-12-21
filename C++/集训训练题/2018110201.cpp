#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N=2e5+20;
double p,a[N],b[N],t[N];
int n;
bool check(double x)
{
	for(int i=1;i<=n;i++)
		t[i]=b[i];
	for(int i=1;i<=n;i++)
		t[i]-=a[i]*x;
	double cnt=0;//把负的充到0 所需要时间 
	for(int i=1;i<=n;i++)
	{
		if(t[i]<0)
			cnt+=fabs(t[i])/p;
	}
	return cnt<=x;
}
int main()
{
	while(cin>>n>>p)
	{
		double s=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a[i],&b[i]);
			s+=a[i];
		}
		double ans;
		if(p>=s)
			puts("-1");
		else
		{
			double l=0,r=9e17;//
			for(int i=0;i<150;i++)//比用eps快的多 
			{
				double mid=(l+r)/2.0;
				if(check(mid))
				{
					ans=mid;
					l=mid;
				}
				else
				r=mid;
			}
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}