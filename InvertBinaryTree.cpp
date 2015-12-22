#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root) {
    if(NULL==root)
            return NULL;
    invertTree(root->left);
    invertTree(root->right);
    TreeNode* tmp=root->left;
    root->left=root->right;
    root->right=tmp;
}

int main()
{

}
