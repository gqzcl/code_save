#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long max=0;
		for(int i=0;i<n;i++){
			long long cmax=1;
			for(int j=i;j<n;j++){
				cmax*=a[j];
				max=max>cmax?max:cmax;
			}
		}
		max=max>=0?max:0;
		cout<<max<<endl;
	}
}
