#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int> &nums) {
    int n = nums.size(); // Get the size of the input vector
    int low = 0, high = n - 1, ans = INT_MAX; // Initialize variables for binary search and minimum answer

    // Binary search loop
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate the middle index

        // Check if the current segment is sorted and contains duplicates
        if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low++; // Move low pointer to skip duplicates
            high--; // Move high pointer to skip duplicates
            continue; // Skip to the next iteration
        }

        // If the left half (low to mid) is sorted
        if (nums[low] <= nums[mid]) {
            ans = min(ans, nums[low]); // Update answer with the minimum between ans and nums[low]
            low = mid + 1; // Update the low pointer to search in the right half
        } else { // If the left half is not sorted
            ans = min(ans, nums[mid]); // Update answer with the minimum between ans and nums[mid]
            high = mid - 1; // Update the high pointer to search in the left half
        }
    }

    return ans; // Return the minimum element found
}
int main() {
    vector<int> arr = {2,2,2,0,1};
    cout<<"Minimum value in the array is : "<<findMin(arr)<<endl;
    return 0;
}