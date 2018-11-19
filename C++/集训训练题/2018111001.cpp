#include<iostream>
#include <cstring>
#include <cmath>
using namespace std;

int extended(int a,int b,int& x,int& y)
{
    int d = a;
    if(b){
        d = extended(b,a % b,y,x);
        y -= (a / b) * x;
    }
    else{
        x = 1;
        y = 0;
    }
    return d;
}
 
void solve(int a,int b,int d,int& x,int& y)
{
    int g = extended(a,b,x,y);
    x *= d / g;
    int t = b / g;
    x = (x % t + t) % t;
    y = abs((a * x - d) / b);
}
 
int main()
{
    int a,b,c,x1,x2,y1,y2;
    while(cin>>a>>b>>c){
        if(a||b||c)
            break;
        solve(a,b,c,x1,y1);
        solve(b,a,c,x2,y2);
        if(x1 + y1 < x2 + y2)
            printf("%d %d\n",x1,y1);
        else
            printf("%d %d\n",y2,x2);
    }
    return 0;
}