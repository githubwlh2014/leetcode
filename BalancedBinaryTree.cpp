#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int balDepth(TreeNode * root,bool* tag)
{
    if(root==NULL)
        return 0;
    if(tag)
    {
        int leftLen=balDepth(root->left,tag)+1;
        int rightLen=balDepth(root->right,tag)+1;
        if(leftLen-rightLen>1||leftLen-rightLen<-1)
            *tag=false;
        return leftLen>rightLen?leftLen:rightLen;
    }
    else
    return 0;


}

bool isBalanced(TreeNode* root) {
    bool tag=true;
    balDepth(root,&tag);
    if(!tag)
    {
        return tag;
    }
    else
        return tag;
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
    TreeNode* root;
    CreateBiTree(root);
    if(isBalanced(root))
        cout<<"二叉树为平衡二叉树"<<endl;
    else
        cout<<"二叉树不是平衡二叉树"<<endl;
}
