#include<iostream>
#include<stack>
using namespace std;

class Queue {
private:
    stack<int> pushStack,popStack;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(popStack.empty())
        {
            pushStack.push(x);
        }
        else
        {

            while(!popStack.empty())
            {
                pushStack.push(popStack.top());
                popStack.pop();
            }
            pushStack.push(x);
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if(popStack.empty())
        {
            int len=pushStack.size()-1;
            for(int i=0;i<len;i++)
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }
            pushStack.pop();
        }
        else
            popStack.pop();
    }

    // Get the front element.
    int peek(void) {
        if(popStack.empty())
        {
            while(!pushStack.empty())
            {
                popStack.push(pushStack.top());
                pushStack.pop();
            }

        }
        return popStack.top();

    }

    // Return whether the queue is empty.
    bool empty(void) {
        return (pushStack.empty()&&popStack.empty());
    }
};

int main()
{
    Queue qu;
    qu.push(1);
    qu.push(2);
        cout<<qu.peek()<<endl;
    qu.push(3);
        cout<<qu.peek()<<endl;
    qu.push(5);
    qu.push(6);
    qu.push(7);
    //cout<<qu.empty()<<endl;
    cout<<qu.peek()<<endl;
}
