#include <bits/stdc++.h>
using namespace std;
class Stack {
private:
    queue<int> q;

public:
    void push(int value) {
        // Move all elements to temporary queue
        queue<int> temp;
        while (!q.empty()) {
            temp.push(q.front());
            q.pop();
        }

        // Add new element to the front of the queue
        q.push(value);

        // Move back all elements from temporary queue
        while (!temp.empty()) {
            q.push(temp.front());
            temp.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        // Remove the top element from the queue
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << std::endl;
            return -1;
        }

        // Return the top element from the queue
        return q.front();
    }

    bool empty() {
        // Check if the queue is empty
        return q.empty();
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << "Top element: " << stack.top() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element: " << stack.top() << endl;

    stack.pop();

    if (stack.empty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty!" << endl;
    }

    return 0;
}
