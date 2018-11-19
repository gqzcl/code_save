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
/*int main()
{
	long a,b;
	char c; 
	while(scanf("%c%c%c%c%d%c%d%c)",&c,&c,&c,&c,&a,&c,&b,&c)!=EOF)
	{
		getchar();
		printf("%d\n",pow(a,b)%10);
	}
	return 0;
}*/

