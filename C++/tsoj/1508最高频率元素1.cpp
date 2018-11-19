#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int L;
	while(cin>>L)
	{
		int a;
		vector<int> S[L];
		int size=0;
		int L1=L;
		while(L--)
		{
			cin>>a;
			bool flag=true;
			for(int i=0;i<size;i++)
			{
				if(a==S[i][0])
				{
					S[i][1]++;
					flag=false;
				}
			}
			if(flag)
			{
				S[size].push_back(a);
				S[size].push_back(1);
				size++;
			}
			
		}
		for(int i=0;i<size;i++)
		{
			if(S[i][1]>L1/2)
				cout<<S[i][0]<<endl;
		}
	}
}

