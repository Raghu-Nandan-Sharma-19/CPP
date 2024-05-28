#include<bits/stdc++.h>
using namespace std;

// // brute force approach
// int singleNumber(vector<int> &nums) {
//     // Initialize a map to store the number and frequency 
//     map<int, int> mpp;

//     // iterate the array 
//     for(int i = 0; i < nums.size(); i++) {
//         // Store the number in the map with its frequency
//         mpp[nums[i]]++;
//     }

//     // iterate through the map
//     for(auto it : mpp) {
//         // check if the frequency is equal to one then return the number
//         if(it.second == 1) return it.first;
//     }

//     // dummy statement this will never execute if we have an element which appears once in the array
//     return -1;
// }

// Optimal Approach below
int singleNumber(vector<int> &nums) {
    int ones = 0, twos = 0; // Initialize variables to keep track of bits appearing once and twice respectively

    // Iterate over all elements in the array
    for(int i = 0; i < nums.size(); i++) {
        // Update 'ones' with the bits that have appeared once so far
        // 'ones ^ nums[i]' adds the current number's bits to 'ones'
        // '& ~twos' ensures that any bit that has also appeared twice is removed from 'ones'
        ones = (ones ^ nums[i]) & ~twos;
        
        // Update 'twos' with the bits that have appeared twice so far
        // 'twos ^ nums[i]' adds the current number's bits to 'twos'
        // '& ~ones' ensures that any bit that has appeared once is removed from 'twos'
        twos = (twos ^ nums[i]) & ~ones;
    }
    
    // 'ones' will contain the bits of the number that appears exactly once in the array
    return ones;
}
int main() {
    vector<int> arr = {5, 5, 5, 2, 4, 4, 4};
    cout<<"The array is : "<<endl;
    for(auto it : arr) {
        cout<<it<<" ";
    } cout<<endl;
    cout<<"The number which appears once in the array is : "<<singleNumber(arr)<<endl;
    return 0;
}