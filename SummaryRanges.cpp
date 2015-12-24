#include<iostream>
#include<vector>
#include<string>
using namespace std;

string itoa(int m)
{
    if(m==0)
        return "0";
    if(m==-2147483648)
        return "-2147483648";
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
    if(len==0)
    {
        ranges.push_back("");
        return ranges;
    }
    int indexV=nums[0];
    for(int i=0;i<len;i++)
    {
        if(nums[i]==indexV)
        {
            if(str.length()>0)
                ;
            else
                str=itoa(indexV);
            indexV++;
        }
        else
        {
            if(str!=itoa(--indexV))
                str=str+"->"+itoa(indexV);
            ranges.push_back(str);
            str="";
            indexV=nums[i--];
        }
    }
        if(str!=itoa(--indexV))
            str=str+"->"+itoa(indexV);
        ranges.push_back(str);
    return ranges;
}

int main()
{
    vector<int> tmp;
    tmp.push_back(0);
    tmp.push_back(3);
    tmp.push_back(5);
    tmp.push_back(7);
    tmp.push_back(9);
    tmp.push_back(11);
    tmp.push_back(12);

    vector<string> tmp1=summaryRanges(tmp);

    for(int i=0;i<tmp1.size();i++)
        //cout<<tmp1[i]<<",";

    cout<<itoa(-2147483648)<<endl;
}
