#include<iostream>
#include<string.h>
using namespace std;
const int N=40;
int a1[N];
int a2[N];
char arr1[N];
char arr2[N];
int main()
{
	int i,j;
	while(cin>>arr1>>arr2)
	{
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		
		int narr1=strlen(arr1);
		j=0;
		for(i=narr1-1;i>=0;i--)
			a1[j++]=arr1[i]-'0';
		
		int narr2=strlen(arr2);
		j=0;
		for(i=narr2-1;i>=0;i--)
			a2[j++]=arr2[i]-'0';
		
		for(i=0;i<narr1;i++)
		{
			a1[i]+=a2[i];
		}
		
		for(i=0;i<N;i++)
		{
			if(a1[i]>=10)
			{
				a1[i]%=10;
				a1[i+1]++;
			}
		}
		bool output=false;
		for(i=N-1;i>=0;i--)
		{ 
			if(output)
				cout<<a1[i];
			else if(a1[i])
			{
				cout<<a1[i];
				output=true;
			}
		} 
		cout<<endl;	
	}
	return 0;
}

