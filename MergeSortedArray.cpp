#include<iostream>
#include<string>
#include<vector>
using namespace std;


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    if(n==0)
        return ;
    if(m==0)
    {
        for(int i=0;i<n;i++)
            nums1[i]=nums2[i];
        return ;

    }
    vector<int> tmpNum={0};
    for(int i=0;i<m;i++)
        tmpNum[i]=nums1[i];
    int index2=0,index1=0;

    while(true)
    {
        if(nums2[index2]<tmpNum[index1])
        {
            tmpNum.insert(tmpNum.begin()+index1,nums2[index2]);
            index1++;
            index2++;
            if(index2==n)
                break;
        }
        else
            index1++;
        if(index1==tmpNum.size())
        {
            while(index2!=n)
            {
                tmpNum.push_back(nums2[index2]);
                index2++;
            }
            break;
        }
    }
            for(int j=0;j<(m+n);j++)
        {
            nums1[j]=tmpNum[j];
        }
}

int main()
{
    cout<<"Haha";

}
