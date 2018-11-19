#include<iostream>
#include<cstdlib>
#include<ctime> 
using namespace std;
int main()
{
	srand(time(0));
	int a=10;
	while(a--)cout<<rand()%6+85<<" ";
	return 0;
}

