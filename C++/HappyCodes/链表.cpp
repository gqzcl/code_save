#include<iostream>
using namespace std;
typedef struct SqList{
        int* data;
        int length;
        };

bool InitList(struct SqList* L,int length)
{
    L->data=(int*)malloc(sizeof(int)*(length));
    for(int i=0;i<length;i++)
    {
        cin>>L->data[i];
    }
    L->length=length;
    return true;
    }
void InitList_i(struct SqList* L,int length)
{
    L->data=(int*)malloc(sizeof(int)*(length));
    L->length=length;
}
void merge(struct SqList* LL1,struct SqList* LL2,struct SqList* LL3)
{
    int i=0;
    int j=0;
    int k=0;
    while((i<LL1->length)&&(j<LL2->length))
    {
        if(LL1->data[i]<=LL2->data[j])
        {
            LL3->data[k]=LL1->data[i];
            i++;
            k++;
        }
        else
        {
            LL3->data[k]=LL2->data[j];
            j++;
            k++;
        }
    }
    while(i<LL1->length)
    {
        LL3->data[k++]=LL1->data[i++];
    }
    while(j<LL2->length)
    {
        LL3->data[k++]=LL2->data[j++];
    }
    LL3->length=k;
}
void print(struct SqList *L)
{
    int j=L->length;
    for(int i=0;i<j;i++)
    {
        printf("%d ",L->data[i]);
    }
    printf("\n");
}
int main()
{
    struct SqList L1;
    struct SqList L2;
    struct SqList L3;
    InitList(&L1,10);
    InitList(&L2,10);
    InitList_i(&L3,20);
    merge(&L1,&L2,&L3);
    print(&L3);
    printf("\n");
}
