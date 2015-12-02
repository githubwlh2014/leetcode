#include<iostream>
using namespace std;

int trailingZeroes(int n) {
    int countFive=0;
    int j;
    for(int i=1;i*5<=n;i++)
    {
        countFive++;
        j=i;
        while(j%5==0)
        {
            countFive++;
            j=j/5;
        }
    }
    return countFive;
}

int main()
{
    cout<<trailingZeroes(50);

}
