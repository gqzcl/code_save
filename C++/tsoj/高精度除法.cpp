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
	if(nlen1<nlen2)//�жϣ����p1λ��С��p2λ������p1С��p2������-1 
		return -1;
	bool blarger=false;//�����ж�p1λ����p2λ����ͬʱ�Ĵ�С�Ƚ� 
	if(nlen1==nlen2)
	{
		for(i=nlen1-1;i>=0;i--)
		{
			if(p1[i]>p2[i])//���p1С��p2�����ִ��else if��䣬����-1��������ڣ��򲻻᷵�أ���������ļ������� 
				blarger=true;
			else if(p1[i]<p2[i])
			{
				if(!blarger)
				return -1;
			}
		}
	}
	for(i=0;i<nlen1;i++)//���� 
	{
		p1[i]-=p2[i];
		if(p1[i]<0)
		{
			p1[i]+=10;
			p1[i+1]--;
		}
	}
	for(i=nlen1-1;i>=0;i--)//��������һ����Ϊ���p1[i]ʱ��ִ�з���i+1 
		if(p1[i])
			return i+1;
	return 0;
}
int main()//�� 
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
		
		if(nlen1<nlen2)//���a1��λ��С��a2��λ������ֱ�����0����������ǰѭ�� 
		{
			cout<<0<<endl;
			continue;
		}
		
		nlen1=substract(a1,a2,nlen1,nlen2);//��a1�ɹ���ȥһ��a2ʱ��nlen1��ֵΪa1��ǰ��λ�� 
		if(nlen1<0)//a1û�гɹ���ȥa2ʱ��nlen1��ֵΪ-1��������㲢����ѭ�� 
		{
			cout<<0<<endl;
			continue;
		}
		
		else if(nlen2==0)//nlen1����0ʱ˵���պü�ȥһ�Σ����������ѭ�� 
		{
			cout<<1<<endl;
			continue;
		}
		
		result[0]++;//a1��ֵ����0ʱ����һ 
		int ntimes=nlen1-nlen2;//���㵱ǰ����λ����Ϊ���� 
		if(ntimes<0)//˵������һ��֮��a1С��a2������ 
			goto output;
		else if(ntimes>0)
		{
			for(i=nlen1-1;i>=0;i--)//��a2����10��ntimes�� 
				if(i>=ntimes)
					a2[i]=a2[i-ntimes];
				else
					a2[i]=0;
		}
		nlen2=nlen1;
	for(j=0;j<=ntimes;j++)
	{
		int ntmp;
		while((ntmp=substract(a1,a2+j,nlen1,nlen2-j))>=0)//��ȥһ�κ�result��ntimes-jλ��һ 
		{
			nlen1=ntmp;
			result[ntimes-j]++;
		}
	}
	
	output:
		for(i=0;i<N;i++)//��λ 
		{
			if(result[i]>=10)
			{
				result[i+1]+=result[i]/10;
				result[i]%=10;
			}
		}
		
		bool boutput=false;
		for(i=N-1;i>=0;i--)//������һ����Ϊ�������ʼ��� 
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

