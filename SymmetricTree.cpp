#include<iostream>
#include<deque>
#include<math.h>
using namespace std;



struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSymmetric(TreeNode* root) {

    if(root==NULL)
        return true;

    deque<TreeNode*> de1;
    deque<TreeNode*> de2;
    deque<TreeNode*> *tmp1,*tmp2,*tmp3;

    de1.push_back(root);
    de2.push_back(root);
    de2.clear();
    tmp1=&de1;
    tmp2=&de2;

    while(tmp1->size()!=0)
    {
        int len=ceil(float(tmp1->size())/2);
        int cou=1;
        deque<TreeNode*>::iterator beg=tmp1->begin();
        deque<TreeNode*>::iterator en=tmp1->end();
        en--;
        while(cou<=len)
        {
            if((*beg)->left!=NULL&&(*en)->right!=NULL)
            {
                if((*beg)->left->val!=(*en)->right->val)
                    return false;
                else
                {
                    tmp2->push_front((*beg)->left);
                    tmp2->push_back((*en)->right);
                }
            }
            else if((*beg)->left==NULL&&(*en)->right==NULL)
            {
                ;
            }else return false;

            if((*beg)->right!=NULL&&(*en)->left!=NULL)
            {
                if((*beg)->right->val!=(*en)->left->val)
                    return false;
                else
                {
                    tmp2->push_front((*beg)->right);
                    tmp2->push_back((*en)->left);
                }
            }
            else if((*beg)->right==NULL&&(*en)->left==NULL)
            {
                ;
            }else return false;
            cou++;
            beg++;
            en--;
        }
            tmp3=tmp1;
            tmp1=tmp2;
            tmp2=tmp3;
            tmp2->clear();
    }
    return true;

}

void CreateBiTree(TreeNode* &T){

    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else{
        T=new TreeNode(-1);
        T->val=int(ch-'0');
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}
int main()
{
    deque<int> m;
    m.push_back(3);
    deque<int>::iterator it=m.end();
    it--;
    TreeNode p(1);
    TreeNode q(2);
    p.left=&q;
    //CreateBiTree(p);
    cout<<isSymmetric(&p)<<endl;
}
