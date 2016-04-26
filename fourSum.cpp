#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {

    vector<vector<int>> fourInt;
    if(nums.size()<4)
        return fourInt;
    sort(nums.begin(),nums.end(),less<int>());
    int twoSum=0;
    for(int j=0;j<nums.size()-3;j++)
    {
        if(j!=0&&nums[j]==nums[j-1])
            continue;
        for(int i=j+1;i<nums.size()-2;i++)
        {
            if((j+1)!=i&&nums[i]==nums[i-1])
                continue;
            twoSum=target-nums[j]-nums[i];
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
                    if(fourInt.size()!=0&&fourInt[fourInt.size()-1][1]==nums[i]
                       &&fourInt[fourInt.size()-1][2]==nums[startLocation]&&fourInt[fourInt.size()-1][0]==nums[j])
                    {
                        startLocation++;
                        continue;
                    }
                    vector<int> tmp;
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[startLocation]);
                    tmp.push_back(nums[endLocation]);
                    fourInt.push_back(tmp);
                    startLocation++;
                    endLocation--;
                }
            }

        }
    }

    return fourInt;
}

int main()
{
    vector<int> nums={-1,0,-5,-2,-2,-4,0,1,-2};
    vector<vector<int>> tmp=fourSum(nums,-9);
    for(int i=0;i<tmp.size();i++)
    {
        for(int j=0;j<tmp[i].size();j++)
            cout<<tmp[i][j]<<" ";
        cout<<endl;
    }
}
