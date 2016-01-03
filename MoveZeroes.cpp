#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int countZero=0;
    int index=0;
    int len=nums.size();
    for(int i=0;i<len;i++)
    {
        if(nums[i]==0)
            countZero++;
        else
        {
            nums[index]=nums[i];
            index++;
        }
    }
    while(countZero--)
    {
        len--;
        nums[len]=0;
    }

}

int main()
{
    vector<int> nums={1,2,3,0,0,0,2,3,4,5};
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    moveZeroes(nums);
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
}
