#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char arr[16];
int s[100];
int change10(char m[],int q)
{
	int i=strlen(m)-1;
	int count=0;
	int a=0;
	for(i,a;i>=0;i--,a++)
	{
		if(m[i]>='A')
			count+=((int)m[i]-55)*pow(q,a);
		else
			count+=(m[i]-'0')*pow(q,a);
	}
	return count;
}
void changeq(int p,int n)
{
	int m=0;
	while (n!=0)  
   {  
     int c=n%p;  
     n=n/p;  
     m++;
	 s[m]=c;   
   }    
   for(int k=m;k>=1;k--)
   {  
     if(s[k]>=10) 
       cout<<(char)(s[k]+55);  
     else  
       cout<<s[k];  
   }  
   cout<<endl; 
}
int main()
{
	int p,r;
	char m[70];
	while(cin>>p>>r>>m)
	{
		if(p==0&&r==0&&m[0]=='0')
			return 0;
		else
		{
			int ten=change10(m,p);
			changeq(r,ten);
		}
	}
	return 0;
}

