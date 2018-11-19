#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		cout<<n<<':'<<endl;
		for(int i=1;i<=n;i++)
		{
			int flag=1;
			
			for(int j=0;j<i;j++)
			{
				if(flag)
				{
					cout<<'*';
					flag=!flag;
				}
				else
				{
					cout<<'-';
					flag=!flag;
				}
			}
			cout<<endl;
		}
	} 
}

