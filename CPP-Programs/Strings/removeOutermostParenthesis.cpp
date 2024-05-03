#include<bits/stdc++.h>
using namespace std;
// Function to remove the outermost parenthesis from a given string
string removeOutermostParenthesis(string s) {
    // Initialize an empty string to store the result
    string res;
    // Initialize a counter to keep track of opened parenthesis
    int opened = 0;
    // Iterate through each character in the input string 's'
    for(auto c : s) {
        // If the current character is an opening parenthesis and it's not the outermost one
        if((c == '(' && opened++ > 0) ||
           // Or if the current character is a closing parenthesis and it's not the outermost one
           (c == ')' && opened-- > 1))
            // Add the character to the result string
            res += c;
    }
    // Return the resultant string without the outermost parenthesis
    return res;
}
int main() {
    string s = "(()())(())";
    cout<<"The result is : ' "<<removeOutermostParenthesis(s)<<" '"<<endl;
    return 0;
}