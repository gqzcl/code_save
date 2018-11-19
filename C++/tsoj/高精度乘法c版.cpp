#include<stdio.h>
#include<string.h>
#define N 100
int a1[N+10];
int a2[N+10];
int result[2*N];
char arr1[N+10];
char arr2[N+10];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",arr1);
		scanf("%s",arr1);
		memset(a1,0,sizeof(a1));
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
		
		for(i=0;i<narr2;i++)
		{
			for(j=0;j<narr2;j++)
				result[i+j]+=a2[i]*a1[j];
		}
		
		for(i=0;i<2*N-1;i++)
		{
			if(result[i]>=10)
			{
				result[i+1]+=result[i]/10;
				result[i]%=10;
			}
		}
		bool output=false;
		for(i=2*N-1;i>=0;i--)
		{ 
			if(output)
				printf("%d",result[i]);
			else if(result[i])
			{
				printf("%d",result[i]);
				output=true;
			}
		} 
		//if(!output)
		//printf("0");	
		printf("\n");
	}
	return 0;
}
