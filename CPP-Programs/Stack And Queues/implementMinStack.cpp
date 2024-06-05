#include<bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;

public:
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};
int main() {
    // Create an instance of MinStack
    MinStack stack;

    // Push elements into the stack
    stack.push(5);
    stack.push(2);
    stack.push(7);
    stack.push(1);

    // Print the top element and minimum element
    cout << "Top element: " << stack.top() << endl;
    cout << "Minimum element: " << stack.getMin() << endl;

    // Pop an element from the stack
    stack.pop();

    // Print the top element and minimum element after popping
    cout << "Top element after pop: " << stack.top() << endl;
    cout << "Minimum element after pop: " << stack.getMin() << endl;

    return 0;
}
