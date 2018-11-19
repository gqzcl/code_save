#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char arr[1000];
int main()
{
	int n;
	char c;
	cin>>n;
	c=getchar();
	while(n--)
	{
		gets(arr);
		for(int i=strlen(arr)-1;i>=0;i--)
			cout<<arr[i];
		cout<<endl;
	}
	return 0;
}

