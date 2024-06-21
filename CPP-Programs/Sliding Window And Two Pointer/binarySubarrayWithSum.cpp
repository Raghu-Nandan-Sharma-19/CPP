#include<bits/stdc++.h>
using namespace std;
int count(vector<int>& nums, int goal) {
    int l = 0, r = 0, sum = 0, cnt = 0;
    while (r < nums.size()) {
        sum += nums[r];
        while (sum > goal && l <= r) {
            sum -= nums[l];
            l++;
        }
        if (sum <= goal) cnt += r - l + 1;
        r++;
    }
    return cnt;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    return count(nums, goal) - count(nums, goal - 1);
}
int main() {
    vector<int> arr = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << numSubarraysWithSum(arr, goal) << endl;
    return 0;
}