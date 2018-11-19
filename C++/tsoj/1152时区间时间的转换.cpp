#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int difference(char *zone1,char *zone2)//after-before 
{
	char zone[32][5]={"UTC","GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST","MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST","PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST"};
	float time[32]={0,0,1,1,0,1,1,2,2,3,3,4,-4,-3,-3.5,-2.5,-5,-4,-6,-5,-7,-6,-8,-7,-10,-9,-8,10,11,9.5,10.5,8};//此技巧应学会 
	int i,j;
	for(i=0;strcmp(zone[i],zone1);i++);//判断条件小于0或大于零都满足 
	for(j=0;strcmp(zone[j],zone2);j++);
	return (int)((time[i]-time[j])*60);
}
int main()
{
	int n;
	while(cin>>n)
	{
	while(n--)
	{
		int hours,minute;
		char time[9];
		cin>>time;		
		if(time[0]=='n') 
		{
			hours=12;
			minute=0;
		}
		else if(time[0]=='m')
		{
			hours=0;
			minute=0;
		}
		else
		{
			sscanf(time,"%d:%d",&hours,&minute);//从time中读取 ,也可以用sstream
			hours=hours%12;
			cin>>time;
			if(time[0]=='p') hours+=12;
		}
//		switch(time[0])
//		{
//			case 'n':hours=12;
//					 minute=0;
//					 break;
//			case 'm':hours=0;
//					 minute=0;
//					 break;
//			default:sscanf(time,"%d:%d",&hours,&minute);
//					hours=hours%12;
//					scanf("%s",time);
//					if(time[0]=='p') hours+=12;
//		}

		char before[5],after[5];
		cin>>before>>after;
		int newTime;
		newTime=hours*60+minute+difference(after,before);
		if(newTime<0) newTime+=1440;
		newTime%=1440;
		switch(newTime)
		{
			case 0:		cout<<"midnight"<<endl;
			break;
			case 720:	cout<<"noon"<<endl;
			break;
			default:  
				hours=newTime/60;
				minute=newTime%60;
				if(hours==0)
					cout<<"12:"<<minute<<" a.m."<<endl;
				else if(hours<12)
					cout<<hours<<":"<<minute<<" a.m."<<endl;
				else if(hours==12)
					cout<<"12:"<<minute<<" p.m."<<endl;
				else
					cout<<hours%12<<":"<<minute<<" p.m."<<endl;
		}
	}
	}
	return 0;
}
