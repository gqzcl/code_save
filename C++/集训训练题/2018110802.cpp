#include<iostream>
#include<cmath>
using namespace std;
const int N = 10005;
const double eps = 1e-10;
int n;
struct lp{
    double x,y,rad;
    int id;
    lp(){}
    lp(double a,double b){x=a,y=b;}
}cw[N];
lp operator +(lp A,lp B){
    return (lp){A.x+B.x,A.y+B.y};
}//重载一下
lp operator -(lp A,lp B){
    return (lp){A.x-B.x,A.y-B.y};
}
inline double crossDot(lp a,lp b){
    return a.x*b.y-a.y*b.x;
}
inline double area2(lp a,lp b,lp c){
    return crossDot(b-a,c-a);
}
double leng(lp A,lp B){
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double disToLine(lp P,lp A,lp B){//求出距离
    return fabs(crossDot(B-A,P-A))/leng(A,B);
}
inline bool ok(double m){//判断条件
    for(int i=1;i<=n;++i){
        if(disToLine(cw[i],cw[i-1],cw[i+1])<=2*m)
            return false;
    }
    return true;
}
int main(){
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;++i){
            scanf("%lf%lf",&cw[i].x,&cw[i].y);
        }
        cw[0]=cw[n];
        cw[n+1]=cw[1];
        double l=0,r=1e18,m,ans;
        for(int i=0;i<100;++i){
            m=(l+r)/2;
            if(ok(m))l=m,ans=m;
            else r=m;
        }
        printf("%.10f\n",ans );
    }
    return 0;
}