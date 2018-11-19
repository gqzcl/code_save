#include<iostream>
#include<cstring>
using namespace std;
const int N=25;
char arr[N];
int an[N];
static int a2,a3,a5,a7;
int count(int* p,int i)
{
	int j;
	 
	for(j=0;j<i;j++)
		{
			switch(p[j])
			{
			case 2:
				a2++;
				break;
			case 3:
				a2++;
				a3++;
				break;
			case 4:
				a2+=3;
				a3++;
				break;
			case 5:
				a2+=3;
				a3++;
				a5++;
				break;
			case 6:
				a2+=4;
				a3+=2;
				a5++;
				break;
			case 7:
				a2+=4;
				a3+=2;
				a5++;
				a7++;
				break;
			case 8:
				a2+=7;
				a3+=2;
				a5++;
				a7++;
				break;
			case 9:
				a2+=7;
				a3+=4;
				a5++;
				a7++;
				break;
			default:
				break;	
			}
				
		}
	
	return 0;	
}
int fact(int a,int b)
{
	int t=1;
	while(b>0){
		t*=a;
		b--;
	}
	return t;
}
int main()
{
	while(cin>>arr)
	{	
		memset(an,0,sizeof(an));
		int narr=strlen(arr);
		int i,j;
		//j=narr-1;
		j=0;
		for(i=narr-1;i>=0;i--)
		{
			an[j++]=arr[i]-'0';
		}
		
		count(an,narr);
		
		int n=0;
		n=an[1]+11*an[2]+110*an[3];
		//cout<<an[0]<<an[1]<<an[2]<<an[3]<<endl;
		n%=4;
		a2+=(3*n);
		a5+=n;
		a7+=n;
		a2-=a5;
		a2%=4;
		a3%=4;
		
		a7%=4;
		cout<<a2<<a3<<a5<<a7<<endl;
		int m=1;
		m=fact(3,a3)*fact(2,a2)*fact(7,a7);
		m%=10; 
		cout<<m<<endl;
	}
	return 0;
}
