#include<iostream>
#include<stdio.h> 
using namespace std;
const int initsize=100;
const int stackincrement=10;
typedef struct{
	int *base;
	int *top;
	int stacksize;
}qstack;
int InitStack(qstack &S){
	S.base=(int*)malloc(initsize*sizeof(int));
	if(!S.base)
		exit(0);//����ʧ�� 
	S.top=S.base;//��ʼջ������ջ�� 
	S.stacksize=initsize;//����ջ���� 
	return 0;
}
int push(qstack S,int e){
	if(S.top-S.base>=S.stacksize){
		S.base=(int *)realloc(S.base,(S.stacksize+stackincrement)*sizeof(int));
	if(!S.base)
		exit(0);//����ʧ��
	S.top=S.base+S.stacksize;
	S.stacksize+=stackincrement; 
	}
	*S.top++=e;
	return 0;
}
int pop(qstack &S,int &e){
	if(S.top==S.base)
		return 1;
	e=*--S.top;
	return 0;
}
int gettop(qstack S,int &e){
	if(S.top==S.base)
		return 1;
	e=*(S.top-1);
	return 0;
}
int main()
{
	qstack S;
	int n;
	while(cin>>n)
	{
		push(S,n);
	}
	do{
		
	}while(S.base!=S.top)
}

