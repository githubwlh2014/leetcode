#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(k==0)
        return false;
    unordered_map<int,int> conDu;
    for(int i=0;i<nums.size();i++)
    {
        if(conDu.size()<k)
        {
            if(conDu.find(nums[i])!=conDu.end())
                return true;
            else
                conDu.insert(pair<int,int>(nums[i],i));
        }
        else
        {
            if(conDu.find(nums[i])!=conDu.end())
                return true;
            else
            {
                conDu.erase(conDu.find(nums[i-k]));
                conDu.insert(pair<int,int>(nums[i],i));
            }
        }
    }
    return false;
}

int main()
{
    vector<int> tmp;
    for(int i=0;i<10;i++)
        tmp.push_back(i);
    tmp.push_back(8);
    cout<<containsNearbyDuplicate(tmp,4)<<endl;
}
