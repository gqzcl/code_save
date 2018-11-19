// #include<iostream>
// using namespace std;

// double search_maxn(int* a,int n,int f,int l,int r,double sum,double max){
//         //cout<<f<<' ';
//         if(f==n){
//             return max;
//         }
//         //cout<<f<<' ';
//         double max1=0,max2=0;
//         if(r<n-1&&(sum+(double)a[r+1])/(double)f>=max){
//             cout<<max1;
//             max1=(sum+(double)a[r+1])/(double)f;
//         }
//         if(l>0&&(sum+(double)a[l-1])/(double)f>=max){
//             cout<<max2;
//             max2=(sum+(double)a[l-1])/(double)f;
//         }
//         cout<<max1<<max2<<' ';
//         if(max1>max2){
//             max=max1;
//             search_maxn(a,n,f+1,l,r+1,sum,max);
//         }
//         else if(max1<max2){
//             max=max2;
//             search_maxn(a,n,f+1,l-1,r,sum,max);
//         }
//         else if(max1==0&&max2==0){
//             if(a[l-1]>a[r+1]&&r<n-1&&l>0)
//                 search_maxn(a,n,f+1,l-1,r,sum,max);
//             else if(a[r+1]>a[l-1]&&r<n-1&&l>0)
//                 search_maxn(a,n,f+1,l,r+1,sum,max);
//             else if(l<=0)
//                 search_maxn(a,n,f+1,l,r+1,sum,max);
//             else if(r>=n-1)
//                 search_maxn(a,n,f+1,l-1,r,sum,max);
//         }
        
// }
// void search_max(int* a,int n,int f){
//     double max=0;
//     double sum=0;
//     int l=0,r=f-1;
//     for(l;l<=r;l++)
//         sum+=a[l];
//     max=sum/(double)f;
//     l=0;
//     double sum1=sum;
//     for(int i=r+1;i<n;i++){
//         sum+=a[i];
//         sum-=a[l];
//         l++;
//         if(sum/(double)f>max){//如果有相等的情况另作考虑
//             //r=i;
//             max=sum/(double)f;
//         }
//     }
//     //cout<<max<<endl;
//     double maxn1=max;
//     //cout<<sum1<<endl;
//     l=0;
//     for(int i=r+1;i<n;i++){
//         sum1+=a[i];
//         sum1-=a[l];
//         l++;
//         //cout<<sum1<<endl;
//         if(sum1/(double)f==max){//如果有相等的情况另作考虑
//             r=i;
//             l=r-f+1;
//             double maxn2=search_maxn(a,n,f+1,l,r,sum1,maxn1);
//             cout<<maxn1<<endl;
//             max=max>maxn2?max:maxn2;
//         }
//     }
//     //cout<<maxn1<<endl;
//     max=max>maxn1?max:maxn1;
//     cout<<int(1000*max)<<endl;   
// }


// int main(int argc, char const *argv[])
// {
//     int n,f;
//     while(cin>>n>>f){
//         int a[n];
//         for(int i=0;i<n;i++)
//             cin>>a[i];
//         search_max(a,n,f);
//     }
//     return 0;
// }
#include <cstdio>
#include <cmath>
const int maxn = 100100;
//输入优化
char ch;
int scan()
{
    while( ch = getchar(), ch < '0' || ch > '9' );
        int res = ch - '0';
    while( ch = getchar(), ch >= '0' && ch <= '9' )
        res = res*10 + ch - '0';
    return res;
}
int a[maxn];
struct point
{
    double x, y;
}p[maxn], queue[maxn];
//叉乘
double cross( point& p0, point& p1, point& p2 )
{
    return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
}
//获取两点的斜率
double getk( point& aa, point& bb )
{
    return (bb.y-aa.y)/(bb.x-aa.x);
}
int main ()
{
    int i, j, N, F, size;
    double ans;
    while(scanf("%d %d", &N, &F)==2){
        p[0].y = p[0].x = 0;
        for( i = 1; i <= N; ++i )
        {
            p[i].y = scan() + p[i - 1].y;
            p[i].x = i;
        }
        size = 0;
        ans = -1.0;
        int ll, rr, mid;
        for( i = F; i <= N; ++i )
        {
            point newp = p[i - F];
            //类似凸包的构造，构造一个下凹的曲线
            while( size >= 2 && cross(queue[size-2], queue[size-1], newp) < 0 )
                --size;
            queue[size++] = newp;
            //二分查找
            ll = 0; rr = size;
            while( rr - ll > 1 )
            {
                mid = (ll+rr)/2;
                if( cross(queue[mid-1], p[i], queue[mid]) > 0 )
                    rr = mid;
                else
                    ll = mid;
            }
            if( ans < getk(queue[ll], p[i]) )
                ans = getk(queue[ll], p[i]);
        }
        printf("%d", (int)(ans*1000));
    }
    return 0;
}