#include<bits/stdc++.h>
using namespace std;
int maxDepth(string s) {
    int ans = 0, p = 0; // initialize the answer and the depth
    for(char c:s) { // iterate through the string
        p += (c == '(') - (c == ')'); // increment the depth if '(' is encountered and decrement if ')' is encountered
        ans = max(ans, p); // update the answer
    }
    return ans; // return the answer
}
int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<"Maximum nesting depth of the string is : "<<maxDepth(s)<<endl;
    return 0;
}