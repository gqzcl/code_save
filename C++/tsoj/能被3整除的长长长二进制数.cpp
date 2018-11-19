#include<iostream>
#include<cstdio> 
#include<cstring>
using namespace std;
int main()
{
	char c;
	while(cin>>c)
	{
		int judge=0;
		//int m=c.length();
		for(int i=0;i<m;i++)
		{
			if(c=='0')
			{
				if(judge==0)
					judge=0;
				else if(judge==1)
					judge=2;
				else if(judge==2)
					judge=1;
			}
			else if(c=='1')
			{
				if(judge==0)
					judge=1;
				else if(judge==1)
					judge=0;
				else if(judge==2)
					judge=2;
			}
			else
				break;
		}
		if(judge==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl; 
	}
	return 0;
}

