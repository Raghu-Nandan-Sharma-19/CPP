#include <bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

string postfixToInfix(string postfix) {
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++) {
        if (isOperator(postfix[i])) {
            string operand2 = s.top();
            s.pop();
            string operand1 = s.top();
            s.pop();
            string expression = "(" + operand1 + postfix[i] + operand2 + ")";
            s.push(expression);
        } else {
            s.push(string(1, postfix[i]));
        }
    }
    return s.top();
}

int main() {
    string postfix = "ab+c*";
    string infix = postfixToInfix(postfix);
    cout << "Infix expression: " << infix << endl;
    return 0;
}
