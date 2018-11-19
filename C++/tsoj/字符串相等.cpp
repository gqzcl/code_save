#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		getchar();
		while(n--)
		{
			string s1,s2;			
			getline(cin,s1);
			getline(cin,s2);
			int len1=s1.length();
			int len2=s2.length();
			int j=0;
			bool flag=true;
			for(int i=0;i<len1;i++)
			{				
				if(s1[i]!=' ')
				{
					
					if(s1[i]>='A'&&s1[i]<='Z')
					{
						s1[i]=(char)(s1[i]+32);
					}
					for(j;j<len2;j++)
					{
//						cout<<j<<endl;
						if(s2[j]!=' ')
						{
							if(s2[j]>='A'&&s2[j]<='Z')
							{
								s2[j]=(char)(s2[j]+32);
							}
							if(s1[i]==s2[j])
							{
								j++;
								break;
							}
							if(s1[i]!=s2[j])
							{
								flag=false;
//								cout<<i<<' '<<j<<endl;
//								cout<<s1[0]<<endl;
								break;
							}
						}
					}
				}
				if(!flag)
					break;
			}
			if(flag)
				cout<<"YES"<<endl;
			else if(!flag)
				cout<<"NO"<<endl;
		}
	}
}

