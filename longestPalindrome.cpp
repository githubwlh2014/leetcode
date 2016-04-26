#include<iostream>
using namespace std;

string longestPalindrome(string s) {
    if(s.size()==0)
        return "";
    int startLocation=0;
    int endLocation=0;
    int maxLen=0;
    int k=0;
    int j=0;
    for(int i=0;i<s.size();)
    {
        if(s.size()-i-1<(maxLen/2))
            break;
        k=j=i;
        while(i+1<s.size()&&s[i]==s[i+1])
        {
            i++;
        }
        j=i++;
        while(j+1<s.size()&&k>0&&s[k-1]==s[j+1])
        {
            k--;
            j++;
        }
        if(j-k+1>maxLen)
        {
            startLocation=k;
            endLocation=j;
            maxLen=j-k+1;
        }

    }
    return s.substr(startLocation,maxLen);
}

int main()
{
    string str="abcbe";
    cout<<longestPalindrome(str)<<endl;

}
