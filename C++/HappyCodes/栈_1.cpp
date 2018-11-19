#include<iostream>
using namespace std;
const int STACK_INIT_SIZE=100;
const int STACKINCREMENT=10;
typedef struct{
    char *base;
    char *top;
    int stacksize;
}SqStack;
void InitStack(SqStack &S){
    S.base=(char*)malloc(STACK_INIT_SIZE*sizeof(char));
    if(!S.base)
        return;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return;
}
void Push(SqStack &S,char e){
    if(S.top-S.base>=S.stacksize){
        S.base=(char*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));
        if(!S.base)
            return;
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return;
}
void Pop(SqStack &S,char &e){
    if(S.top==S.base)
        return ;
    e=*--S.top;
    return ;
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
    string s;
    while(cin>>s){
        int j=s.size();
        for(int i=0;i<j;i++)
            Push(S,s[i]);
        int flag=1;
        char e;
        for(int i=0;i<j;i++){
            Pop(S,e);
            if(s[i]!=e){
                cout<<"no"<<endl;
                flag=0;
                break;
            }
        }
        if(flag)
            cout<<"yes"<<endl;
    }

    return 0;
}