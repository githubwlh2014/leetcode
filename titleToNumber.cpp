#include<iostream>
#include<string>
using namespace std;

int titleToNumber(string s) {
    int len=s.size();
    int result=0;
    for(int index=0;index<len;index++)
    {
        result=result*26+s[index]-'A'+1;
    }
    return result;
}

int main()
{
    cout<<titleToNumber("AA");
}
