#include<bits/stdc++.h>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string prefixToInfix(string prefix) {
    stack<string> s;
    int length = prefix.length();

    for (int i = length - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            string operand1 = s.top();
            s.pop();
            string operand2 = s.top();
            s.pop();

            string infix = "(" + operand1 + prefix[i] + operand2 + ")";
            s.push(infix);
        } else {
            s.push(string(1, prefix[i]));
        }
    }

    return s.top();
}

int main() {
    string prefix;
    cout << "Enter the prefix expression: ";
    cin >> prefix;

    string infix = prefixToInfix(prefix);
    cout << "Infix expression: " << infix << endl;

    return 0;
}
