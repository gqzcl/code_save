#include<iostream>
#include<cstdio> 
using namespace std;
void show(int n,int *array)
{
	for(int i=0;i<n-1;i++)
			{
				printf("%d ",array[i]);
			}
	cout<<array[n-1]<<endl;;		
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
    int ball[n];
	
	
	for(int i=0;i<n;i++)
	{
		ball[i]=i+1;
	}//初始编号 
	
	for(int q=0;q<m;q++)
	{
		

		char command;
		int RX=0,RY=0,X,Y;
		cin>>command>>RX>>RY;
		int finder;
		
		for(finder=0;finder<n;finder++)
		{
			if (ball[finder]==RX)X=finder;	
		}
		for(finder=0;finder<n;finder++)
		{
			if (ball[finder]==RY)Y=finder;	
		}//查找编号定位 
		
		
		
		
		if(command=='A')
		{
			int tem=ball[X];
			int val=Y-X;
			
			if(val>=0)
			{
				for(int t=0;t<val-1;t++)
				{
					ball[X+t]=ball[X+t+1];
				} 
				ball[Y-1]=tem;
			}
			else
			{
				val=-val;
				for(int t=0;t<val+1;t++)
				{
					ball[X-t]=ball[X-t-1];	
				}
				ball[Y]=tem;
			}
			(n,ball);	
		}
		
		
		
		
		else if(command=='B')
		{
			int tem=ball[X];
			int val=Y-X;
			
			if(val>0)
			{
				for(int t=0;t<val;t++)
				{
					ball[X+t]=ball[X+t+1];
				} 
				ball[Y]=tem;
			}
			else
			{
				val=-val;
				for(int t=0;t<val;t++)
				{
					ball[X-t]=ball[X-t-1];	
				}
				ball[Y+1]=tem;
			}
				
			(n,ball);
				
		}
		
		
		
		
		
	}show(n,ball);
}
}

