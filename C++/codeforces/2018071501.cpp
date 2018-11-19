#include<iostream>  
#include<vector>
using namespace std; 
const int MAXN = 100000000;
const int M = 1000000007;
bool arr[MAXN+1] = {false};
vector<int> produce_prim_number()
{
    vector<int> prim;
    prim.push_back(2);
    int i,j;
    for(i=3; i*i<=MAXN; i+=2)
    {
        if(!arr[i])
        {
            prim.push_back(i);
            for(j=i*i; j<=MAXN; j+=i)
            arr[j] = true;
        }
    }
    while(i<=MAXN)
    {
        if(!arr[i])
        prim.push_back(i);
        i+=2;
    }
    return prim;
}
 
int Cal(int x, int p)
{
    int ans = 0;
    long long rec = p;
    while(x>=rec)
    {
        ans += x/rec;
        rec *= p;
    }
    return ans;
}
 
int Pow(long long n, int k, int M)
{
    long long ans = 1;
    while(k)
    {
        if(k&1)
        {
            ans = (ans * n) % M;
        }
        n = (n * n) % M;
        k >>= 1;
    }
    return ans;
}
 
int Combination(int n, int m)
{
    
    vector<int> prim = produce_prim_number();
    long long ans = 1;
    int num;
    for(int i=0; i<prim.size() && prim[i]<=n; ++i)
    {
        num = Cal(n, prim[i]) - Cal(m, prim[i]) - Cal(n-m, prim[i]);
        ans = (ans * Pow(prim[i], num, M)) % M;
    }
    return ans;
}
int main()
{
	int T;
	while(cin>>T)
	{
		int s=1;
		while(T--)
		{
			
			int N,K;
			cin>>N>>K;
			long long result=0;
			for(int i=K;i<=N;i++)
			{
				result+=Combination(N,i);
				result%=M;
			}
			cout<<"Case #"<<s<<": "<<result<<endl;
			s++;
		}
	} 
}


