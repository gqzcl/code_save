#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int x,n;
	while(cin>>x>>n)
	{
		int money[n];
		for(int i=0;i<n;i++)
			cin>>money[i];
		sort(money,money+n);
		for(int i=1;i<=x;i++)
		{
			if(comb(x,money))
		}	
	} 
}

