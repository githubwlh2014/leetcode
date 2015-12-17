#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
bool containsDuplicate(vector<int>& nums) {
    int len=nums.size();
    if(len==0||1==len)
        return false;
    sort(nums.begin(),nums.end());
    int pre=nums[0];
    for(int i=1;i<len;i++)
    {
        if(pre==nums[i])
            return true;
        else
        {
            pre=nums[i];
        }
    }
    return false;

}*/
bool containsDuplicate(vector<int>& nums) {
    if(0==nums.size()||1==nums.size())
        return false;
    unordered_map<int,int> conDu;
    for(int i=0;i<nums.size();i++)
    {
        if(conDu.find(nums[i])!=conDu.end())
            return true;
        else
            conDu.insert(pair<int,int>(nums[i],1));
    }

    return false;
}

int main()
{
    vector<int> tmp;
    for(int i=0;i<14;i++)
        tmp.push_back(i);
    tmp.push_back(0);
    cout<<containsDuplicate(tmp)<<endl;
}
