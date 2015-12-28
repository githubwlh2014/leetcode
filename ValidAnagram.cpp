#include<iostream>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.size()!=t.size())
            return false;
    if(s==t)
        return true;
    int len=s.size();
    int sContain[26]={0};
    int tContain[26]={0};
    for(int i=0;i<len;i++)
    {
        sContain[s[i]-'a']++;
        tContain[t[i]-'a']++;
    }

    for(int i=0;i<26;i++)
        if(sContain[i]!=tContain[i])
            return false;
    return true;
}

int main()
{
    cout<<isAnagram("te","et")<<endl;
}
