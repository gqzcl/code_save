#include<iostream>
#include<string.h>
using namespace std;
const int N=100;
int a1[N];
int a2[N];
int result[N];
char arr1[N];
char arr2[N];
int substract(int* p1,int* p2,int nlen1,int nlen2)
{
	int i;
	if(nlen1<nlen2)//判断，如果p1位数小于p2位数，则p1小于p2，返回-1 
		return -1;
	bool blarger=false;//用于判断p1位数与p2位数相同时的大小比较 
	if(nlen1==nlen2)
	{
		for(i=nlen1-1;i>=0;i--)
		{
			if(p1[i]>p2[i])//如果p1小于p2，则会执行else if语句，返回-1，如果大于，则不会返回，进行下面的减法程序 
				blarger=true;
			else if(p1[i]<p2[i])
			{
				if(!blarger)
				return -1;
			}
		}
	}
	for(i=0;i<nlen1;i++)//减法 
	{
		p1[i]-=p2[i];
		if(p1[i]<0)
		{
			p1[i]+=10;
			p1[i+1]--;
		}
	}
	for(i=nlen1-1;i>=0;i--)//当遇到第一个不为零的p1[i]时，执行返回i+1 
		if(p1[i])
			return i+1;
	return 0;
}
int main()//主 
{
	int n;
	char szblank[20];
	cin>>n;
	while(n--)
	{
		cin>>arr1>>arr2;
		int i,j;
		int nlen1=strlen(arr1);
		int nlen2=strlen(arr2);
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));
		memset(result,0,sizeof(result));
		
		j=0;
		for(i=nlen1-1;i>=0;i--)
			a1[j++]=arr1[i]-'0';
		j=0;
		for(i=nlen2-1;i>=0;i--)
			a2[j++]=arr2[i]-'0';
		
		if(nlen1<nlen2)//如果a1的位数小于a2的位数，则直接输出0，并跳出当前循环 
		{
			cout<<0<<endl;
			continue;
		}
		
		nlen1=substract(a1,a2,nlen1,nlen2);//当a1成功减去一次a2时，nlen1的值为a1当前的位数 
		if(nlen1<0)//a1没有成功减去a2时，nlen1的值为-1，则输出零并跳出循环 
		{
			cout<<0<<endl;
			continue;
		}
		
		else if(nlen2==0)//nlen1等于0时说明刚好减去一次，输出，跳出循环 
		{
			cout<<1<<endl;
			continue;
		}
		
		result[0]++;//a1的值大于0时，加一 
		int ntimes=nlen1-nlen2;//计算当前相差的位数即为倍数 
		if(ntimes<0)//说明减过一次之后a1小于a2，结束 
			goto output;
		else if(ntimes>0)
		{
			for(i=nlen1-1;i>=0;i--)//将a2乘以10的ntimes倍 
				if(i>=ntimes)
					a2[i]=a2[i-ntimes];
				else
					a2[i]=0;
		}
		nlen2=nlen1;
	for(j=0;j<=ntimes;j++)
	{
		int ntmp;
		while((ntmp=substract(a1,a2+j,nlen1,nlen2-j))>=0)//减去一次后，result第ntimes-j位加一 
		{
			nlen1=ntmp;
			result[ntimes-j]++;
		}
	}
	
	output:
		for(i=0;i<N;i++)//进位 
		{
			if(result[i]>=10)
			{
				result[i+1]+=result[i]/10;
				result[i]%=10;
			}
		}
		
		bool boutput=false;
		for(i=N-1;i>=0;i--)//遇到第一个不为零的数开始输出 
			if(boutput)
				cout<<result[i];
			else if(result[i])
			{
				cout<<result[i];
				boutput=true;
			}
		if(!boutput)
			cout<<0<<endl;
		cout<<endl;
	}
	return 0;
	
}

