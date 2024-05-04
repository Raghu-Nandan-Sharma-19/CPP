#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    if(strs.empty()) return ""; // if the vector is empty, return an empty string
    string pref = strs[0]; // initialize the prefix string with the first string in the vector
    int prefLen = pref.length(); // initialize the prefix length with the length of the first string
    for(int i=1; i<strs.size(); i++) { // iterate through the vector
        string s = strs[i]; // get the current string
        // while the prefix length is greater than the current string length or the prefix is not equal to
        // the substring of the current string
        while(prefLen > s.length() || pref != s.substr(0, prefLen)) { 
            prefLen--; // decrement the prefix length
            if(prefLen == 0) { // if the prefix length is 0, return an empty string
                return ""; 
            }
            pref = pref.substr(0, prefLen); // update the prefix string
        }
    }
    return pref; // return the prefix string
}
int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    cout<<"The longest common prefix is : "<<longestCommonPrefix(strs)<<endl;
    return 0;
}