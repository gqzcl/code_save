#include<iostream>
using namespace std;
int main()
{
	string str;
	while(cin>>str)
	{
		int nstr=str.length();
		int count=0,sum1=0,sum=0;
		for(int i=0;i<nstr;i++)
		{
			if(str[i]>='0'&&str[i]<='9')
			{
				sum=10*sum+(str[i]-'0');
			}
			else if(str[i]=='+')
			{
				//count=0;
				sum1+=sum;
				sum=0;
			}
			if(i==nstr-1)
				sum1+=sum;
		}
		cout<<sum1<<endl;
	}
	return 0;
}

