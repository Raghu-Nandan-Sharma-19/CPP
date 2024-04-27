#include<bits/stdc++.h>
using namespace std;
// // brute force approach --> O(N)
// int singleNonDuplicate(vector<int> &nums) {
//     int n = nums.size(); // Get the size of the input vector
//     if(n == 1) return nums[0]; // If there's only one element, return it as it is unique
    
//     // Loop through each element in the vector
//     for(int i=0; i<n; i++) {
//         // Check if the current element is the first element
//         if(i == 0) {
//             // If it is, check if it's different from the next element
//             if(nums[i] != nums[i+1]) return nums[i]; // If it is, return this element as it's unique
//         } 
//         // Check if the current element is the last element
//         else if(i == n-1) {
//             // If it is, check if it's different from the previous element
//             if(nums[i] != nums[i-1]) return nums[i]; // If it is, return this element as it's unique
//         } 
//         // If the current element is neither the first nor the last element
//         else {
//             // Check if it's different from both its previous and next elements
//             if(nums[i] != nums[i+1] && nums[i] != nums[i-1]) return nums[i]; // If it is, return this element as it's unique
//         }
//     }
//     return -1;
// }
// optimised approach --> O(log2n)
int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size(); // Get the size of the input vector
    if(n == 1) return nums[0]; // If there's only one element, return it as it is unique
    
    // If the first element is unique
    if(nums[0] != nums[1]) return nums[0];
    
    // If the last element is unique
    if(nums[n-1] != nums[n-2]) return nums[n-1];
    
    // Binary search
    int low = 1, high = n-2; // Set up the low and high pointers for binary search
    while(low <= high) { // Continue the search until low is less than or equal to high
        int mid = (low+high)/2; // Calculate the middle index
        
        // Check if the current element is the non-duplicate
        if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]) {
            return nums[mid];
        }
        
        // Adjust the low and high pointers based on the property of the array
        if((mid%2 == 1 && nums[mid-1] == nums[mid]) || (mid%2 == 0 && nums[mid] == nums[mid+1])) {
            low = mid+1; // If the non-duplicate is on the right side, move low to the right
        } else {
            high = mid-1; // If the non-duplicate is on the left side, move high to the left
        }
    }
    
    return -1; // This line is unreachable in this code snippet and might be unnecessary
}
int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    cout<<"Single element in array is : "<<singleNonDuplicate(arr)<<endl;
    return 0;
}