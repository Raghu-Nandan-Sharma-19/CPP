#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// int subarraysWithKDistinct(vector<int> &nums, int k) {
//     int cnt = 0;
//     for(int i = 0; i < nums.size(); i++) {
//         map<int, int> mpp;
//         for(int j = i; j < nums.size(); j++) {
//             mpp[nums[j]]++;
//             if(mpp.size() == k) cnt = cnt + 1;
//             else if(mpp.size() > k) break;
//         }
//     }
//     return cnt;
// }
// // optimal solution
int count(vector<int> &nums, int k) {
    int l = 0, r = 0, cnt = 0;
    map<int, int> mpp;
    while (r < nums.size()) {
        mpp[nums[r]]++;
        while(mpp.size() > k) {
            mpp[nums[l]]--;
            if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l++;
        }
        cnt = cnt + (r - l + 1);
        r++;
    }
    return cnt;
    
}
int subarraysWithKDistinct(vector<int> &nums, int k) {
    return count(nums, k) - count(nums, k - 1);
}
int main() {
    vector<int> arr = {1, 2, 1, 3, 4};
    int k = 3;
    cout<<subarraysWithKDistinct(arr, k)<<endl;
    return 0;
}