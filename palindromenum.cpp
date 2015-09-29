#include<iostream>
using namespace std;

bool isPalindrome(int x) {

    int tmp=x;
    int reX=0;

    if(x<0)
        return false;
    while(tmp>0)
    {
        reX=reX*10+tmp%10;
        tmp/=10;

    }
    if(reX==x)
        return true;
    else
        return false;
}

int main()
{


}
