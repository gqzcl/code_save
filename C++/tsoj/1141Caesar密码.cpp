#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char start[10],end[10];
	char text[140000];
	while(gets(start))
	{
		if(strcmp(start,"ENDOFINPUT")==0)
			return 0;
		//cin.getline(text,140000);
		gets(text);
		gets(end);
		int len=strlen(text);
		for(int i=0;i<len;i++)
		{
			if(text[i]>='F'&&text[i]<='Z')
				text[i]=text[i]-5;
			else if(text[i]>='A'&&text[i]<='E')
				text[i]=text[i]+21;
		}
		cout<<text<<endl;
	}
	return 0;
}

