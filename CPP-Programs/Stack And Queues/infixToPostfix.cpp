#include<bits/stdc++.h>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> stack;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Discard the opening parenthesis
        } else if (isOperator(c)) {
            while (!stack.empty() && getPrecedence(stack.top()) >= getPrecedence(c)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(c);
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << std::endl;

    return 0;
}
