#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=2;i<n;i++)//��2��ʼѰ�ҷ����������� 
		{
			for(int t=2;t<=sqrt(i);t++)//�ж�i�ǲ������� 
			{
				if(i%t==0)
					i=0;
			}
			if(i==0)//���i��������������ѭ�������������´�ѭ�� 
				break;
			if(i!=0&&(n-i)!=1)//���i���������ж�n-i�ǲ������� 
			{
				int k=n-i;
				for(int t=2;t<=sqrt(k);t++)//�ж� 
				{
					if(k%t==0)
						k=0;
				}
				if(k!=0)//���n-i�������������ҵ���������������� 
					cout<<i<<"+"<<k<<endl;	
			}
		}
	}
	return 0;
}

