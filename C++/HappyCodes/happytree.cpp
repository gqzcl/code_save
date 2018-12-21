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
void PreOrderTraverse(BiTree root)      //非递归中序遍历
{
    stack<BiTree> s;
    BiTree p=root;
    while(p!=NULL||!s.empty())
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
            cout<<"#";
        }
        if(!s.empty())
        {
            p=s.top();
            cout<<p->data;
            s.pop();
            p=p->rchild;
        }
    }    
}
//AB0CD000E0FGH00K000

int main(){
    BiTree T;
    CreateBiTree(T);
    PreOrderTraverse(T);
    printf("\n");
}
