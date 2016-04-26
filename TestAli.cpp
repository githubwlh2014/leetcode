#include<iostream>
#include<stdio.h>
using namespace std;

int maxDivisior(int a,int b)
{
    if(a%b==0)
        return b;
    else
    {
        int c=b;
        b=a%b;
        a=c;
        return maxDivisior(a,b);
    }

}

int maxMultiple(int a,int b)
{
    int divisior=0;
    if(a>b)
        divisior=maxDivisior(a,b);
    else
        divisior=maxDivisior(b,a);

    return (a*b)/divisior;
}

int main()
{
    int a,b;
    char name[10];
    while(cin.get(name,10))
    {
        cin.get();
        cout<<name<<endl;
    }
}
