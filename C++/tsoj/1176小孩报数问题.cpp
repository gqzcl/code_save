#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		char people[n][15];
		for(int i=0;i<n;i++)
			cin>>people[i];
		int w,s;
		scanf("%d,%d",&w,&s);
		int sum=n;
		int i=w+s-2;
		for(;;)
		{
			if(strcmp(people[i],"0")!=0)
			{
					cout<<people[i]<<endl;
				sum--;
				strcpy(people[i],"0");
				if(sum==0)
					break;					
			}
			else
			{
				i++;
				i%=n;
				continue;
			}
			i++;			
		 	for(int j=0;j<s-1;)
		 	{
		 		i%=n;
		 		if(strcmp(people[i],"0")!=0)
		 		{
		 			j++;
		 			i++;
				 }
		 		else
		 			i++;
			}
			i%=n;							 
		} 
		cout<<endl;
	}
	return 0;
}
