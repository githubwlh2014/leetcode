#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* removeElements(ListNode* head, int val) {
    if(head==NULL)
        return head;
    ListNode* tmp;
    ListNode* tmpHead=head;
    while(head!=NULL)
    {
        if(head->next!=NULL&&head->next->val==val)
        {
            tmp=head->next;
            head->next=head->next->next;
            delete tmp;
        }
        else
            head=head->next;
    }
    if(tmpHead->val==val)
    {
        tmp=tmpHead;
        tmpHead=tmpHead->next;
        delete tmp;
    }
    return tmpHead;

}

int main()
{
    ListNode* test,*tmp;
    tmp=test=new ListNode(0);
    for(int i=0;i<10;i++)
    {
        tmp->next=new ListNode(i);
        tmp=tmp->next;
    }
    ListNode* head=removeElements(test,0);
    //ListNode* head=test;
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}
