#include<iostream>
#include<stack>
using namespace std;
const int MAX_TREE_SIZE=100;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void CreateBiTree(BiTree &T){
    char ch;
    scanf("%c",&ch);
    if(ch=='0'){
        T=NULL;
        return;
    }else{
        if(!(T=(BiTNode*)malloc(sizeof(BiTNode))))
            return;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}
// void PreOrderTraverse(BiTree T){   
//     if(T){
//         PreOrderTraverse(T->lchild);
//         cout<<T->data;
//         PreOrderTraverse(T->rchild);                        
//     }else{
//         cout<<'#';
//     }    
//     return;
// }
void PreOrderTraverse(BiTree T){
    stack<BiTNode> S;
    int i=0;
    //T=NULL;
    S.push(T);
    //cout<<S.top();
    //cout<<S.empty();
    while(!S.empty()){
        while(S.top()){
            S.push(S.top()->lchild);
            //cout<<S.top();
        }
        //cout<<i++;
        while(!S.top()){
            S.pop();
            cout<<'#';
        }
        cout<<S.top()->data;
        S.top()=S.top()->rchild;
        
    }
    return;
}
//AB0CD000E0FGH00K000

int main(){
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T);
    printf("\n");
}
