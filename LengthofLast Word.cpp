#include<iostream>
#include<string>
using namespace std;

int lengthOfLastWord(string s) {

    int len=s.size();
    int countLast=0;

    for(int i=0;i<len;i++)
    {
        if(' '==s[i])
            countLast=0;
        else
        {
            ++countLast;
        }
    }
    return countLast;
}

int main()
{
   string in;
   while(true){

        cin>>in;
        cout<<lengthOfLastWord(in)<<endl;

   }
}
