#include<iostream>
using namespace std;

bool isBadVersion(int i){
    return false;
}
int reBinSea(long minB,long maxB)
{
    if(minB==maxB)
        return minB;
    int mid=(minB+maxB)/2;
    if(isBadVersion(mid))
            maxB=mid;
    else
    {
        minB=mid;
    }

    return reBinSea(minB,maxB);

}


int firstBadVersion(int n) {
    return reBinSea(1,n);
}

int main()
{
    long m=2147483647;
    long n=2147483647;
    cout<<((m+n)/2)<<endl;
}
