#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
void sot(int *a,int *b,int m){
    //数据不大，直接冒泡
    //同时对索引进行排序，方便计算
    for(int i=0;i<m;i++){
        for(int j=0;j<m-i-1;j++){
            if(a[j]>=a[j+1]){
                int c;
                c=a[j];
                a[j]=a[j+1];
                a[j+1]=c;
                c=b[j];
                b[j]=b[j+1];
                b[j+1]=c;
            }
        }
    }
}

void judge(int *a,int* b,int **c,int m,int &flag){
    //根据Havel-Hakimi定理，出现负值直接为不可图
	for(int i=0;i<m;i++){
		if(a[i]<0){
			cout<<"NO"<<endl;
            flag=0;
			return ;
		}
	}
    //直接判断到最后
	if(m==0){
		cout<<"YES"<<endl;
        flag=1;
		return ;
	}
    sot(a,b,m);//排序进行判断
	int i=m-1;
	int cur=i-1;
    //按照公式操作
	for(int j=a[i];j>0;j--){
		a[cur]-=1;
        c[b[i]][b[cur]]=1;
        c[b[cur]][b[i]]=1;
        cur--;
		a[i]=0;
	}	
	judge(a,b,c,m-1,flag);//递归
}

void make(int* a,int m){
    int *Lake[m];//方便二维数组传值
    int mm[m][m];
    memset(Lake,0,sizeof(Lake));
    memset(mm,0,sizeof(mm));
    int b[m];
    for(int i=0;i<m;i++){
        b[i]=i;
        Lake[i]=mm[i];
    }
    sot(a,b,m);
    int flag;
    judge(a,b,Lake,m,flag);
    //如果可图，输出图
    if(flag){
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++)
                cout<<Lake[i][j]<<' ';
            cout<<endl;
        }
    }
    cout<<endl;
}

int main()
{
	int n;
	while(cin>>n){
		while(n--){
			int m;
			cin>>m;
			int a[m];
			for(int i=0;i<m;i++)
				cin>>a[i];
            make(a,m);
		}
	}
	return 0;
}
