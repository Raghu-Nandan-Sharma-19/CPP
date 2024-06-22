#include<bits/stdc++.h>
using namespace std;
int count(vector<int> &nums, int k) {
    int l = 0, r = 0, sum = 0, cnt = 0;
    while(r < nums.size()) {
        sum += (nums[r] % 2);
        while(sum > k && l <= r) {
            sum -= (nums[l] % 2);
            l++;
        }
        if(sum <= k) cnt += (r - l + 1);
        r++;
    }
    return cnt;
}
int numberOfSubarrays(vector<int> &nums, int k) {
    return count(nums, k) - count(nums, k - 1);
}
int main() {
    vector<int> arr = {1, 1, 2, 1, 1};
    int k = 3;
    cout<<numberOfSubarrays(arr, k)<<endl;
    return 0;
}