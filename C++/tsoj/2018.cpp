#include<iostream>
using namespace std;
int main()
{
	long long a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		long long e1,e2,n1,n2;
		long long count=0;
		e1=(a%2018!=0)?(b/2018-a/2018):(b/2018-a/2018+1);
		e2=(c%2018!=0)?(d/2018-c/2018):(d/2018-c/2018+1);
		n1=(a%1009!=0)?(b/1009-a/1009):(b/1009-a/1009+1);
		n2=(c%1009!=0)?(d/1009-c/1009):(d/1009-c/1009+1);
		n1-=e1;
		n2-=e2;
		//cout<<n1<<" "<<e1<<" "<<n2<<" "<<e2<<endl;
		long long hf1=(a%2!=0)?(b/2-a/2):(b/2-a/2+1),hf2=(c%2!=0)?(d/2-c/2):(d/2-c/2+1);
		long long ln1=b-a+1,ln2=d-c+1;
		//cout<<hf1<<" "<<hf2<<endl;
		count+=(hf1*n2+hf2*n1+ln1*e2+ln2*e1);
		//cout<<count<<endl;
		count-=(n1*e2+e1*n2+e2*n1);
		cout<<count<<endl;	
	}
	return 0;
}
