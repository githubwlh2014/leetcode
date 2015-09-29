#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
     vector<int> result(2);
     int len=nums.size();
     unordered_map<int,int> hashMap;

     if(target%2==0){
        int mid=target/2;
        int count=0;

       for(int j=0;j<len;j++){
       if(nums[j]==mid)
        {

             result[count]=j+1;
             count++;
        }
     }
     if(count==2)
        return result;
     }


     for(int i=0;i<len;i++)
        hashMap[nums[i]]=i;

     unordered_map<int,int>::iterator beg = hashMap.begin(),
	 end = hashMap.end(),ite;

     while(beg!=end){
        if(hashMap.find(target-beg->first)!=end)
        {
            if(target-beg->first==beg->first)
            {
                beg++;
               continue;

            }

            if(hashMap[beg->first]<hashMap[target-beg->first])
            {
                result[0]=hashMap[beg->first]+1;
                result[1]=hashMap[target-beg->first]+1;
                return result;

            }else{
                result[1]=hashMap[beg->first]+1;
                result[0]=hashMap[target-beg->first]+1;
                return result;

        }

     }
        beg++;
    }
}

int main()
{
    cout<<"Test"<<endl;
}
