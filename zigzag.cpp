#include<iostream>
using namespace std;
string convert(string s, int numRows)
    {
        int len=s.length();
        char* result=new char[len+1];
        int index=0;
        result[len]=0;
        if(numRows==1)
        {
            return s;
        }
        for(int i=1;i<=numRows;i++){

            for(int j=i-1;j<len;j=j+numRows*2-2)
            {
                if(i==1||i==numRows)
                {
                    result[index]=s[j];
                    index++;
                }
                else
                    {
                        result[index]=s[j];
                        index++;
                        int tmpIndex=j+numRows*2-2*i;
                        if(tmpIndex<len)
                        {
                            result[index]=s[tmpIndex];
                            index++;

                        }
                    }

            }
        }
        return result;
}
int main()
{


}
