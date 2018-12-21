#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1000 + 10;
int a[maxn];
int dp[maxn][31];
int t,w;
int main(){  
    while(cin >> t >> w){   
		memset(dp,0,sizeof(dp)); 
        for(int i = 1;i <= t; i++){
        	cin >> a[i];
		} 
        for(int i = 1; i <= t; i++){  
            dp[i][0] = dp[i-1][0];  
            if(a[i] == 1)  
                dp[i][0]++;  
            for(int j = 1;j <= w; j++){  
                if(j % 2 + 1 == a[i]){  
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + 1;  
                }else  
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]);  
            }  
        }  
		int Max = 0;
        for(int i = 0; i <= w; i++)  
           Max = max(Max, dp[t][i]);    
        printf("%d\n",Max);  
    }
}
