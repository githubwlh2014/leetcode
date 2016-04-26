#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>> threeInt;
    if(nums.size()<3)
        return threeInt;
    sort(nums.begin(),nums.end(),less<int>());
    int twoSum=0;
    for(int i=0;i<nums.size()-2;i++)
    {
        if(0!=i&&nums[i]==nums[i-1])
            continue;
        twoSum=0-nums[i];
        int startLocation=i+1;
        int endLocation=nums.size()-1;

        while(startLocation<endLocation)
        {
            if(nums[startLocation]+nums[endLocation]<twoSum)
                startLocation++;
            else if(nums[startLocation]+nums[endLocation]>twoSum)
                endLocation--;
            else
            {
                if(threeInt.size()!=0&&threeInt[threeInt.size()-1][0]==nums[i]&&threeInt[threeInt.size()-1][1]==nums[startLocation])
                {
                    startLocation++;
                    continue;
                }
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[startLocation]);
                tmp.push_back(nums[endLocation]);
                threeInt.push_back(tmp);
                startLocation++;
                endLocation--;
            }
        }

    }
    return threeInt;
}

int main()
{
    vector<int> nums={0,0,0};
    vector<vector<int>> tmp=threeSum(nums);
    for(int i=0;i<tmp.size();i++)
    {
        for(int j=0;j<tmp[i].size();j++)
            cout<<tmp[i][j]<<" ";
        cout<<endl;
    }
}
