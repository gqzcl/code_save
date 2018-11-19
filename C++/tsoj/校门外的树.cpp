#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int L,M;
	while(cin>>L>>M)
	{
		int road[L+1];
		int count=0;
		memset(road,0,sizeof(road));
		while(M--)
		{
			int a,b;
			cin>>a>>b;
			for(int i=a-1;i<b;i++)
				road[i]=1;	
		}
		for(int i=0;i<=L;i++)
		{
			if(road[i]==0)
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}

