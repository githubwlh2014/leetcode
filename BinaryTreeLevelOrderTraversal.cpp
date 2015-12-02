#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> store;
    queue<TreeNode*> que;
    que.push(root);
    if(root==NULL)
        return store;
    int siz=que.size();
    while(siz>0)
    {
        vector<int> leStore;
        int len=siz;
        while(len)
        {
            if(que.front()->left!=NULL)
                que.push(que.front()->left);
            if(que.front()->right!=NULL)
                que.push(que.front()->right);
            leStore.push_back(que.front()->val);
            que.pop();
            len--;
        }
        store.push_back(leStore);
        siz=que.size();
    }
    return store;
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
    vector<vector<int>> tmp=levelOrder(p);

    for(int i=0;i<tmp.size();i++)
    {
         for(int j=0;j<tmp[i].size();j++)
        {
            cout<<tmp[i][j]<<" ";
        }
        cout<<endl;

    }

}
