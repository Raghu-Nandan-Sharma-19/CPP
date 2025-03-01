#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to merge two sorted halves of the array
    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        // Merge the two halves into temp array
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                right++;
            }
        }

        // Copy remaining elements from the left half
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }

        // Copy remaining elements from the right half
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }

        // Copy the merged elements back into the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    // Function to count reverse pairs in the array
    int countPairs(vector<int> &nums, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;

        // Count the number of reverse pairs
        for (int i = low; i <= mid; i++) {
            while (right <= high && nums[i] > (long long)(2LL * nums[right])) {
                right++;
            }
            cnt += (right - (mid + 1));
        }

        return cnt;
    }

    // Function to perform merge sort and count reverse pairs
    int mergeSort(vector<int> &nums, int low, int high) {
        int cnt = 0;
        if (low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
        return cnt;
    }

public:
    // Function to return the number of reverse pairs in the array
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    Solution sol;
    cout << sol.reversePairs(nums) << "\n";

    return 0;
}