#include<iostream>
using namespace std;
int main()
{
	int a,b,m,n;
	while(cin>>m>>n)
	{
		if(n%2==0)
		{
			a=2*m-n/2;
			b=n/2-m;
			if(a>=0&&b>=0)
				cout<<a<<" "<<b<<endl;
			else
				cout<<-1<<" "<<-1<<endl;	
		}
		else
			cout<<-1<<" "<<-1<<endl;
	}
	return 0;
}

