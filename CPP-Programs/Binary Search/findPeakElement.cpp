#include<bits/stdc++.h>
using namespace std;
// // brute force solution --> O(N)
// // Function to find a peak element in a given vector of integers
// int findPeakElement(vector<int> &nums) {
//     // Get the size of the vector
//     int n = nums.size();
//     // Iterate through each element in the vector
//     for(int i = 0; i < n; i++) {
//         // Check if the current element is greater than its previous element (if it exists)
//         // and also greater than its next element (if it exists)
//         if((i == 0 || nums[i - 1] < nums[i]) && (i == n - 1 || nums[i] > nums[i + 1])) {
//             // If the conditions are met, it means the current element is a peak element,
//             // so return its index
//             return i;
//         }
//     }
//     // If no peak element is found, return -1
//     return -1;
// }
// Optimal approach --> O(log2N)
int findPeakElement(vector<int> &nums) {
    int n = nums.size(); // Get the size of the input array.
    // If there's only one element, it's a peak.
    if(n == 1) return 0;
    // If the first element is greater than the second, it's a peak.
    if(nums[0] > nums[1]) return 0;
    // If the last element is greater than the second-to-last, it's a peak.
    if(nums[n-1] > nums[n-2]) return n-1;
    // Binary search for a peak element.
    int low = 1, high = n-2; // Set the search range, excluding the first and last elements.
    while(low <= high) { // Continue until the search range is valid.
        int mid = (low+high)/2; // Calculate the middle index.
        // If the middle element is greater than its neighbors, it's a peak.
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) {
            return mid;
        } 
        // If the element to the left is greater, move the search range to the right.
        else if(nums[mid] > nums[mid-1]) {
            low = mid+1;
        } 
        // If the element to the right is greater, move the search range to the left.
        else {
            high = mid-1;
        }
    }
    // If no peak is found, return -1.
    return -1;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    cout<<"The peak element is present at index : "<<findPeakElement(arr)<<endl;
    return 0;
}