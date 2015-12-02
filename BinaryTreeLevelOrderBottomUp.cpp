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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> store,store1;
    queue<TreeNode*> que;
    que.push(root);
    if(root==NULL)
        return store;

   vector<int> *leStore=new vector<int>();

    while(que.size()>0)
    {
        int len=que.size();
        while(len)
        {
            if(que.front()->left!=NULL)
                que.push(que.front()->left);
            if(que.front()->right!=NULL)
                que.push(que.front()->right);
            leStore->push_back(que.front()->val);
            que.pop();
            len--;
        }
        store.push_back(*leStore);
        leStore->clear();
    }
    vector<vector<int>>::reverse_iterator  it=store.rbegin();
    while(it!=store.rend())
    {
        store1.push_back(*it);
        it++;
    }


    return store1;

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

    TreeNode*p;
    CreateBiTree(p);
    cout<<"zhixingmudihanshu"<<endl;
    levelOrderBottom(p);

}
