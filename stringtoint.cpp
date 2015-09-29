#include<iostream>
using namespace std;
int myAtoi(string str) {

    int len=str.length();
    bool tag=false;
    long long result=0;
    char zf='0';
    int count=0;

    for(int i=0;i<len;i++)
    {
        if(str[i]!=' '&&str[i]!='-'&&str[i]!='+'&&(str[i]>'9'||str[i]<'0'))
            break;
        if((str[i]<'0'||str[i]>'9')&&tag)
            break;
        if((str[i]=='-'||str[i]=='+')&&!tag)
        {
            zf=str[i];
            if(str[i+1]<'0'||str[1+i]>'9')
                break;

        }
        if(str[i]>='0'&&str[i]<='9')
        {
            result=result*10+str[i]-'0';
            tag=true;
            count++;

        }


    }

    if(tag)
    {
        if(zf=='+'||zf=='0')
        {
            if(count>10||result>2147483647)
                result=2147483647;

        }
        if(zf=='-')
        {
            if(count>10||result>2147483648)
                result=-2147483648;
            else
                result=0-result;

        }
    }
    return (int)result;
}

int main()
{


}
