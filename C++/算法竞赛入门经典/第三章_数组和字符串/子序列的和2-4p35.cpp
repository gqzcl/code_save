#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
const int N=1000000000;
int main()
{
	int m,n;
	while(cin>>n>>m)
	{
		if(n==0&&m==0)
			break;
		double x=0;
		for(int i=n;i<=m;i++)
		{
			x+=(1.0/(double)i)*(1.0/(double)i);			
		}
		printf("%.5lf\n",x);
	} 
} 

