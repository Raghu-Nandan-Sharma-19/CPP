#include<bits/stdc++.h>
using namespace std;
bool isIsomorphic(string s, string t) {
    vector<int> indexS(200, 0); // Stores index of characters in string s
    vector<int> indexT(200, 0); // Stores index of characters in string t
    int len = s.length(); // Get the length of both strings
    if(len != t.length()) { // If the lengths of the two strings are different, they can't be isomorphic
        return false;
    }    
    for(int i = 0; i < len; i++) { // Iterate through each character of the strings
    // Check if the index of the current character in string s is different from 
    // the index of the corresponding character in string t
        if(indexS[s[i]] != indexT[t[i]]) { 
            return false; // If different, strings are not isomorphic
        }    
        indexS[s[i]] = i + 1; // updating position of current character
        indexT[t[i]] = i + 1;
    }
    return true; // If the loop completes without returning false, strings are isomorphic
}
int main() {
    string s, t;
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;
    if(isIsomorphic(s, t)) {
        cout << "The strings are isomorphic." << endl;
    } else {
        cout << "The strings are not isomorphic." << endl;
    }
    return 0;
}