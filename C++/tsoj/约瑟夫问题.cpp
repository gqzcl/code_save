#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int people[n];
		for(int i=0;i<n;i++)
			people[i]=i+1;
		int sum=n;
		int i=m-1;
		for(;;)
		{
			if(people[i]!=0)
			{
				if(sum==1)
					cout<<people[i];
				else
					cout<<people[i]<<" ";
				sum--;
				people[i]=0;
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
		 	for(int j=0;j<m-1;)
		 	{
		 		i%=n;
		 		if(people[i]!=0)
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


