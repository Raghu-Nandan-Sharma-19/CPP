#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    // Get the size of the vector
    int n = nums.size();
    // Initialize the low and high pointers for binary search
    int low = 0, high = n - 1;
    // Binary search loop
    while (low <= high) { 
        // Calculate the mid index
        int mid = (low + high) / 2;
        // If the target is found at the mid index, return the index
        if (nums[mid] == target) 
            return mid;
        // Check if the left half is sorted
        if (nums[low] <= nums[mid]) {
            // If the target is within the left sorted range, update high
            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            } else {
                // If not, update low
                low = mid + 1;
            }
        }
        // If the right half is sorted
        else {
            // If the target is within the right sorted range, update low
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1;
            } else {
                // If not, update high
                high = mid - 1;
            }
        }
    }
    // If the target is not found, return -1
    return -1;
}

int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Please enter unique elements"<<endl;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int target;
    cout<<"Enter the target element : "<<endl;
    cin>>target;
    int index = search(arr, target);
    if(index == -1) {
        cout<<"Element not found"<<endl;
    } else {
        cout<<"Element found at index "<<index<<endl;
    }
    return 0;
}