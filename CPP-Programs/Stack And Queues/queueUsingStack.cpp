#include <bits/stdc++.h>
using namespace std;

class Queue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void enqueue(int value) {
        stack1.push(value);
    }

    int dequeue() {
        if (stack1.empty() && stack2.empty()) {
            cout << "Queue is empty!" << std::endl;
            return -1;
        }

        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        int front = stack2.top();
        stack2.pop();
        return front;
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << queue.dequeue() << endl; // Output: 10
    cout << queue.dequeue() << endl; // Output: 20

    queue.enqueue(40);

    cout << queue.dequeue() << endl; // Output: 30
    cout << queue.dequeue() << endl; // Output: 40

    cout << boolalpha << queue.isEmpty() << endl; // Output: true

    return 0;
}