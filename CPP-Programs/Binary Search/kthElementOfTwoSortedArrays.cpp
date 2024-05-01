#include<bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k) {
    // If the size of array 'a' is greater than the size of array 'b',
    // call the function with arguments swapped to ensure that 'a' is the smaller array.
    if (n1 > n2) return kthElement(b, a, n2, n1, k);
    
    // Total number of elements in both arrays
    int n = n1 + n2; 
    
    // Initialize the left boundary of the search space as k
    int left = k; 
    
    // Calculate the boundaries for binary search
    int low = max(k - n2, 0), high = min(k, n1);
    
    // Binary search loop
    while (low <= high) {
        // Calculate the middle indices
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        
        // Initialize variables to store elements to the left and right of the midpoints
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        
        // Update variables with actual values if indices are within bounds
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
        
        // Check if the current partition is correct
        if (l1 <= r2 && l2 <= r1) {
            // Return the maximum of the two elements to the left of the partition
            return max(l1, l2);
        }
        // Update the boundaries based on the current partition
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    // Dummy return statement, this should never be reached
    return 0; 
}
int main() {
    vector<int> arr1 = {2,3,6,7,9};
    vector<int> arr2 = {1,4,8,10};
    int m = arr1.size();
    int n = arr2.size();
    int k = 5;
    cout<<"The element at the kth position in the final sorted array is "<<kthElement(arr1,arr2,m,n,k);
    return 0;
}