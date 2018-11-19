#include<iostream>
using namespace std;
double pow(double a,double b)
	{
		double v=a; 
		while(b--)
		{
			v*=a;
		}
		return v;
	}
int main()
{
	double a,b;
	cin>>a>>b;
	cout<<pow(a,b)<<endl;
	
	
} 
