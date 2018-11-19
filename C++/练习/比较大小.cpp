#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main()
{
	int a,n;
	srand(time(0));
	a=rand()%99+1;
	do
	{
		cout<<"please input a number"<<endl;
		cin>>n;
		if (n==a)
			{
				cout<<"you are right"<<endl;
				break;
			}
		else 
		{
			if (n<a)
			cout<<"what you guess is small"<<endl;
			if (n>a)
			cout<<"what you guess is big"<<endl;
		}
	}while(1);3
	
} 
