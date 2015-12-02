#include<iostream>
#include<string>
using namespace std;

int myAtoi(string str)
{
    int len=str.length();
    long result=0;
    for(int i=0;i<len;i++)
    {
            result=result*10+str[i]-'0';
    }
    return result;
}

int compareVersion(string version1, string version2) {
    string str1,str2;
    version1=version1+'.';
    version2=version2+'.';
    int len1=version1.size(),len2=version2.size();
    int index1=0,index2=0;
    while(index1<len1&&index2<len2)
    {
        if(version1[index1]!='.')
        {
            str1=str1+version1[index1];
            index1++;
        }
        if(version2[index2]!='.')
        {
            str2=str2+version2[index2];
            index2++;
        }
        if(version2[index2]=='.'&&version1[index1]=='.')
        {
            if(myAtoi(str1)>myAtoi(str2))
                return 1;
            else if(myAtoi(str1)<myAtoi(str2))
                    return -1;
            else
            {
                str1="";
                index1++;
                str2="";
                index2++;
            }
        }

    }
    if(len1==index1&&len2==index2)
        return 0;
    else if(len1==index1)
    {
        for(;index2<len2;index2++)
            if(version2[index2]<='9'&&version2[index2]>'0')
                return -1;
        return 0;
    }

    else
    {
        for(;index1<len1;index1++)
            if(version1[index1]<='9'&&version1[index1]>'0')
                return 1;
        return 0;
    }

}

int main()
{
    cout<<compareVersion("15","15.0");
}
