#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		 if(!a&&!b&&!c)
		 	break;
		cout<<a/b<<".";
		a%=b;
		for(int i=1;i<c;i++)
		{
			cout<<a*10/b;
			a=a*10/b;
		}
		if(a*10/b*10/b>=5)
			cout<<a*10/b+1;
		else cout<<a*10/b<<endl;
	}
}

