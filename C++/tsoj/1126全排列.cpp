#include<iostream>
using namespace std;
int arr[10];
void change(int k,int n){
     if (k==n-2)
     {
         for (int j=0;j<n;j++)
             cout<<arr[j];
         cout<<endl;
         for (int j=0;j<n-2;j++)
             cout<<arr[j];   
         cout<<arr[n-1];
         cout<<arr[n-2]<<endl;
     }

         for (int i=k;i<n;i++)
         {
             swap(arr[k],arr[i]);
             change(k+1,n);
             swap(arr[k],arr[i] );
         }
     
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			arr[i]=i+1;
    	change(0,n);
	}
	return 0;
}

