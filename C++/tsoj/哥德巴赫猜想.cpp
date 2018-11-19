#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=2;i<n;i++)//从2开始寻找符合条件的数 
		{
			for(int t=2;t<=sqrt(i);t++)//判断i是不是素数 
			{
				if(i%t==0)
					i=0;
			}
			if(i==0)//如果i不是素数，本次循环结束，进行下次循环 
				break;
			if(i!=0&&(n-i)!=1)//如果i是素数，判断n-i是不是素数 
			{
				int k=n-i;
				for(int t=2;t<=sqrt(k);t++)//判断 
				{
					if(k%t==0)
						k=0;
				}
				if(k!=0)//如果n-i不是素数，则找到了两个素数，输出 
					cout<<i<<"+"<<k<<endl;	
			}
		}
	}
	return 0;
}

