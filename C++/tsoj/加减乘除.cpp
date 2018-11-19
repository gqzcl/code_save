#include<iostream>
using namespace std;
int main ()
{
	int a,b,n,m=1;
	char sign;
	cin>>n;
	while(m<=n)
	{    m++;
		cin>>a>>sign>>b;
		switch(sign)
		{
			case '+': cout<<a+b<<endl;
			            break;
			case '-': cout<<a-b<<endl;
						break;
			case '*': cout<<a*b<<endl;
						break;
			case '/': cout<<a/b<<endl;
						break;
			default :   break;
			
		}
	}
	return 0;
}

