#include <iostream>
using namespace std;
struct ListNode
{
	int   val;
	ListNode* next;
};
ListNode* MergeTwoSortedLists(ListNode* l1, ListNode* l2)
{
	ListNode* newhead = NULL;
	ListNode* p = NULL;
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	if (l1->val < l2->val){ newhead = l1;  p = l1; l1 = l1->next; }
	else{ newhead = l2; p = l2; l2 = l2->next; }
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			p ->next= l1;
			l1 = l1->next;
		}
		else
		{
			p->next = l2;
			l2 = l2->next;
		}
		p = p->next;
	}
	p->next = l1 ? l1 : l2;
	return newhead;
}
ListNode* CreateListNode(int value)
{
	ListNode* pNode = new ListNode();
	pNode->val = value;
	pNode->next = NULL;
	return pNode;
}
void print(ListNode *p1)
{
    while (p1)
	{
		cout << p1->val << " ";
		p1 = p1->next;
	}
    cout<<endl;
}
void cinn(ListNode* p1,int a){
    int n;
    for(int i=0;i<a;i++){
        cin>>n;
        p1->next=CreateListNode(n);
        p1=p1->next;
    }
}
int  main()
{
	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(1);
	ListNode* p1 = pNode1;
	ListNode* p2 = pNode2;
    int n;
    cinn(pNode1,5);
    cinn(pNode2,5);
	ListNode* res = MergeTwoSortedLists(p1, p2);
    print(res);
	return 0;
}