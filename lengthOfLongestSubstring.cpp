#include<iostream>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int startLocation=0,maxLen=0;
    int exit[128];
    for(int i=0;i<128;i++)
        exit[i]=-1;
    int length=s.size();
    for(int j=0;j<length;j++)
    {
        if(exit[int(s[j])]==-1||exit[int(s[j])]<startLocation)
            exit[int(s[j])]=j;
        else
        {
            if(maxLen<(j-startLocation))
                maxLen=j-startLocation;
            startLocation=exit[int(s[j])]+1;
            exit[int(s[j])]=j;
        }
    }
    if(maxLen<(length-startLocation))
        maxLen=length-startLocation;
    return maxLen;
}

int main()
{
    string str="";
    cin>>str;
   // str="";
    cout<<lengthOfLongestSubstring(str)<<endl;
}
