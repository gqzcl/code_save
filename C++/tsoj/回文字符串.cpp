#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		char po[100];
		int x=0;
		gets(po);
		x=strlen(po);
		
    int val=0,v1=0;
    if(((x)%2)==0)
     {
    	val=(x)/2;
    	for(int q=0;q<=val-1;q++)
    		{
    			if(po[q]==po[x-1-q])
    				v1++;
			}
		if(v1==val)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;		
	 }
	 
	else 
 	 {
 	 	val=(x-1)/2;
 	 	for(int q=0;q<=val-1;q++)
    		{
    			if(po[q]==po[x-1-q])
    				v1++;
			}
		if(v1==val)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	 }
	}
	return 0; 
 } 
