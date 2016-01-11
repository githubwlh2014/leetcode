#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    int weight=0;
    ListNode* tmp,*head,*pl2=new ListNode(0);
    head=l1;

    while(l1!=NULL)
    {
        l1->val=l1->val+l2->val+weight;
        if(l1->val>=10)
        {
            l1->val=l1->val-10;
            weight=1;
        }
        else
            weight=0;
        tmp=l1;
        l1=l1->next;
        l2=l2->next;
        if(l1==NULL)
        {
            tmp->next=l2;
            l1=l2;
            l2=pl2;
        }
        if(l2==NULL)
            l2=pl2;
    }
    if(l1==NULL)
    {
        if(weight==1)
        {
            l1=new ListNode(1);
            tmp->next=l1;
        }
        return head;
    }
}

int main()
{
    ListNode*p1=new ListNode(1);
    ListNode* tmp1=p1;
    for(int i=2;i<10;i++)
    {
        p1->next=new ListNode(i);
        p1=p1->next;
    }
    ListNode*p2=new ListNode(1);
    ListNode*tmp2=p2;
    for(int i=2;i<9;i++)
    {
        p2->next=new ListNode(i);
        p2=p2->next;
    }
    tmp1=addTwoNumbers(tmp1,tmp2);
    while(tmp1!=NULL)
    {
        cout<<tmp1->val;
        tmp1=tmp1->next;
    }

}
