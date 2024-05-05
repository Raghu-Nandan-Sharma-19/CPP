#include<bits/stdc++.h>
using namespace std;
string longestPalindrome(string s) {
    // if the length of the string is less than or equal to 1, return the string
    if (s.length() <= 1) {
        return s; 
    }
    // function to expand from center
    auto expand_from_center = [&](int left, int right) {
        // while the left and right are within the bounds and the characters at left and right are equal
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            // decrement the left and increment the right
            left--;
            right++;
        }
        // return the substring from left+1 to right-1
        return s.substr(left + 1, right - left - 1);
    };
    // initialize the max_str as the first character of the string
    string max_str = s.substr(0, 1);
    // iterate through the string
    for (int i = 0; i < s.length() - 1; i++) {
        // expand from center with i as the center
        string odd = expand_from_center(i, i);
        // expand from center with i and i+1 as the center
        string even = expand_from_center(i, i + 1);
        // if the length of odd is greater than the length of max_str
        if (odd.length() > max_str.length()) {
            max_str = odd;
        }
        // if the length of even is greater than the length of max_str
        if (even.length() > max_str.length()) {
            max_str = even;
        }
    }
    // return the max_str
    return max_str;
}
int main() {
    string s = "babad";
    cout<<"Longest palindromic substring is : "<<longestPalindrome(s)<<endl;
    return 0;
}