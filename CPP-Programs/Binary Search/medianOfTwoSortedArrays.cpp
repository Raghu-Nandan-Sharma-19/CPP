#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Get the sizes of the input arrays
    int n1 = nums1.size(), n2 = nums2.size();
    // Calculate the total number of elements in the combined array
    int n = n1 + n2;
    // Ensure nums1 is the smaller array for simplicity, otherwise swap
    if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

    // Initialize variables for binary search
    int low = 0, high = n1;
    // Calculate the number of elements needed in the left half for median calculation
    int left = (n1 + n2 + 1) / 2;

    // Binary search to find the partition point
    while(low <= high) {
        // Calculate mid point for nums1 array
        int mid1 = (low + high) / 2;
        // Calculate mid point for nums2 array
        int mid2 = left - mid1;

        // Initialize variables to hold values for partitioning
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        // Assign values if mid points are within array bounds
        if(mid1 < n1) r1 = nums1[mid1];
        if(mid2 < n2) r2 = nums2[mid2];
        if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        // Check if partition is correct
        if(l1 <= r2 && l2 <= r1) {
            // If total number of elements is odd, return the maximum of left halves
            if(n % 2 == 1) return max(l1, l2);
            // If total number of elements is even, return the average of max left and min right
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        } else if(l1 > r2) {
            // Adjust the partition to the left
            high = mid1 - 1;
        } else {
            // Adjust the partition to the right
            low = mid1 + 1;
        }
    }
    // Default return value
    return 0;
}
int main() {
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1) << findMedianSortedArrays(a, b) << '\n';
    return 0;
}