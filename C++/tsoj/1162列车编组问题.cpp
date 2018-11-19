#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int car[n+1];
		stack<int> S;
		int a=1,b=1;
		for(int i=1;i<=n;i++)
		{
			cin>>car[i];
		}
		bool flag=true;
		while(b<=n)
		{
			if(a==car[b])
			{
				a++;
				b++;
			}
			else if(!S.empty()&&S.top()==car[b])
			{
				S.pop();
				b++;
			}
			else if(a<=n)
			{
				S.push(a++);
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(flag)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}

