#include<iostream>
#include<vector>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool searchNode(TreeNode* root,TreeNode* node,vector<TreeNode*>& stackO)
{
    if(root==NULL)
        return false;
    stackO.push_back(root);
    if(root==node)
    {
        return true;
    }
    else if(root->val>node->val)
    {
      searchNode(root->left,node,stackO);
    }
    else if(root->val<node->val)
    {
      searchNode(root->right,node,stackO);
    }

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root||!p||!q)
        return NULL;
    vector<TreeNode*> st1,st2;
    if(searchNode(root,p,st1)&&searchNode(root,q,st2))
    {
        int len=st1.size()>st2.size()?st2.size():st1.size();
        for(int i=0;i<len;i++)
            if(st1[i]!=st2[i])
                return st1[i-1];
        return st1[len-1];
    }else
    return NULL;
}

int main()
{
    TreeNode m(2);
    TreeNode n(1);
    TreeNode p(3);
    m.left=&n;
    m.right=&p;

    cout<<lowestCommonAncestor(&m,&n,&m)->val<<endl;
}
