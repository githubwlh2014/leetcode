#include<iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode* root)
{
    if(root==NULL)
        return 0;
    int leftDepth=0;
    int rightDepth=0;
    return (leftDepth=(maxDepth(root->left)+1))>(rightDepth=(maxDepth(root->right)+1))?leftDepth:rightDepth;

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
    TreeNode* p;
    CreateBiTree(p);
    cout<<maxDepth(p)<<endl;

}
