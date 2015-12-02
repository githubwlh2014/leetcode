#include<iostream>
#include<vector>
using namespace std;
vector<int> generateOne(const vector<int>& pre)
{
    vector<int> ba;
    ba.push_back(1);
    int len=pre.size()-1;
    for(int i=0;i<len;i++)
    {
        ba.push_back(pre[i]+pre[i+1]);
    }
    ba.push_back(1);
    return ba;
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pasTri;
    if(numRows==0)
        return pasTri;
    vector<int> pre;
    pre.push_back(1);
    pasTri.push_back(pre);

    for(int i=1;i<numRows;i++)
    {
        pre=generateOne(pre);
        pasTri.push_back(pre);
    }
    return pasTri;
}

int main()
{


}
