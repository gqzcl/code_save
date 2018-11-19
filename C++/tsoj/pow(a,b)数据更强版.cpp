#include<iostream>
#include<cstring>
using namespace std;
const int N=210;
char arr1[N];
int pow(int,int);
int main()
{
	while(cin>>arr1)
	{
	int narr1=strlen(arr1);
	int c=0;
	int b=arr1[narr1-2]-'0';
	if((arr1[narr1-3])!=','){
		c=10*(arr1[narr1-3]-'0');
		b+=c;
	}
	int a;
	for(int i=4;i<=105;i++)
	{
		if(arr1[i]==','){
			a=arr1[i-1]-'0';
			break;
			}
	}
	a%=10;
	if(b!=0&&b%4==0)
		b=4;
	else 
		b%=4;
    cout << pow(a,b)%10<< endl;
	}
	return 0;
}
int pow(int a,int b)
{
	int t=1;
	while(b--)
	{
		t*=a;
	}
	return t;
} 

