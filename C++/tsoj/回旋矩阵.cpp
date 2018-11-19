#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int i,j,a=n,b=(a+1)/2,change=0;
		cin>>i>>j;
		for(int k=1,t=n;k<=b&&t>=b;t--,k++)
		{
			int gt=a+change;
			if(((i-k)==0&&j<=gt)||((j-k)==0&&i<=gt)||((i-t)==0&&j>=k)||((j-t)==0&&i>=k))
			{
				int start=n*n-a*a;				 
				for(int row1=k;row1<=gt;row1++)
				{	
					start++;
					if(k==i&&row1==j)//第一行 
					{
						cout<<start<<endl;
						break;
					}
					else if(row1==gt)
					{
						for(int line1=k+1;line1<=t;line1++)
						{
							start++;
							if(line1==i&&t==j)//第一列 
							{
								cout<<start<<endl;
								break;
							}
							else if(line1==t)
							{
									for(int row2=t-1;row2>=k;row2--)
									{
										start++;
										if(t==i&&row2==j)//第二行 
										{
											cout<<start<<endl;
											break;
					 					}
										else if(row2==k)
										{
											for(int line2=t-1;line2>k;line2--)
											{
												start++;
												if(k==j&&line2==i)//第二列 
												{
													cout<<start<<endl;
													break;
					 							}
											}
										}
									}			
							}
						}
					}
				}		
				break;
			}
			else
				a-=2;
			change++;
		}
	}
}
