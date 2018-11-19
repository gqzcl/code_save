#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if(j!=i)
			{
				for(int k=1;k<=9;k++)
				{
					if(k!=i&&k!=j)
					{
						a=i*100+j*10+k;
						b=a*2;
						c=a*3;
						if(c<1000)
						{
							int f=a;
							int h[9];
							int g=0;
							while(f>0)
							{								
								h[g++]=f%10;
								f/=10;
							} 
							f=b;
							while(f>0)
							{								
								h[g++]=f%10;
								f/=10;
							} 
							f=c;
							while(f>0)
							{								
								h[g++]=f%10;
								f/=10;
							} 
							int flag=1;							
							for(int d=1;d<=9;d++)
							{
								int ft=0;
								for(int l=0;l<9;l++)
								{									
									if(d==h[l])
										ft=1;
								}
								if(!ft)
									flag=0;
							}
							if(flag)
								cout<<a<<ends<<b<<ends<<c<<endl;
						}
						
					}
				}
			}
			
		}
	}
}

