#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void mergeTwoLists(ListNode* l1,ListNode* l2,ListNode* head)
{
    if(l1==nullptr)
    {
        head->next=l2;
        return;
    }
    if(l2==nullptr)
    {
        head->next=l1;
        return;
    }
    if(l1->val<l2->val)
    {
        head->next=l1;
        head=head->next;
        l1=l1->next;
        mergeTwoLists(l1,l2,head);
    }else
    {
        head->next=l2;
        head=head->next;
        l2=l2->next;
        mergeTwoLists(l1,l2,head);
    }
    return;
}
ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if(lists.size()==0)
        return nullptr;
    ListNode* head=new ListNode(0);
    while(lists.size()>1)
    {
        mergeTwoLists(lists[0],lists[1],head);
        lists.push_back(head->next);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
    delete head;
}


/*
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size()==0)
        return nullptr;
    if(lists.size()==1)
        return lists[0];
    int tagIndex=0;
    ListNode* tagTmp=nullptr;
    int tagLoop=1;
    ListNode* head=nullptr;
    ListNode* pre=nullptr;
    ListNode l(INT_MAX);
    tagTmp=&l;
    while(tagLoop)
    {
        tagLoop=0;
        int i=0;
        for(;i<lists.size();i++)
        {
            if(lists[i]!=nullptr)
            {
                tagLoop++;
                if(lists[i]->val<tagTmp->val)
                {
                    tagTmp=lists[i];
                    tagIndex=i;
                }
            }
        }
        if(head==nullptr&&tagTmp!=&l)
        {
             pre=head=tagTmp;
             lists[tagIndex]=lists[tagIndex]->next;
        }
        else if(tagLoop)
        {
            lists[tagIndex]=lists[tagIndex]->next;
             pre->next=tagTmp;
             pre=pre->next;
        }
        if(tagLoop==1)
        {
            break;
        }

        tagTmp=&l;
    }
    return head;
}*/

int main()
{
    ListNode l(1);
    vector<ListNode*> ll;
    ll.push_back(nullptr);
    ll.push_back(nullptr);
    for(ListNode* p=mergeKLists(ll);p!=nullptr;p=p->next)
        cout<<p->val<<" ";
}
