#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char arr1[100][100];
char arr2[100];
int search(char arr2[])
{
	int n,narr2;
    n=narr2=strlen(arr2);
    int flag;
    char arr3[100];
	char arr4[100];
    while(n>0)
    {
        for(int i=0;i<=narr2-n;i++)
        {
            strncpy(arr3,arr2+i,n);
            strncpy(arr4,arr2+i,n);
            arr3[n]=arr4[n]='\0'; 
            reverse(arr4,arr4+n);          
            flag=1;
            for(int j=0;j<n;j++)
            {
                if(strstr(arr1[j],arr3)==NULL && strstr(arr1[j],arr4)==NULL)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
                return n;
        }
        n--;
    }
}
int main()
{
	int t,s;
	while(cin>>t)
	{
		while(t--)
		{
			cin>>s;
			int min=100;
			for(int i=0;i<s;i++)
			{
				cin>>arr1[i];
				if(strlen(arr1[i])<min)
				{
					strcpy(arr2,arr1[i]);
					min=strlen(arr1[i]);
				}
			}
			cout<<search(arr2)<<endl;
		}
	}
	return 0;
}

