#include<bits/stdc++.h>
using namespace std;
bool rotateString(string s, string goal) {
    // If the length of the first string is less than the length of the second string, return false
    int n = s.length();
    if(s.length() < goal.length()){
        return false;
    }
    // Concatenate the first string with itself
    string doublestr = s+s;
    // Check if the second string is a substring of the concatenated string
    for(int i=0; i<n; i++){
        string str = doublestr.substr(i, n);
        // If the second string is a substring of the concatenated string, return true
        if(str == goal) {
            return true;
        }
    }
    // If the second string is not a substring of the concatenated string, return false
    return false;
}
int main() {
    string s, goal;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> goal;
    if(rotateString(s, goal)) {
        cout << "The strings are rotation of each other." << endl;
    } else {
        cout << "The strings are not rotation of each other." << endl;
    }
    return 0;
}