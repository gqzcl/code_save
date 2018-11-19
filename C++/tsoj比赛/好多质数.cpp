#include<iostream>
#include<cmath>
using namespace std;
bool jud(int n)
{
	int s=(sqrt(n)+0.5);
	bool flag=true;
	for(int i=2;i<=s;i++)
	{
		if(n%i==0)
			flag=false;
	}
	return flag;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int count=5;
		for(int i=4;i<n;i++)
		{
			if(jud(i))
				count+=i;
		}
		cout<<count<<endl;
	}
}

