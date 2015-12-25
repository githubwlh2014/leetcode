#include<iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head) {
    if(head==NULL||head->next==NULL)
        return true;
    ListNode* pre=head,*bac=head,*tmp,*pal=NULL;
    while(pre->next!=NULL&&pre->next->next!=NULL)
    {

        pre=pre->next->next;
        tmp=bac;
        bac=bac->next;
        tmp->next=pal;
        pal=tmp;
    }

    if(pre->next==NULL)
    {
        pre=bac->next;
        bac=pal;
    }else
    {
        pre=bac->next;
        bac->next=pal;
    }

    while(pre!=NULL)
    {
        if(bac->val==pre->val)
        {
            bac=bac->next;
            pre=pre->next;
        }
        else
            return false;
    }
    return true;

}

int main()
{
    ListNode m(12);
    ListNode n(2);
    ListNode h(1);

    m.next=&n;
    n.next=&h;
    cout<<isPalindrome(&n)<<endl;
}
