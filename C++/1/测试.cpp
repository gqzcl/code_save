#include<iostream>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
void judge(int *a,int m){
	for(int i=0;i<m;i++){
		if(a[i]<0){
			cout<<"No"<<endl;
			return ;
		}
	}
	if(m==0){
		cout<<"Yes"<<endl;
		return ;
	}
		int i=m-1;
		int cur=i-1;
		for(int j=a[i];j>0;j--){
			a[cur--]-=1;
		a[i]=0;
	}
	sort(a,a+m);
	judge(a,m-1);
}
int main()
{
	int n;
	while(cin>>n){
		while(n--){
			int m;
			cin>>m;
			int a[m];
			for(int i=0;i<m;i++){
				cin>>a[i];
			}
			sort(a,a+m);
			judge(a,m);
		}
	}
	
}

