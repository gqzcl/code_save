#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char arr[100];
char top[100];
int main()
{
	int n;
	cin>>n;
	char c=getchar();
	while(n--)
	{
		gets(arr);
		int judge=0;
		int j=0;
		for(int i=0;i<strlen(arr);i++)
		{
			if(arr[i]=='{'){
				top[j++]=arr[i];
				}
			else if(arr[i]=='}'){
				if(j==0)
				{
					judge=1;
					break;}
				else
					if(top[j]=='{'){
						top[j--];
						}
					else
						{
							judge=1;
							break;}
				}
			else if(arr[i]=='('){
				top[j++]=arr[i];
				
				}
			else if(arr[i]==')'){
				if(j==0)
				{
					judge=1;
					break;}
				else
					if(top[j]=='('){
						top[j--];
					
						}
					else
						{
							judge=1;
							break;}
				}
		}
		if(j==0&&judge==0)
			cout<<"Yes"<<endl;
		else if(j!=0||judge==1)
			cout<<"No"<<endl;
	}
	return 0;
}
