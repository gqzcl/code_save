#include<iostream>
using namespace std;
const int MAX_TREE_SIZE=100;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTnode,*BiTree;
void CreateBiTree(BiTree &T){
    char ch;
    scanf("%c",&ch);
    if(ch=='0'){
        T=NULL;
        return;
    }else{
        if(!(T=(BiTnode*)malloc(sizeof(BiTNode))))
            return;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
void PreOrderTraverse(BiTree T){   
    if(T){
        printf("%c",T->data);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);                        
    }       
    return;
}
int main(){
    BiTree T;
    char e;
    CreateBiTree(T);
    PreOrderTraverse(T);
    printf("\n");
}
