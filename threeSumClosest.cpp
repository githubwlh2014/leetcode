#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {

    sort(nums.begin(),nums.end(),less<int>());
    int closet=nums[0]+nums[nums.size()-1]+nums[1];
    int maxGap=closet-target;
    if(maxGap<0)
        maxGap=0-maxGap;
    for(int i=0;i<nums.size()-2;i++)
    {
        int startLocation=i+1;
        int endLocation=nums.size()-1;

        while(startLocation<endLocation)
        {
            if(nums[startLocation]+nums[endLocation]+nums[i]<target)
            {

                if(target-(nums[startLocation]+nums[endLocation]+nums[i])<maxGap)
                {
                    maxGap=target-(nums[startLocation]+nums[endLocation]+nums[i]);
                    closet=nums[startLocation]+nums[endLocation]+nums[i];
                }
                startLocation++;
            }
            else if(nums[startLocation]+nums[endLocation]+nums[i]>target)
            {

                if((nums[startLocation]+nums[endLocation]+nums[i])-target<maxGap)
                {
                    maxGap=(nums[startLocation]+nums[endLocation]+nums[i])-target;
                    closet=nums[startLocation]+nums[endLocation]+nums[i];
                }
                 endLocation--;
            }
            else
            {
                return target;
            }
        }

    }
    return closet;
}

int main()
{
    vector<int> nums={0,1,2};
    cout<<threeSumClosest(nums,0);
}
