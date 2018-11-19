#include<iostream>
using namespace std;
int main()
{
	int n; 
    while(cin>>n)
    {
    	int s[2*n];
    	int m[n+1][n+1];
		for(int i=0;i<2*n;i++)
		{
			cin>>s[i];
		}
		bool flag=false;
		for(int i=1;i<2*n-2;i+=2)
		{
			if(s[i]!=s[i+1])
			{
				cout<<"invalid argument"<<endl;
				flag=true;
				break;
			}
		}
		if(flag)
			continue;
		int p[n+1]; 
		p[0]=s[0];
		p[n]=s[2*n-1];
		for(int i=1,j=1;i<n;i++,j+=2)
		{
			p[i]=s[j];
		}
	    for(int i=0;i<=n;++i) 
			m[i][i]=0;
	    for(int r=2;r<=n;r++)
		{
	        for(int i=1;i<=n-r+1;i++)
			{
	            int j=r+i-1;
	            m[i][j]=m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
	            for(int k=i+1;k<j;k++)
				{
	                int temp=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
	                if(temp<m[i][j])
	                    m[i][j]=temp;
	            }
	        }
	    }
	    cout<<m[1][n]<<endl;
	}
}

