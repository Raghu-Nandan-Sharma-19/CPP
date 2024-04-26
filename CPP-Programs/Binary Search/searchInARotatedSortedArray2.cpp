#include<bits/stdc++.h>
using namespace std;
bool search(vector<int>& nums, int target) {
    int n = nums.size(); // Get the size of the input array
    int low = 0, high = n-1; // Initialize low and high indices for binary search

    // Perform binary search
    while(low <= high) {
        int mid = (low + high) / 2; // Calculate the middle index
        if(nums[mid] == target) { // If the target is found at the middle index, return true
            return true;
        }
        // If elements at low, mid, and high indices are equal,
        // move low and high pointers towards the center until they're different
        if(nums[low] == nums[mid] && nums[mid] == nums[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        // If the left half is sorted
        if(nums[low] <= nums[mid]) {
            // Check if the target lies in the left half
            if(nums[low] <= target && target <= nums[mid]) {
                high = mid - 1; // Update high to search in the left half
            } else {
                low = mid + 1; // Update low to search in the right half
            }
        }
        // If the right half is sorted
        else {
            // Check if the target lies in the right half
            if(nums[mid] <= target && target <= nums[high]) {
                low = mid + 1; // Update low to search in the right half
            } else {
                high = mid - 1; // Update high to search in the left half
            }
        }
    }
    // If the target is not found in the array, return false
    return false;
}
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cout<<"Enter the target element : "<<endl;
    cin>>target;
    if(search(arr, target)) {
        cout<<"Element found"<<endl;
    } else {
        cout<<"Element not found"<<endl;
    }
    return 0;
}