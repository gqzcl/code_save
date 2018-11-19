#include <iostream>    
#include <string.h>    
#include <math.h>    
using namespace std;
const int N=90000000;
char arr[N];
int main(){  
    string str;   
    while(cin>>str) 
    {
    int a=convert(str);  
    int result=a%3;    
    if(result==0)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl; 
	}
    return 0;  
} 
