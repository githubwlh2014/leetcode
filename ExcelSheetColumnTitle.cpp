#include<iostream>
#include<string>
using namespace std;


string convertToTitle(int n) {
    string title="";
    if(0==n)
        return title;
    while(n)
    {
        if(n%26!=0)
        {
            title=char((n%26)-1+'A')+title;
            n=n/26;
        }
        else
        {
            title='Z'+title;
            n=n/26-1;
        }
    }
    return title;
}
int main()
{
    cout<<convertToTitle(53)<<endl;
}
