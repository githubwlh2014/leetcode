#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    if(height.size()<2)
        return 0;
    int len=height.size()-1;
    int start=0;
    int maxArea=0;
    int minHigh=0;
    int tmp;

    while(start<len)
    {
        minHigh=height[start]>height[len]?height[len]:height[start];
        maxArea=maxArea>(tmp=minHigh*(len-start))?maxArea:tmp;

        while(height[len]<=minHigh&&--len>start)
             ;
        while(height[start]<=minHigh&&++start<len)
             ;
    }
    return maxArea;
}

int main()
{
    vector<int> tmp={1,1};
    cout<<maxArea(tmp)<<endl;
}
