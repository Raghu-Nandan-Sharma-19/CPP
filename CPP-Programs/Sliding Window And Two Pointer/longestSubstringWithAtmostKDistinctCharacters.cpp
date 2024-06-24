#include<bits/stdc++.h>
using namespace std;
// // Brute force approach
// int kDistinctChars(int k, string &str) {
//     int maxLen = 0;
//     map<char, int> mpp;
//     for(int i = 0; i < str.size(); i++) {
//         mpp.clear();
//         for(int j = i; j < str.size(); j++) {
//             mpp[str[j]]++;
//             if(mpp.size() <= k) maxLen = max(maxLen, j - i + 1);
//             else break;
//         }
//     }
//     return maxLen;
// }

// // Optimal approach
int kDistinctChars(int k, string &str) {
    int maxLen = 0, l = 0, r  = 0;
    map<char, int> mpp;
    while(r < str.size()) {
        mpp[str[r]]++;
        if (mpp.size() <= k) {
          maxLen = max(maxLen, r - l + 1);
        }
        else {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0) {
                mpp.erase(str[l]);
            }
            l++;
        }
        
        r++;
    }
    return maxLen;
}
int main() {
    string s = "aaabbccd";
    int k = 2;
    cout<<kDistinctChars(k, s)<<endl;
    return 0;
}