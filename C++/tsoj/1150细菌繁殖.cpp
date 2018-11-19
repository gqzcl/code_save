#include<iostream>
using namespace std;
const int N=180;
int months[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int days(int day1,int month1,int day2,int month2)
{
	int count=0;
	for(int i=month1;i<=month2;i++)
	{
		if(month1==month2)
			count=day2-day1;
		else if(i==month1)
			count=count+months[i-1]-day1;
		else if(i==month2)
			count+=day2;
		else
			count+=months[i-1];
	}
	return count;
}
int fact(int count,int p[])
{
	for(int i=count;i>0;)
	{
		if(i/8>0)
		{
			i-=8;
			for(int j=N-1;j>=0;j--)
				p[j]*=256;
		}
		else if(i/4>0)
		{
			i-=4;
			for(int j=N-1;j>=0;j--)
				p[j]*=16;
		}
		else if(i/2>0)
		{
			i-=2;
			for(int j=N-1;j>=0;j--)
				p[j]*=4;
		}
		else
		{
			i-=1;
			for(int j=N-1;j>=0;j--)
				p[j]*=2;
		}
		for(int j=N-1;j>=0;j--)
		{
			if(p[j]>=10)
			{
				p[j-1]+=p[j]/10;
				p[j]%=10;
			}
		}
	}
}
int print(int arr[])//Êä³öÊı×é 
{
	int flag=0;
	for(int i=0;i<N;i++)
	{
		if(flag)
			cout<<arr[i];
		else if(arr[i])
		{
			cout<<arr[i];
			flag=1;
		}
	}
	cout<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
		while(n--)
		{
			int day1,month1,day2,month2;
			string nsize;
			cin>>month1>>day1>>nsize>>month2>>day2;
			int count=days(day1,month1,day2,month2);
			int result[N];
			for(int i=0;i<N;i++) 
				result[i]=0;
			int j=nsize.length()-1;
			for(int i=N-1;j>=0;i--) 
				result[i]=nsize[j--]-'0';
			fact(count,result);
			print(result);
		}
	}
	return 0;
}

