#include<iostream>
#include<map>
using namespace std;

bool isIsomorphic(string s, string t) {
    int len=s.size();
    map<char,char> tmp1;
    map<char,char> tmp2;

    for(int i=0;i<len;i++)
    {
        if(tmp1.find(s[i])!=tmp1.end())
        {
            if(tmp1[s[i]]==t[i])
                continue;
            else
                return false;
        }
        else
            tmp1.insert(pair<char,char>(s[i],t[i]));

        if(tmp2.find(t[i])!=tmp2.end())
        {
            if(tmp2[t[i]]==s[i])
                continue;
            else
                return false;
        }
        else
            tmp2.insert(pair<char,char>(t[i],s[i]));
    }
    return true;
}

int main()
{
    if(isIsomorphic("ab","aa"))
        cout<<"可以"<<endl;
    else
        cout<<"不可以"<<endl;

}
