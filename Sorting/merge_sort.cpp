#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    void mergeSortHelper(vector<int> &nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int mid = low + (high - low) / 2;
        mergeSortHelper(nums, 0, mid);
        mergeSortHelper(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
public:
    vector<int> mergeSort(vector<int> &nums) {
        mergeSortHelper(nums, 0, nums.size() - 1);
        return nums;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    Solution sol;
    for (auto num : sol.mergeSort(nums)) {
        cout << num << " ";
    }
    cout << "\n";

    return 0;
}