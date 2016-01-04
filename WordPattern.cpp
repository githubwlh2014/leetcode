#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

void split(vector<string>& contain,string str)
{
    string tmpStr="";
    for(int i=0;i<str.size();i++)
    {

        if(str[i]==' '&&tmpStr!="")
        {
            contain.push_back(tmpStr);
            tmpStr="";
        }
        if(str[i]!=' ')
        {
            tmpStr=tmpStr+str[i];
        }
    }
        if(tmpStr!="")
        contain.push_back(tmpStr);
}

bool wordPattern(string pattern, string str) {
    vector<string> contain;
    split(contain,str);
    if(contain.size()!=pattern.size())
        return false;
    string pat[26];
    for(int i=0;i<26;i++)
        pat[i]="";
    for(int i=0;i<pattern.size();i++)
    {
        if(pat[pattern[i]-'a']=="")
            pat[pattern[i]-'a']=contain[i];
        else
            if(pat[pattern[i]-'a']!=contain[i])
                return false;
    }

    sort(pat,pat+26);
    string pre=pat[25];
    for(int j=24;j>=0;j--)
        if(pat[j]!="")
        {
            if(pat[j]==pre)
                return false;
            else
            {
                pre=pat[j];
            }
        }
    return true;

}

int main()
{
    cout<<('z'-'a')<<endl;
    cout<<wordPattern("abba","dog cat cat dog");
}
