#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {

    int index=digits.size()-1;
    int tmp=0;
    bool tag=true;
    if(index<0)
        return digits;

    for(;index>=0;index--)
    {
        tmp=digits[index]+1;
        if(tag)
        {
            if(tmp>9)
                ;
            else
                tag=false;
            digits[index]=tmp%10;

        }
        else
            break;
    }

    if(tag)
        digits.insert(digits.begin(),1);

    return digits;


}

int main()
{
    vector<int> dig={8};
    vector<int> digits=plusOne(dig);
    for(int i=0;i<digits.size();i++)
        cout<<digits[i];

}
