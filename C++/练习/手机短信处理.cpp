#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int mes[2][n];
		for(int i=0;i<n;i++)
		{
			cin>>mes[0][i]>>mes[1][i];
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<n-1-i;j++)
			{
				if(mes[0][j]>mes[0][j+1])
				{
					int temp=mes[0][j+1];
					mes[0][j+1]=mes[0][j];
					mes[0][j]=temp;
					temp=mes[1][j+1];
					mes[1][j+1]=mes[1][j];
					mes[1][j]=temp;
				}
			}
		}
		int sum=mes[1][0]+mes[1][1];
		
		for(int i=2;i<n;i++)
		{
			if(sum>=mes[0][i])
				sum+=mes[1][i];
			else
			{
				sum=mes[0][i];
				sum+=mes[1][i];
			}
		}
		cout<<sum<<endl;	
	}
}

