#include<iostream>
using namespace std;
const int N = 50;  
int pre[N], in[N], post[N]; 
int n;
struct Btree{
	int data;
	Btree *lchild;
	Btree *rchild;
}; 
Btree* CreatTree(int prel, int prer, int inl, int inr)
{
	if (prel>prer)                              
    {  
        return NULL;
    }  
    Btree* root = new Btree;                        
    root->data = pre[prel];                        
    int k;                                    
    for (k = inl; k <= inr; k++)  
    {  
        if (in[k] == pre[prel])                 
            break;  
    }  
    int numleft = k - inl;                        
    root->lchild = CreatTree(prel + 1, prel + numleft, inl, k - 1);       
    root->rchild = CreatTree(prel + numleft + 1, prer, k + 1, inr); 
    return root;
}

int gethight(Btree *root) {  
    if (!root)return 0;  
    return max(gethight(root->lchild) + 1, gethight(root->rchild) + 1);  
}
int main()
{
	while(cin>>n)
	{  
    for (int i = 0; i<n; i++)
    {  
        scanf("%d", &pre[i]);  
    }  
    for (int i = 0; i<n; i++)
    {  
        scanf("%d", &in[i]);  
    }  
    Btree* root = CreatTree(0, n - 1, 0, n - 1);
    cout<<gethight(root)<<endl;
	}
    cout<<(int)'0'; 
}

