#include<bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr){
    int n = arr.size(); // Get the size of the input array
    int low = 0, high = n - 1, ans = INT_MAX, index = -1; // Initialize variables for binary search and result

    // Binary search loop
    while (low <= high) {
        int mid = (low + high) / 2; // Calculate the middle index

        // Check if the current segment is sorted
        if (arr[low] <= arr[high]) {
            // Update index and ans if the current element is smaller
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break; // Break out of the loop since the array is sorted
        }

        // If the left half (low to mid) is sorted
        if (arr[low] <= arr[mid]) {
            // Update index and ans if the current element is smaller
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            low = mid + 1; // Update the low pointer to search in the right half
        } else { // If the left half is not sorted
            high = mid - 1; // Update the high pointer to search in the left half
            // Update index and ans if the current element is smaller
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }
        }
    }

    return index; // Return the index of the minimum element found
}
int main() {
    vector<int> arr = {4,5,6,7,0,1,2};
    cout<<"Array is rotated "<<findKRotation(arr)<<" times"<<endl;
    return 0;
}