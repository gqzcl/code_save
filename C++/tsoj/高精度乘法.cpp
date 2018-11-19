#include<iostream>
#include<string.h>
using namespace std;
const int N=100;
int a1[N+10];
int a2[N+10];
int result[2*N];//存储结果 
char arr1[N+10];
char arr2[N+10];
int main()
{
	int i,j;
	while(cin>>arr1>>arr2)
	{
		memset(a1,0,sizeof(a1));//数组取零 
		memset(a2,0,sizeof(a2));
		memset(result,0,sizeof(result));
		
		int narr1=strlen(arr1);
		j=0;
		for(i=narr1-1;i>=0;i--)
			a1[j++]=arr1[i]-'0';
		
		int narr2=strlen(arr2);
		j=0;
		for(i=narr2-1;i>=0;i--)
			a2[j++]=arr2[i]-'0';
		
		for(i=0;i<narr2;i++)//相乘 
		{
			for(j=0;j<narr2;j++)
				result[i+j]+=a2[i]*a1[j];
		}
		
		for(i=0;i<2*N;i++)//进位 
		{
			if(result[i]>=10)
			{
				result[i+1]+=result[i]/10;
				result[i]%=10;
			}
		}
		bool output=false;
		for(i=2*N-1;i>=0;i--)//注意越界问题，第一次取成了i=2*N 
		{ 
			if(output)
				cout<<result[i];
			else if(result[i])
			{
				cout<<result[i];
				output=true;
			}
		} 
		if(!output)
		cout<<'0';	
	}
	return 0;
}
