#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
class MinStack {
private:
    vector<int> min;
    vector<int> stk;

public:
    void push(int x) {
        if(stk.empty())
            min.push_back(x);
        else if(x <= min.back())
            min.push_back(x);
        stk.push_back(x);
    }

    void pop() {
        int a = stk.back();
        if(a == min.back())
            min.pop_back();
        stk.pop_back();
    }

    int top() {
        return stk.back();
    }

    int getMin() {
        return min.back();
    }
};

int main()
{
    MinStack Stack;
    for(int i=0;i<10;i++)
        Stack.push(i);

    cout<<Stack.top()<<endl;
    Stack.pop();
    cout<<Stack.top()<<endl;
    cout<<Stack.getMin()<<endl;

}

