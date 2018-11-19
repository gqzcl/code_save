#include<iostream>
using namespace std;
const int N=50;
int p[N];
int mult(int p[],int b)
{
	int i;
	cin>>p[0];
	for(i=0;i<N;i++)
	{
		if(p[i]>=b)
		{
			p[i+1]+=p[i]/b;
			p[i]%=b;
		}
	}
}

int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		mult(p,6);
		for(int i=N-1;i>=0;i--)
		{
			if(p[i]!=0)
			{
				for(int t=i;t>=0;t--)
					cout<<p[t];
				break;
			}
		}
		for(int i=N-1;i>=0;i--)
		{
			p[i]=0;
		}
		cout<<endl;
			
	}
	return 0;
}

