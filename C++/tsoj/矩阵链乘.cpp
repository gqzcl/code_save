#include<iostream>
#include<stack> 
//#include<vector>
using namespace std;
int main()
{
	stack<char> S;
	int n;
	while(cin>>n)
	{
		int n1=n;
		char ma[n];
		int  line[n][2];

		//vector<int> line2;
		int i=0;
		while(n1--)
		{
			cin>>ma[i]>>line[i][0]>>line[i][1];
			i++;
		}
		n1=n;
		string s;
		while(cin>>s)
		{
			int count=0;
			int len=s.size();
			stack<int> S1;
//			if(len==1)
//				cout<<0<<endl;
			for(int i=0;i<len;i++)
			{
				if(s[i]=='(')
					S.push(s[i]);
				else if(s[i]>='A'&&s[i]<='Z')
				{
					
					S1.push(line[s[i]-'A'][1]);
					//cout<<line[s[i]-'A'][1]<<ends;
					S1.push(line[s[i]-'A'][0]);
					//cout<<line[s[i]-'A'][0]<<ends;
				}
				else if(s[i]==')')
				{
					S.pop();
					int store[4];
					for(int j=0;j<4;j++)
					{
						store[j]=S1.top();
						//cout<<store[j]<<ends;
						//cout<<S1.top();
						S1.pop();
					}
					//cout<<store[0]<<store[3]<<endl;
					if(store[0]!=store[3])
					{
						cout<<"error"<<endl;
					}
					else
					{
						count+=store[0]*store[1]*store[2];
						S1.push(store[1]);
						S1.push(store[2]);
					}
				}
			}
			cout<<count<<endl;
		}
		
	}
}

