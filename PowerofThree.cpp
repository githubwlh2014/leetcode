#include<iostream>
using namespace std;

/*bool isPowerOfThree(int n) {
    if(1==n)
        return true;
    if(n<=0)
        return false;

    int sum=1;
    while(true)
    {
        sum+=sum<<1;
        if(sum==n)
            return true;
        else if(sum>n)
                return false;
    }
}*/

bool isPowerOfThree(int n){
    if(n<=0)
        return false;
    while(n!=1)
    {
        if(n%3!=0)
            return false;
        n=n/3;
    }
    return true;
}

int main()
{
    cout<<isPowerOfThree(9)<<endl;
}
