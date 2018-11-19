#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		ll n1=(a%1009!=0)?(b/1009-a/1009):(b/1009-a/1009+1);
		ll n2=(c%1009!=0)?(d/1009-c/1009):(d/1009-c/1009+1);
		ll e1=(a%2018!=0)?(b/2018-a/2018):(b/2018-a/2018+1);
		ll e2=(c%2018!=0)?(d/2018-c/2018):(d/2018-c/2018+1);
		n1-=e1;n2-=e2;
		//cout<<n1<<" "<<e1<<" "<<n2<<" "<<e2<<endl;
		ll d1=(a%2!=0)?(b/2-a/2):(b/2-a/2+1);
		ll d2=(c%2!=0)?(d/2-c/2):(d/2-c/2+1);
		ll len1=b-a+1,len2=d-c+1;
		//cout<<d1<<" "<<len1<<" "<<d2<<" "<<len2<<endl;
		ll sum1=n1*d2+e1*len2;
		ll sum2=n2*d1+e2*len1;
		ll rsum=e1*e2+n1*e2+e1*n2;
		cout<<sum1+sum2-rsum<<endl;
	}
}
