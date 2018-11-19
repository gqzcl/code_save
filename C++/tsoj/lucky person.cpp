#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			return 0;
		else
		{
			int stu[3][n];
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<n;j++)
				{
					cin>>stu[i][j];
				}
			}
			
			for(int i=0;i<n;i++)
			{
				bool flag=false;
				for(int j=0;j<n;j++)
				{
					if(stu[0][i]==stu[1][j])
						flag=true;
				}
				if(!flag)
					stu[0][i]=0;
				else
					flag=false;
			}
			for(int i=0;i<n;i++)
			{
				bool flag=false;
				if(stu[0][i]!=0)
				{
					for(int j=0;j<n;j++)
					{
						if(stu[0][i]==stu[2][j])
							flag=true;
					}
					if(!flag)
						stu[0][i]=0;
					else
						flag=false;
				}			
			}
			sort(stu[0],stu[0]+n);
			for(int i=0;i<n;i++)
			{
				if(i==(n-1))
				{
					if(stu[0][i]!=0)
						cout<<stu[0][i];
				}
				else if(stu[0][i]!=0)
					cout<<stu[0][i]<<" ";
			}
			cout<<endl;
		}
	}
}

