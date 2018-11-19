#include<iostream>
using namespace std;
int yuanshi(int test,int thesis)
{
	if(test>80&&thesis>=1)
		return 1;
	return 0;
}
int wusi(int test,int pclass)
{
	if(test>85&&pclass>80)
		return 1;
	return 0;
}
int chengji(int test)
{
	if(test>90)
		return 1;
	return 0;
}
int west(int test,char iswest)
{
	if(test>85&&iswest=='Y')
		return 1;
	return 0;
}
int pclass(int pclass,char iscadre)
{
	if(pclass>80&&iscadre=='Y')
		return 1;
	return 0;
}
int main()
{
	int n;
	
	while(cin>>n)
	{
		string name;
		int count=0;
		int pointoftest;
		int pointofclass;
		char iswest,iscadre;
		int thesis;	
		int judge1,judge2=0;	
		string theone;
		while(n--)
		{
			judge1=0;
			cin>>name>>pointoftest>>pointofclass>>iscadre>>iswest>>thesis;			
				if(yuanshi(pointoftest,thesis))
					judge1+=8000;
				if(wusi(pointoftest,pointofclass))
					judge1+=4000;
				if(chengji(pointoftest))
					judge1+=2000;
				if(west(pointoftest,iswest))
					judge1+=1000;
				if(pclass(pointofclass,iscadre))
					judge1+=850;
				count+=judge1;
				if(judge1>judge2)
				{
					theone=name;
					judge2=judge1;
					
				}			
		}
		cout<<theone<<endl<<judge2<<endl<<count<<endl;
	}
	return 0;
}

