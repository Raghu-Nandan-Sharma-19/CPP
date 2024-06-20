#include<bits/stdc++.h>
using namespace std;
// // Brute force approach
// int characterReplacement(string s, int k) {
//     int maxLen = 0;
//     for(int i = 0; i < s.size(); i++) {
//         vector<int> hash(26, 0);
//         int maxFreq = 0;
//         for(int j = i; j < s.size(); j++) {
//             hash[s[j] - 'A']++;
//             maxFreq = max(maxFreq, hash[s[i]]);
//             int changes = (j - i + 1) - 1;
//             if(changes <= k) maxLen = max(maxLen, j - i + 1);
//             else break;
//         }
//     }
//     return maxLen;
// }
// Optimal approach --> O(N)
int characterReplacement(string s, int k) {
    int n = s.size(), l = 0, r = 0, maxFreq = 0, maxLen = 0;
    vector<int> hash(26, 0);
    while(r < n) {
        hash[s[r] - 'A']++;
        if(hash[s[r] - 'A'] > maxFreq) maxFreq = hash[s[r] - 'A'];
        if((r - l + 1) - maxFreq > k) {
            hash[s[l] - 'A']--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}
int main() {
    string s = "AAABBCCD";
    int k = 2;
    cout << characterReplacement(s, k) << endl;
    return 0;
}