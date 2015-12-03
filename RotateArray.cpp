#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
    k=k%nums.size();
    if(k==0)
        return;
    int len=nums.size()-k;
    for(int i=0;i<len;i++)
    {
        nums.push_back(nums[i]);
    }
    nums.erase(nums.begin(),nums.begin()+len);
}

int main()
{
    cout<<"Hello world"<<endl;
}
