#include<iostream>
#include<limits.h>
using namespace std;

/*int addDigits(int num) {
    int index[]={0,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,2};
    int sum=0;
    while(num)
    {
        sum+=num%10;
        num/=10;
    }
    while(sum)
    {
        num+=sum%10;
        sum/=10;
    }

    return index[num];
}*/

int addDigits(int num)
{
    return num < 10 ? num:((num-1)%9+1);
}

int main()
{
    cout<<869<<endl;
    cout<<addDigits(869)<<endl;
}
