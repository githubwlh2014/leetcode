#include<iostream>
using namespace std;

uint32_t reverseBits(uint32_t n) {
    uint32_t reverseN=0;
    for(int i=0;i<32;i++)
    {
        reverseN=reverseN<<1;
        reverseN=reverseN+(n%2);
        n=n>>1;
    }
    return reverseN;
}

int main()
{
    int m=5;
    cout<<(m<<2)<<endl;
    cout<<reverseBits(43261596)<<endl;
}
