#include<iostream>
using namespace std;

int climbStairs(int n) {

    int step1=1;
    int step2=2,stepn;

    if(n<=0)
        return 0;


    for(int i=3;i<=n;i++)
    {
        stepn=step1+step2;
        step1=step2;
        step2=stepn;
    }

    return n>2?stepn:n;

}

int main()
{

    cout<<climbStairs(1);
}
