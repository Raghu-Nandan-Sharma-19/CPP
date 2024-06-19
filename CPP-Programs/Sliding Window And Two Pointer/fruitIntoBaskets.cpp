#include<bits/stdc++.h>
using namespace std;
// // Brute force --> O(N x N)
// int totalFruits(vector<int> &fruits) {
//     int maxLen = 0;
//     for(int i = 0; i < fruits.size(); i++) {
//         set<int> st;
//         for(int j = i; j < fruits.size(); j++) {
//             st.insert(fruits[j]);
//             if(st.size() <= 2) maxLen = max(maxLen, j - i + 1);
//             else break;
//         }
//     }
//     return maxLen;
// }
// // Optimal Solution --> O(N)
int totalFruits(vector<int> &fruits) {
    int l = 0, r = 0;
    int maxLen = INT_MIN;
    map<int, int> mpp;

    while(r < fruits.size()) {
        mpp[fruits[r]]++;
            
        if(mpp.size() > 2) {
            mpp[fruits[l]]--;    
            if(mpp[fruits[l]] == 0) {
                mpp.erase(fruits[l]);
            }
            l++;
        }
        if(mpp.size() <= 2) {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}
int main() {
    vector<int> arr = {2, 1, 2};
    cout<<totalFruits(arr)<<endl;
    return 0;
}