#include<iostream>
//using namespace std;
void swap (int&a,int&b)
{
	int c;
	c=a; a=b; b=c;
}
int main () 
{
	int a=-5,b=6;
	swap(a,b);
	std::cout<<a<<"\t"<<b<<std::endl;
	swap(a,b);
	std::cout<<a<<"\t"<<b<<std::endl;
	return 0;
	
}
