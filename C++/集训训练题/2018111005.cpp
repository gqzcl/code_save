#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
char s[1000010];
int main()
{
    scanf(" %s",s);
    int len = strlen(s);
    long long cntb = 0, ans = 0;
    for(int i=len-1;i>=0;--i)
    {
        if(s[i] == 'a') {
            (ans += cntb) %= mod;
            (cntb *= 2) %= mod;
        } else {
            cntb++;
        }
    }
    printf("%I64d\n", ans%mod);
}