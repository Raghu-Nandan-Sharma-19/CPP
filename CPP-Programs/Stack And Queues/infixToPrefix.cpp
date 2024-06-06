#include <bits/stdc++.h>

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int getPrecedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPrefix(const string& infix) {
    string prefix;
    stack<char> stack;

    // Reverse the infix expression
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (char c : reversedInfix) {
        if (isalpha(c) || isdigit(c)) {
            prefix += c;
        } else if (c == ')') {
            stack.push(c);
        } else if (c == '(') {
            while (!stack.empty() && stack.top() != ')') {
                prefix += stack.top();
                stack.pop();
            }
            stack.pop(); // Discard the ')'
        } else if (isOperator(c)) {
            while (!stack.empty() && getPrecedence(stack.top()) > getPrecedence(c)) {
                prefix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    // Reverse the prefix expression to get the final result
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infixExpression;
    cout << "Enter the infix expression: ";
    getline(cin, infixExpression);

    string prefixExpression = infixToPrefix(infixExpression);
    cout << "Prefix expression: " << prefixExpression << endl;

    return 0;
}
