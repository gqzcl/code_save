#include<iostream> 
#include<cstring>
using namespace std;
static string arr1;
int main()
{
		while(cin>>arr1)
		{
		int judge=0;
		for(int i=0;i<arr1.size();i++)
		{
			if(arr1[i]=='0')
			{
				if(judge==0)
					judge=0;
				else if(judge==1)
					judge=2;
				else if(judge==2)
					judge=1;	
			}
			else if(arr1[i]=='1')
			{
				if(judge==0)
					judge=1;
				else if(judge==1)
					judge=0;
				else if(judge==2)
					judge=2;
			}
			arr1[i]=0;
		}
		if(judge==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		}
	return 0;
}
cin.get(a);
//程序占用内存过高..... 
