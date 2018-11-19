#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n],number[n];
		char name[n][25];
		char change[25];
		char area[n][15];
		for(int i=0;i<n;i++)
			cin>>a[i]>>name[i]>>number[i]>>area[i];
		for(int i=0;i<n-1;i++)
		{
	        for(int j=0;j<n-i-1;j++)
	        {
	   			if(strcmp(name[j],name[j+1])>0) 
				{
					swap(name[j+1],name[j]);
					swap(area[j+1],area[j]);
					swap(number[j+1],number[j]);
					swap(a[j+1],a[j]);
				}
			}
		}
			int keep;
			for(int i=0;i<n;i++)
			{ 
           		if(strcmp(name[i],"China")!=0)
					cout<<a[i]<<" "<<name[i]<<" "<<number[i]<<" "<<area[i]<<endl;
				else
				keep=i;
			} 
            cout<<a[keep]<<" "<<name[keep]<<" "<<number[keep]<<" "<<area[keep]<<endl;
   	 
	} 
	return 0;
}
/*样例输入:
5

1 France 123 Europe

2 Russia 254 Europe

3 Japan 235 Asia

4 Germany 185 Europe

5 China 560 Asia

样例输出:
1 France 123 Europe

4 Germany 185 Europe

3 Japan 235 Asia

2 Russia 254 Europe

5 China 560 Asia*/

