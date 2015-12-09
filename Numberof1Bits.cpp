#include<iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int countBit=0;
    while(n)
    {
        countBit+=(n&1);
        n>>=1;
    }

    return countBit;
}

int main()
{
    uint32_t n=3;
    cout<<hammingWeight(n)<<endl;
}
