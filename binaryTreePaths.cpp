#include<iostream>
#include<string>
#include<vector>
using namespace std;
string itoa(int m)
{
    if(m==0)
        return "0";
    if(m==-2147483648)
        return "-2147483648";
    string tag="";
    string str="";
    if(m<0)
    {
        tag+='-';
        m=-m;
    }

    while(m)
    {
        str=char(m%10+'0')+str;
        m/=10;
    }
    str=tag+str;
    return str;
}
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 void searchPaths(TreeNode* root,vector<string>& contains,vector<int>& stackOfNode)
 {
     if(root==NULL)
            return ;
     stackOfNode.push_back(root->val);
     if(root->left==NULL&&root->right==NULL)
     {
         string str=itoa(stackOfNode[0]); //转换
         for(int i=1;i<stackOfNode.size();i++)
         {
            str+="->"+itoa(stackOfNode[i]);  //转换
         }
         contains.push_back(str);
     }else
     {
         searchPaths(root->left,contains,stackOfNode);
         searchPaths(root->right,contains,stackOfNode);
     }
     stackOfNode.erase(stackOfNode.end()-1);//如果此处用的不是引用，即可省去这一步


 }

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> contains;
    vector<int> stackOfNode;
    if(!root)
        contains;
    searchPaths(root,contains,stackOfNode);
    return contains;
}
int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    t4.left=&t2;
    t2.left=&t1;
    t2.right=&t3;
    vector<string> contains=binaryTreePaths(&t4);
    for(int i=0;i<contains.size();i++)
        cout<<contains[i]<<endl;

}
