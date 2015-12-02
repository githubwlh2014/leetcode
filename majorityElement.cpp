#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    unordered_map<int,int> choseMajor;
    int len=nums.size();
    int comp=len/2;
    for(int i=0;i<len;i++)
    {
        if(choseMajor.end()==choseMajor.find(nums[i]))
            choseMajor.insert(map<int,int>::value_type(nums[i],1));
        else
            choseMajor[nums[i]]++;
    }
    unordered_map<int,int>::iterator pos=choseMajor.begin();
    unordered_map<int,int>::iterator epos=choseMajor.end();
    for(;pos!=epos;pos++)
        if(pos->second>comp)
            return pos->first;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(2);
        nums.push_back(2);
    cout<<majorityElement(nums)<<endl;

}
