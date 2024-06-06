#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

string postfixToPrefix(string postfix) {
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isOperator(postfix[i])) {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();
            string prefix = postfix[i] + operand2 + operand1;
            s.push(prefix);
        } else {
            s.push(string(1, postfix[i]));
        }
    }
    return s.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression: ";
    cin >> postfix;
    string prefix = postfixToPrefix(postfix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
