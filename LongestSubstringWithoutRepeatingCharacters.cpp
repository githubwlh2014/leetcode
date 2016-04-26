#include<iostream>
#include<unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s=="")
        return 0;
    unordered_map<char,int> lenMap;
    int length=0;
    int maxLen=1;
    for(int i=0;i<s.size();i++)
    {
        if(lenMap.find(s[i])==lenMap.end())
        {
            length++;
            lenMap.insert(unordered_map<char,int>::value_type(s[i], 1));
        }else
        {
            lenMap.clear();
            int len=i-length;
            length=1;
            int j=i-1;
            lenMap[s[i]]=1;
            while(j>=len)
            {
                if(s[i]!=s[j])
                {
                    length++;
                    lenMap.insert(unordered_map<char,int>::value_type(s[j], 1));
                    j--;
                }
                else
                    break;
            }
        }
        if(length>maxLen)
           maxLen=length;
    }
    return maxLen;
}

int main()
{
    cout<<lengthOfLongestSubstring("abcabcbb");
}
