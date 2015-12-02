#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void findPath(TreeNode* root,int sum,int pre,bool* is)
{
    if(root==NULL)
        return ;
    pre=pre+root->val;
    if(root->left==NULL&&root->right==NULL&&pre==sum)
        *is=true;
    if(!(*is))
    {
        findPath(root->left,sum,pre,is);
        findPath(root->right,sum,pre,is);

    }
    else
        return ;

}

bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)
        return false;
    bool is=false;
    findPath(root,sum,0,&is);
    return  is;
}

void CreateBiTree(TreeNode* &T){

    int ch;
    cin>>ch;
    //cout<<char(ch)<<endl;
    if(char(ch)=='#') T=NULL;
    else{
        T=new TreeNode(-1);
        T->val=ch;
        CreateBiTree(T->left);
        CreateBiTree(T->right);
    }
}

int main()
{

    TreeNode root(0);
    TreeNode* pRoot;
    CreateBiTree(pRoot);
    if(hasPathSum(pRoot,22))
        cout<<"´æÔÚ"<<endl;
    else
        cout<<"²»´æÔÚ"<<endl;

}
