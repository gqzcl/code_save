#include<iostream>
using namespace std;
int main(){
	int k;
	while(cin>>k){
		 for(int i=k+1;i<=2*k;i++){
		 	if((k*i)%(i-k)==0){
				printf("1/%d=1/%d+1/%d\n",k,k*i/(i-k),i);
			}
		 }
	}
}
