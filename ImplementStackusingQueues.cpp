#include<iostream>
#include<deque>
using namespace std;

class Stack {
private:
    deque<int> stackOfDeque;
public:
    void push(int x) {
        stackOfDeque.push_back(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        stackOfDeque.pop_back();
    }

    // Get the top element.
    int top() {
        return stackOfDeque.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return stackOfDeque.empty();
    }
};

int main()
{
    Stack st;
    st.push(3);
    st.push(5);
    cout<<st.top()<<" ";
    st.pop();
    cout<<st.top()<<" ";
    cout<<st.empty()<<" ";
}
