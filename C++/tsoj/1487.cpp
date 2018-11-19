#include<iostream>
#include<cmath>
using namespace std;
const int N=1000;
struct d
{
	int x,y,z;
	
};
d r[N];
d g[N];
d b[N];
double maxx(double x,double y)
{
	return x>y?x:y;
}
double kkk(d a,d b)
{
//	cout<<a.x<<a.y<<a.z<<ends<<b.x<<b.y<<b.z<<endl;
	double l=sqrt((a.x-b.x)*(a.x-b.x)+ (a.y-b.y)*(a.y-b.y)+ (a.z-b.z)*(a.z-b.z));
//	cout<<l<<endl;
	return l;

}

double kk(double a,double b ,double c)
{
//	cout<<a<<b<<c<<endl<<endl;
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main()
{
	int n;
	while(cin>>n)
	{
		int i=0,j=0,k=0;
		for(int t=0;t<n;t++)
		{
			char e;
			cin>>e;
			if(e=='R')
			{
				cin>>r[i].x>>r[i].y>>r[i].z;
//				cout<<r[i].x<<r[i].y<<r[i].z;
				i++;
			}
						if(e=='G')
			{
				cin>>g[j].x>>g[j].y>>g[j].z;
				j++;
			}
						if(e=='B')
			{
				cin>>b[k].x>>b[k].y>>b[k].z;
				k++;
			}
		}
		
		double max=0;
		if(i>2)
		for(int x=2;x<i;x++)
		{
			for(int y=1;y<x;y++)
			{
				for(int z=0;z<y;z++)
				{
					max=maxx(max,kk(kkk(r[x],r[y]),kkk(r[y],r[z]),kkk(r[z],r[x])));
				}
			}
		} 
		if(j>2)
		{
		for(int x=2;x<i;x++)
		{
			for(int y=1;y<x;y++)
			{
				for(int z=0;z<y;z++)
				{
					max=maxx(max,kk(kkk(g[x],g[y]),kkk(g[y],g[z]),kkk(g[z],g[x])));
//					cout<<"?";
				}
			}
		} 
		}
		if(k>2)
		for(int x=2;x<i;x++)
		{
			for(int y=1;y<x;y++)
			{
				for(int z=1;z<y;z++)
				{
					max=maxx(max,kk(kkk(b[x],b[y]),kkk(b[y],b[z]),kkk(b[z],b[x])));
				}
			}
		} 
		if(i*j*k>0)
		for(int x=0;x<i;x++)
		{
			for(int y=0;y<j;y++)
			{
				for(int z=0;z<k;z++)
				{
					max=maxx(max,kk(kkk(r[x],g[y]),kkk(g[y],b[z]),kkk(b[z],r[x])));
				}
			}
		} 
		printf("%0.5lf\n",max);
	}
}

