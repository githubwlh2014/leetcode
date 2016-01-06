#include<iostream>
using namespace std;
string itoa(int m)
{
    if(m==0)
        return "0";
    if(m==-2147483648)
        return "-2147483648";
    string tag="";
    string str="";
    if(m<0)
    {
        tag+='-';
        m=-m;
    }

    while(m)
    {
        str=char(m%10+'0')+str;
        m/=10;
    }
    str=tag+str;
    return str;
}
string getHint(string secret, string guess) {
    int countBull=0;
    int countCow=0;
    int conSec[10]={0};
    int conGue[10]={0};
    int i=0;
    while(i<secret.size())
    {
        if(secret[i]==guess[i])
        {
            countBull++;
        }
        else
        {
            conSec[(int(secret[i]-'0'))]++;
            conGue[(int(guess[i]-'0'))]++;
        }
        i++;
    }
    for(int i=0;i<10;i++)
    {
        countCow+=(conSec[i]>conGue[i]?conGue[i]:conSec[i]);
    }
    return (itoa(countBull)+'A'+itoa(countCow)+'B');
}

int main()
{
    cout<<getHint("1123","0111");
}
