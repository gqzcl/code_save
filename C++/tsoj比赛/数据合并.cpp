#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int c[m+n];
		for(int i=0;i<m;i++)
			cin>>c[i];
		for(int i=m;i<m+n;i++)
			cin>>c[i];
		sort(c,c+m+n);
		for(int i=0;i<m+n-1;i++)
			cout<<c[i]<<" ";
		cout<<c[m+n-1];
		cout<<endl;
	}
}

