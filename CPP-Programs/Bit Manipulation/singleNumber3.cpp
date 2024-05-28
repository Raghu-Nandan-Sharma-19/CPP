#include<bits/stdc++.h>
using namespace std;

// // brute force approach
// vector<int> singleNumber(vector<int> &nums) {
//     // create a map to store numbers with frequency
//     map<int, int> mpp;

//     // iterate through array and add the numbers with their frequency in the map
//     for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;

//     // initialize a vector array to store multiple numbers in array which appears once
//     vector<int> ans;

//     // Iterate through the map
//     for(auto it : mpp) {
//         // If the frequency of the number is one add it to the array
//         if(it.second == 1) ans.push_back(it.first);
//     }

//     // return the answer array
//     return ans;
// }

// Optimal approach below 
vector<int> singleNumber(vector<int>& nums) {
    long int XORR = 0;

    // Compute the XOR of all elements in the array.
    // This will effectively cancel out all numbers that appear twice,
    // leaving the XOR result of the two unique numbers.
    for(int i = 0; i < nums.size(); i++) 
        XORR = XORR ^ nums[i];

    // Find the rightmost set bit in the XOR result.
    // This bit is set in one of the unique numbers but not the other.
    int rightmost = XORR & -XORR;

    int b1 = 0, b2 = 0;

    // Partition the numbers into two groups based on the rightmost set bit.
    // XORing all numbers in each group will result in the two unique numbers.
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] & rightmost) b1 = b1 ^ nums[i];  // XOR for the first group
        else b2 = b2 ^ nums[i];  // XOR for the second group
    }

    // Return the two unique numbers.
    return {b1, b2};
}
int main() {
    vector<int> arr = {2, 4, 2, 6, 3, 7, 7, 3};
    cout<<"The array is : "<<endl;
    for(auto it : arr) {
        cout<<it<<" ";
    } cout<<endl;
    cout<<"The numbers which appears once in array are : "<<endl;
    vector<int> ans = singleNumber(arr);
    for(auto it : ans) {
        cout<<it<<" ";
    } cout<<endl;
    return 0;
}