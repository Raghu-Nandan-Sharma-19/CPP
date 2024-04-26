#include<bits/stdc++.h>
using namespace std;
int findMin(vector<int>& nums) {
    int n = nums.size(); // Get the size of the input vector
    int low = 0, high = n-1, ans = INT_MAX; // Initialize variables for binary search and minimum answer

    // Binary search loop
    while(low <= high) {
        int mid = (low+high)/2; // Calculate the middle index

        // Check if the array is already sorted in non-decreasing order between low and high
        if(nums[low] <= nums[high]) {
            ans = min(ans, nums[low]); // Update answer with the minimum between ans and nums[low]
            break; // Break out of the loop since the array is sorted
        }

        // If the array is rotated, check if the left half (low to mid) is sorted
        if(nums[low] <= nums[mid]) {
            ans = min(ans, nums[low]); // Update answer with the minimum between ans and nums[low]
            low = mid+1; // Update the low pointer to search in the right half
        } else { // If the left half is not sorted
            high = mid-1; // Update the high pointer to search in the left half
            ans = min(ans, nums[mid]); // Update answer with the minimum between ans and nums[mid]
        }
    }

    return ans; // Return the minimum element found
}
int main() {
    vector<int> arr = {4,5,6,7,0,1,2}; // Initialize the input vector
    cout<<"The minimum element in the rotated sorted array is : "<<findMin(arr)<<endl; // Function call to find the minimum element
    return 0;
}