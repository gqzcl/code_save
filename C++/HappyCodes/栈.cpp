#include<iostream>
using namespace std;
const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;
char a[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
typedef struct{
    int *base;
    int *top;
    int stacksize;
}SqStack;
void InitStack(SqStack &S){
    S.base=(int*)malloc(STACK_INIT_SIZE*sizeof(int));
    if(!S.base)
        return;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return;
}
void Push(SqStack &S,int e){
    if(S.top-S.base>=S.stacksize){
        S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
        if(!S.base)
            return;
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return;
}
void Pop(SqStack &S,int &e){
    if(S.top==S.base)
        return;
    e=*--S.top;
    return;
}
bool StackEmpty(SqStack &S){
    if(S.top==S.base)
        return true;
    else    
        return false;
}
int main()
{
    SqStack S;
    InitStack(S);
    int n,f;
    while(cin>>n>>f){
        while(n){
            Push(S,n%f);
            n=n/f;
        }
        int e;
        while(!StackEmpty(S)){
            Pop(S,e);
            cout<<a[e];
        }
        cout<<endl;
    }
    return 0;
}
