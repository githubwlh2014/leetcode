#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int rob(vector<int>& nums) {
    int len=nums.size();
    if(len==0)
        return 0;
    if(len==1)
        return nums[0];
    if(len==2)
        return nums[0]>nums[1]?nums[0]:nums[1];
    queue<int> maxValue;
    int tmp=0;
    maxValue.push(nums[0]);
    maxValue.push(nums[1]);
    maxValue.push(nums[0]+nums[2]);
    for(int i=3;i<len;i++)
    {
        tmp=maxValue.front();
        maxValue.pop();
        maxValue.push((tmp>maxValue.front()?tmp:maxValue.front())+nums[i]);
    }
    maxValue.pop();
    if(maxValue.front()>maxValue.back())
        return maxValue.front();
    else
        return maxValue.back();
}

int main()
{
    vector<int> nums={1,2,1,1,1};
    cout<<rob(nums);
}
