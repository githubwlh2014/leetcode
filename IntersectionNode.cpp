#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(headA==NULL||headB==NULL)
        return NULL;
    if(headA==headB)
        return headA;
    ListNode* tmpA=headA;
    ListNode* tmpB=headB;
    bool tag=false;
    int countNode=1;

    while(tmpA->next!=NULL)
    {
        countNode++;
        tmpA=tmpA->next;

    }
    tmpA->next=headA;

    while(tmpB!=NULL)
    {
        if(tmpB==headA)
        {
            tag=true;
            break;
        }
        tmpB=tmpB->next;
    }
    tmpB=headB;
    tmpA=headB->next;
    if(tag)
    {
        while(tmpA!=tmpB)
        {
            if(countNode>1)
            {
                countNode--;
            }
            else
                tmpB=tmpB->next;
            tmpA=tmpA->next;
        }
    }
    tmpA=headA;
    while(tmpA->next!=headA)
        tmpA=tmpA->next;
    tmpA->next=NULL;
    if(tag)
        return tmpB;
    else
        return NULL;


}

int main(){
    ListNode tmp1(1),tmp2(2),tmp3(3);
    tmp1.next=&tmp2;
    tmp3.next=&tmp2;
    ListNode* pNode=getIntersectionNode(&tmp1,&tmp3);
    cout<<pNode->val;


}
