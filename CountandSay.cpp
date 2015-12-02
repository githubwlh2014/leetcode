#include<iostream>
#include<string>
using namespace std;
string convert(string& say)
{
    char pre=say[0];
    int coun=1;
    string tmp="";

    int len=say.size();
    for(int i=1;i<len;i++)
    {
        if(pre==say[i])
        {
            coun++;
        }else
        {
            tmp+=char(coun+'0');
            tmp+=pre;
            pre=say[i];
            coun=1;
        }
    }
    tmp+=char(coun+'0');
    tmp+=pre;

    return tmp;
}

string countAndSay(int n) {

    string say="1";

    for(int i=1;i<n;i++)
        say=convert(say);

    return say;

}

int main()
{
    int in;
    while(true)
    {
        cin>>in;
        cout<<countAndSay(in)<<endl;

    }

}
