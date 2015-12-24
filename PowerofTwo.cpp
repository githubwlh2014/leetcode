#include<iostream>
#include<limits.h>
using namespace std;

bool isPowerOfTwo(int n) {
    if(n>0&&(n&(n-1))==0)
       return true;
    else
        return false;
}

bool isPowerOfTwo(int n) {
    return n>0 && !(n&(n-1));
}
int main()
{
    cout<<isPowerOfTwo(3);
}
