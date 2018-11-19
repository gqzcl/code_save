#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char arr1[1002];
char arr2[3002];
int main()
{
	while(scanf("%s",&arr1)!=EOF)
	{
		memset(arr2,0,sizeof(arr2));
        int num,tmp,k=0,len=strlen(arr1);
        int j;
        for(int i=len-1;i>1;i--)
        {
            num = arr1[i]-'0';
            for(j=0;j<k||num!=0;j++)
            {
                int z ;
                if(j<k)
                    z=arr2[j]-'0';
                else
                    z=0;
                tmp=num*10+z;
                arr2[j]=tmp/8+'0';
                num=tmp%8;
            }
            cout<<j<<endl;
            k = j;
            cout<<arr2<<endl;
        }
		cout<<arr1<<"[8]=0."<<arr2<<"[10]"<<endl;
	}
	return 0;
}

