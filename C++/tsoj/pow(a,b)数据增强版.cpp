#include <iostream>
#include <sstream>
using namespace std;
long pow(long a,long b);
int main(void) {
  string line;
  while (getline(cin,line)) {
   long a, b;
    char c;
    stringstream ss(line);                                                                            
    ss >> c >> c >> c >> c >> a >> c >> b >> c;
    a%=10;
	if(b!=0&&b%4==0)
		b=4;
	else 
		b%=4;
    cout << pow(a,b)%10<< endl;
  }    
  return 0;
}

long pow(long a,long b)
{
	long t=1;
	while(b--)
	{
		t*=a;
	}
	return t;
} 
