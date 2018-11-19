#include<iostream>
#include<cstring>
using namespace std;
const int N=100;
int a1[N+10];
int a2[N+10];
int result[2*N];
char arr1[N+10];
char arr2[N+10];
int replace(char arr1[],int a1[])
{
		int narr1=strlen(arr1);
		int j=0;
		for(int i=narr1-1;i>=0;i--)
			a1[j++]=arr1[i]-'0';
	}
int calculate(int narr2,int narr1,int result[])
{
	int i,j;
	for(i=0;i<narr2;i++)
		{
			for(j=0;j<narr1;j++)
				result[i+j]+=a2[i]*a1[j];
		}
		
		for(i=0;i<2*N;i++)
		{
			if(result[i]>=10)
			{
				result[i+1]+=result[i]/10;
				result[i]%=10;
			}
		}
}
int main()
{
	while(cin>>arr1>>arr2)
	{
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(result,0,sizeof(result));
		int narr1=strlen(arr1);
		int narr2=strlen(arr2);
		replace(arr1,a1);
		replace(arr2,a2);
		calculate(narr2,narr1,result);
		bool judge=false;
		for(int i=2*N-1;i>=0;i--)
		{ 
			if(judge)
				cout<<result[i];
			else if(result[i])
			{
				cout<<result[i];
				judge=true;
			}
		} 
		if(!judge)
		cout<<'0';	
		cout<<endl;
	}
	return 0;
}
