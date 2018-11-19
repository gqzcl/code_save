#include<iostream>
using namespace std;
int movechess(int n)
{
	if(n==4)
		cout<<"4,5-->9,10"<<endl<<"8,9-->4,5"<<endl<<"2,3-->8,9"<<endl<<"7,8-->2,3"<<endl<<"1,2-->7,8"<<endl;
	else
	{
		cout<<n<<","<<n+1<<"-->"<<2*n+1<<","<<2*n+2<<endl<<2*n-1<<","<<2*n<<"-->"<<n<<","<<n+1<<endl;
		movechess(n-1);
	}
}
int main()
{
	int n;
	while(cin>>n)
		movechess(n);
}
