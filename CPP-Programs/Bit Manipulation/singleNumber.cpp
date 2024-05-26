#include<bits/stdc++.h>
using namespace std;
// // brute force solution
// int singleNumber(vector<int> &arr) {
//     map<int, int> mpp;
//     for(int i=0; i<arr.size(); i++) {
//         mpp[arr[i]]++;
//     }
//     for(auto it:mpp) {
//         if(it.second == 1) {
//             return it.first;
//         }
//     }
//     return -1;
// }
// Optimal solution below
int singleNumber(vector<int> &nums) {
    // Initialize a variable to hold the XOR result. Start with 0 since XOR with 0 does not change the number.
    int xorr = 0;
    // Loop through each element in the vector 'nums'.
    for(int i = 0; i < nums.size(); i++) {
        // XOR the current element with 'xorr'.
        // XORing a number with itself results in 0, and XORing with 0 results in the number itself.
        // This means that pairs of the same number will cancel out to 0, leaving the single number.
        xorr = xorr ^ nums[i];
    }
    // Return the result, which will be the single number that does not have a duplicate.
    return xorr;
}
int main() {
    vector<int> arr = {4, 1, 2, 1, 2};
    cout<<"The array is : "<<endl;
    for(auto it:arr) {
        cout<<it<<" ";
    } cout<<endl;
    cout<<"The number that appears once in array is : "<<singleNumber(arr)<<endl;
    return 0;
}