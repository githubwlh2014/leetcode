#include<iostream>
#include<vector>
using namespace std;

class NumArray {
    private: int *p;
public:
    NumArray(vector<int> &nums) {
        int sum=0;
        p=new int[nums.size()];
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            *(p+i)=sum;
        }
    }

    int sumRange(int i, int j) {
        if(i==0)
            return *(p+j);
        return (*(p+j)-*(p+i-1));
    }
};

int main()
{
    vector<int> nums,*pnums;
    for(int i=0;i<10;i++)
        nums.push_back(i);
    NumArray numArray(nums);
    numArray.sumRange(0, 1);
    numArray.sumRange(1, 2);
    cout<<numArray.sumRange(0, 1)<<endl;
    cout<<numArray.sumRange(1, 9)<<endl;
}
