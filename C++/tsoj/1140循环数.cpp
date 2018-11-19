#include<iostream>
#include<cstring>
using namespace std;
string arr1;
char arr2[60];
int arr3[60];
int arr4[60];
int main()
{
	while(cin>>arr1)
	{
		int len=arr1.length();
		for(int i=0;i<len;i++)
		{
			arr3[i]=arr1[i]-'0';
			arr4[i]=arr1[i]-'0';
		}
		for(int j=1;j<=len+1;j++)
		{
			for(int i=len-1;i>=0;i--)
				arr3[i]*=j;
			for(int i=len-1;i>0;i--)
			{
				if(arr3[i]>=10)
				{
					arr3[i-1]+=arr3[i]/10;
					arr3[i]%=10;											
				}
			}
			if(arr3[0]>=10)
				break;			
			for(int i=0;i<len;i++)
				arr2[i]=arr3[i]+'0';
			for(int i=0;i<len;i++)
				arr3[i]=arr4[i];
		}
		int flag=1;
		for(int i=0;i<len;i++)
		{
			if(arr2[i]!='9')
			flag=0;
		}
		if(flag)
			cout<<arr1<<" is cyclic"<<endl;
		else
			cout<<arr1<<" is not cyclic"<<endl;
	}
	return 0;
}
/*142857 (6位)
0588235294117647 (16位)
052631578947368421 (18位)
0434782608695652173913 (22位)
0344827586206896551724137931 (28位)
0212765957446808510638297872340425531914893617 (46位)
0169491525423728813559322033898305084745762711864406779661 (58位)
016393442622950819672131147540983606557377049180327868852459 (60位)*/
//循环数，第n位循环，第n+1位为9999999....
 

