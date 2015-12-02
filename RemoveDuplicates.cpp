#include<iostream>
using namespace std;



struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* head) {

    if(!head)
        return head;

    int pre=head->val;
    ListNode* tmp=head;
    ListNode* del;

    while(tmp->next)
    {
        if(pre==tmp->next->val)
        {
            tmp->next=tmp->next->next;

        }else{
            pre=tmp->next->val;
            tmp=tmp->next;
        }
    }

    return head;

}

int main()
{
    ListNode* head;
    ListNode* tmp;
    tmp=head=new ListNode(1);
    //int m=tmp->next->val;
    for(int i=1;i<10;i++)
    {
        tmp->next=new ListNode(i);
        tmp=tmp->next;
    }
    head=NULL;
    head=deleteDuplicates(head);

    while(head)
    {
        cout<<head->val<<" ";
        head=head->next;
    }
}



