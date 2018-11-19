#include<iostream>
using namespace std;

void show(int** arr,int n)
{
	for(int a=0;a<n;a++)
		{
			arr[a]=new int [n];
			for(int b=0;b<n;b++)
			{
				arr[a][b]=1;
				cout<<arr[a][b]<<' ';
			}
			cout<<endl;
		}	
}
int main()
{
	
	int n;
	while(cin>>n)
	{	
		int arr[n][n];
		int** p=new int*[n];
		show(p,n);
	}
	return 0;
}

