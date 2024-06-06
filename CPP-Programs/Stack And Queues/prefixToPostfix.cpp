#include<bits/stdc++.h>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToPostfix(string prefix) {
    stack<string> s;
    int length = prefix.size();

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string temp = op1 + op2 + prefix[i];
            s.push(temp);
        }
        else {
            s.push(string(1, prefix[i]));
        }
    }

    return s.top();
}

int main() {
    string prefix;
    cout << "Enter the prefix expression: ";
    cin >> prefix;

    string postfix = prefixToPostfix(prefix);
    cout << "Postfix expression: " << postfix << endl;

    return 0;
}
