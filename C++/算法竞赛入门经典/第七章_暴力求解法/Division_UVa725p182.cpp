#include<iostream>
#include<sstream>
#include<string>
using namespace std;
bool search(int a,int b){
	stringstream s;
	s<<a<<b;
	string s1=s.str();
	if(s1.size()<10)
		s1+='0';
	//cout<<s1<<endl;
	for(int i=0;i<10;i++){
		char c=i+'0';
		if(s1.find(c)==s1.npos)
			return false;
	}
	return true;	
}
int main(){
	int n;
	while(cin>>n){
		for(int i=1234;i<98765;i++){
			if(i*n<=98765){
				if(search(i,i*n))
					printf("%.5d/%.5d=%d\n",i*n,i,n);
			//search(i,i*n);
			}
		}
	}
}
