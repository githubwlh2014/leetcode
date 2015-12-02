#include<iostream>
#include <string.h>
#include<ctype.h>
using namespace std;

bool isPalindrome(string s) {
    if(s=="")
        return true;
    int preIndex=0;
    int backIndex=s.size()-1;
    bool preTag=false;
    bool backTag=false;
    while(true)
    {
        if(isalnum(s[preIndex]))
        {
            preTag=true;
        }else
            preIndex++;
         if(isalnum(s[backIndex]))
        {
            backTag=true;
        }else
            backIndex--;
        if(backIndex<preIndex)
            return true;

        if(preTag&&backTag)
        {
            if(tolower(s[preIndex])!=tolower(s[backIndex]))
                return false;
            preIndex++;
            backIndex--;
            preTag=false;
            backTag=false;
        }
        if(backTag<0)
            return true;
    }
}

int main()
{

    if(isPalindrome("s  ,S  ,  s  ' / ,s"))
        cout<<"是回文字符串"<<endl;
    else
        cout<<"不是回文客串"<<endl;

}
