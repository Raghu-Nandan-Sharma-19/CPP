#include<bits/stdc++.h>
using namespace std;
// // brute force approach --> O(N^2)
// int lengthOfLongestSubstring(string s) {
//     // initialize the max length of substring
//     int maxLen = 0;

//     // Iterate through the string
//     for(int i = 0; i < s.length(); i++) {
//         // declare a vector array of size 256 with all elements as 0
//         vector<int> hash(256, 0);
//         // Iterate through the string
//         for(int j = 0; j < s.length(); j++) {
//             // If the character is present in array break from the loop
//             if(hash[s[j]] == 1) break;
//             // get the length
//             int len = j - i + 1;
//             // store the maximum of len and maxLen in maxLen
//             maxLen = max(len, maxLen);
//             hash[s[j]] = 1;
//         }
//     }
//     // return the length of the longest substring with no repeating characters
//     return maxLen;
// }
// // Optimal approach --> O(N)
int lengthOfLongestSubstring(string s) {
    vector<int> hash(256, -1);
    int l = 0, r = 0, maxLen = 0, n = s.size();
    // Loop till r is less than n
    while(r < n) {
        // if element is present in the map
        if(hash[s[r]] != -1) {
            // if r pointer is grater than l move l to one place ahead of r
            if(hash[s[r]] >= l) l = hash[s[r]] + 1;
        }
        // find length of the substring
        int len = r - l + 1;
        // store maximum of len and max len in max len
        maxLen = max(len, maxLen);
        hash[s[r]] = r;
        // move the r pointer by one place
        r++;
    }
    // return max length
    return maxLen;
}
int main() {
    string s = "abcabcbb";
    cout<<"Length of longest substring with no repeating characters is : "<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}