#include<iostream>
#include<vector>
using namespace std;

int findIndex(vector<int>& nums1, vector<int>& nums2,int index)
{
    int low=0;
    int high=nums1.size()-1;
    int mid=0;
    while(low<=high)
    {
        mid=low+(high-low)/2;
        if(mid+1<index)
        {
            if(nums2[index-2-mid]<=nums1[mid]&&nums2[index-1-mid]>=nums1[mid])
                return nums1[mid];
            else
            {
                if(nums2[index-2-mid]>nums1[mid])
                    low=mid+1;
                else
                    high=mid-1;
            }
        }
        else if(mid+1==index)
        {
            if(nums2[0]>=nums1[mid])
                return nums1[mid];
        }
        else{
            high=mid-1;
        }

    }
    return -1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int first,second;
    int len=nums1.size()+nums2.size();
    int mid=len/2;
    if(nums1.size()==0)
    {
        first=nums2[mid-1];
        second=nums2[mid];
    }
    else if(nums2.size()==0)
    {
        first=nums1[mid-1];
        second=nums1[mid];
    }
    else
    {
      //  first=findIndex(nums1,nums2,mid)==-1?findIndex(nums2,nums1,mid):findIndex(nums1,nums2,mid);
      //  second=findIndex(nums1,nums2,mid+1)==-1?findIndex(nums2,nums1,mid+1):findIndex(nums1,nums2,mid+1);
      if(first=findIndex(nums1,nums2,mid)!=-1)
      {

      }


    }
    if(len%2==1)
        return second;
    else
        return double(first+second)/2;
}

int main()
{
    vector<int> nums1;
    cout<<nums1.size()<<endl;
    vector<int> nums2={1,2,3,4};
    cout<<findMedianSortedArrays(nums1,nums2);
}
