#include<iostream>
#include<string>
#include<vector>
using namespace std;

string map[]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
vector<string> output;
void letterCombinations(string digits,int index,string tmp){
    if(index==digits.size())
    {
        output.push_back(tmp);
        return ;
    }
    string str=map[digits[index]-'0'];
    for(int i=0;i<str.size();i++)
    {
        letterCombinations(digits,index+1,tmp+str[i]);
    }
}
vector<string> letterCombinations(string digits) {
    string tmp="";
    if(digits.size()==0)
        return output;
    else
        letterCombinations(digits,0,tmp);
    return output;
}

class Solution {
public:
    string map[10]={"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> output;
public:
    void letterCombinations(string digits,int index,string tmp){
        if(index==digits.size())
        {
            output.push_back(tmp);
            return ;
        }
        string str=map[digits[index]-'0'];
        for(int i=0;i<str.size();i++)
        {
            letterCombinations(digits,index+1,tmp+str[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        string tmp="";
        if(digits.size()==0)
            return output;
        else
            letterCombinations(digits,0,tmp);
        return output;
    }
};

int main()
{
    Solution s;
    string str="32";
    vector<string> output=s.letterCombinations(str);
    cout<<output.size()<<endl;
    output.push_back("");
    cout<<output.size()<<endl;
    for(int i=0;i<output.size();i++)
        cout<<output[i]<<endl;
}
