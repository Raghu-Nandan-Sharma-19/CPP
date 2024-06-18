#include<bits/stdc++.h>
using namespace std;
// // Brute force solution --> O(N^2)
// int longestOnes(vector<int> &nums, int k) {
//     int maxLen = 0;
//     // Iterate through the loop
//     for(int i = 0; i < nums.size(); i++) {
//         int zeroes = 0;
//         // iterate through the loop
//         for(int j = i; j < nums.size(); j++) {
//             // if element at jth index is zero increase the value of zeroes with 1
//             if(nums[j] == 0) zeroes++;
//             // if zeroes is less than or equal to k
//             if(zeroes <= k) {
//                 // find the length of subarray
//                 int len = j - i + 1;
//                 // get the maximum of max len and len and store it in max len
//                 maxLen = max(maxLen, len);
//             } else break; // else break from the loop
//         }
//     }
//     // return length of the subarray
//     return maxLen;
// }
// // Optimal approach --> o(N)
int longestOnes(vector<int> &nums, int k) {
    int left = 0, right = 0, zeroes = 0, maxLen = 0; // Initialize pointers and counters

    while(right < nums.size()) { // Iterate through the array using the right pointer
        if(nums[right] == 0) zeroes++; // Increment zeroes count if the current element is 0

        if(zeroes > k) { // If the number of zeroes exceeds k
            if(nums[left] == 0) zeroes--; // Decrement zeroes count if the left pointer points to a 0
            left++; // Move the left pointer to the right to shrink the window
        }

        if(zeroes <= k) { // If the number of zeroes is within the allowed limit
            int len = right - left + 1; // Calculate the current window length
            maxLen = max(maxLen, len); // Update maxLen if the current window is larger
        }

        right++; // Move the right pointer to the right to expand the window
    }

    return maxLen; // Return the maximum length of the subarray found
}
int main() {
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    cout<<"Longest subarray with max consecutive ones is : "<<longestOnes(arr, k)<<endl;
    return 0;
}