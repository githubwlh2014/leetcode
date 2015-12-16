#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
ListNode* reverseList(ListNode* head) {
    ListNode* pre=NULL;
    ListNode* bac=head;
    while(head!=NULL)
    {
        head=head->next;
        bac->next=pre;
        pre=bac;
        bac=head;
    }
    return pre;
}
*/
ListNode* reverseList(ListNode*head,ListNode*pre)
{
    if(head->next==NULL)
    {
        head->next=pre;
        return head;
    }
    else
    {
        ListNode* tmp=head->next;
        head->next=pre;
        pre=head;
        head=tmp;
        return reverseList(head,pre);
    }
}

ListNode* reverseList(ListNode* head) {
    if(head==NULL)
        return NULL;
    ListNode*tmp=NULL;
    return reverseList(head,tmp);
}



int main()
{
    ListNode* head=NULL,*tmp;
    head=tmp=new ListNode(0);
    for(int i=0;i<10;i++)
    {
        tmp->next=new ListNode(i);
        tmp=tmp->next;
    }
    head=reverseList(head);
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }

}
