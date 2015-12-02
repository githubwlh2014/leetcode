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
    int countA=0;
    int countB=0;
    ListNode* pA=headA;
    ListNode* pB=headB;

    while(NULL!=pA)
    {
        countA++;
        pA=pA->next;
    }
    while(NULL!=pB)
    {
        countB++;
        pB=pB->next;
    }

    pA=headA;
    pB=headB;
    while(pA!=pB)
    {
        if(countA>countB)
        {
            pA=pA->next;
            countA--;
        }else if(countB>countA)
        {
            pB=pB->next;
            countB--;
        }else{
            pA=pA->next;
            pB=pB->next;
        }
    }
    return pA;
}

int main()
{
    ListNode tmp1(1),tmp2(2),tmp3(3);
    tmp1.next=&tmp2;
    tmp3.next=&tmp2;
    ListNode* pNode=getIntersectionNode(&tmp1,&tmp3);
    cout<<pNode->val;

}
