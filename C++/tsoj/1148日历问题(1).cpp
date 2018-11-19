#include<iostream>
#include<cstdio>
using namespace std;
char weeks[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday "};
int months1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int months2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int year(int &n,int &yearchange)
{
	while(n>365)
	{
		if((yearchange%4==0&&yearchange%100!=0)||yearchange%400==0)
		{
			n-=366;
			yearchange++;
		}
		else
		{
			n-=365;
			yearchange++;
		}
	}
	cout<<(2000+yearchange)<<"-";
}
int month(int &n,int &yearchange)
{
	int monthchange=1;
	if((yearchange%4==0&&yearchange%100!=0)||yearchange%400==0)
		{
			while(n>=months2[monthchange-1])
			{
				if(monthchange==2)
				{
					n-=months2[monthchange-1];
					monthchange++;
				}
				else
				{
					n-=months2[monthchange-1];
					monthchange++;
				}
			}
		}
	else
	{
		while(n>=months1[monthchange-1])	
		{														
			n-=months1[monthchange-1];
			monthchange++;
		}
	}
	printf("%02d-",monthchange);
}
int main()
{
	int n;
	while(cin>>n)
	{
		int c=n;
		int yearchange=0;
		if(n==-1)
			return 0;
		else
		{
			year(n,yearchange);
			month(n,yearchange);
			printf("%02d ",n+1);
		}
		if(c==0)
			cout<<weeks[6]<<endl;
		else
			cout<<weeks[(c-1)%7]<<endl;
	} 
	return 0;
}

