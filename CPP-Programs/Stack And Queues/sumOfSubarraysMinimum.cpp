#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
int sumSubarrayMins(vector<int>& nums) {
    int length = nums.size();
    vector<int> left(length, -1);
    vector<int> right(length, length);
    stack<int> stk;

    for (int i = 0; i < length; ++i) {
        while (!stk.empty() && nums[stk.top()] >= nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            left[i] = stk.top();
        }
        stk.push(i);
    }

    stk = stack<int>();

    for (int i = length - 1; i >= 0; --i) {
        while (!stk.empty() && nums[stk.top()] > nums[i]) {
            stk.pop();
        }
        if (!stk.empty()) {
            right[i] = stk.top();
        }
        stk.push(i);
    }

    ll sum = 0;

    for (int i = 0; i < length; ++i) {
        sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
        sum %= MOD;
    }

    return sum;
}
int main() {
    int n = 5;
    vector<int> arr = {3, 4, 2, 7, 5};
    cout << sumSubarrayMins(arr);
    return 0;
}