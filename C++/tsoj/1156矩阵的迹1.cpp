#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
struct narr
{
    int arr[12][12];
};
narr narr1,narr2;
narr sum(narr a,narr b)
{
    narr c;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c.arr[i][j]=0;
            for(int k =0;k<n;k++)
                c.arr[i][j]=(c.arr[i][j]+a.arr[i][k]*b.arr[k][j]%9973)%9973;
            c.arr[i][j]%=9973;
        }
    }
        return c;
}
narr pow(narr x,narr y,int a)
{
    while (a)
    {
        if(a%2)
        {
            y=sum(y,x);
        }
        a/=2;
        x=sum(x, x);
    }
    return y;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                cin>>narr1.arr[i][j];
                narr2.arr[i][j]=narr1.arr[i][j];
            }
        }
        narr ans;
        ans=pow(narr1,narr2,m-1);
        int answer=0;
        for(int i=0;i<n;i++)
            answer+=ans.arr[i][i]%9973;
        cout<<answer%9973<<endl;
    }
    return 0;
}
