#include<iostream>
#include<vector>
#include<string>
using namespace std;

string itoa(int m)
{
    if(m==0)
        return "0";
    string tag="";
    string str="";
    if(m<0)
    {
        tag+='-';
        m=-m;
    }

    while(m)
    {
        str=char(m%10+'0')+str;
        m/=10;
    }
    str=tag+str;
    return str;
}

vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    string str="";
    int len=nums.size();
    int tag=nums[0];
    for(int i=0;i<len;i++)
    {
        if(nums[i]==tag)
        {

        }
    }
}

int main()
{
    cout<<itoa(-12);

}
