#include<bits/stdc++.h>
using namespace std;
// // brute force approach --> O(n^3)
// int subarraysWithXorK(vector<int> &nums, int k) {
//     int cnt = 0, n = nums.size(); // initialize the variables
//     for(int i=0; i<n; i++) { // loop through the array
//         for(int j=i; j<n; j++) { // loop through the array
//             int xorr = 0; // initialize the xorr
//             for(int k=i; k<=j; k++) { // loop through the array
//                 xorr = xorr^nums[k]; // xor the elements
//             }
//             if(xorr == k) cnt++; // if the xor is equal to k, increment the count
//         }
//     }
//     return cnt; // return the count
// }
// // better solution --> O(n^2)
// int subarraysWithXorK(vector<int> &nums, int k) {
//     int cnt = 0, n = nums.size();
//     for(int i=0; i<n; i++) {
//         int xorr = 0;
//         for(int j=i; j<n; j++) {
//             xorr = xorr^nums[j];
//             if(xorr == k) cnt++;
//         } 
//     }
//     return cnt;
// }
// optimal solution --> O(n)
int subarraysWithXorK(vector<int> &nums, int k) {
    int cnt = 0, n = nums.size(), xorr = 0; // initialize the variables
    map<int, int> mpp; // map to store the xor and the count
    mpp[xorr]++; // store the xor and the count
    for(int i=0; i<n; i++) { // loop through the array
        xorr = xorr^nums[i]; // xor the elements
        int x = xorr^k; // xor the elements
        cnt += mpp[x]; // increment the count
        mpp[xorr]++; // store the xor and the count
    }
    return cnt; // return the count
}
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int k;
    cout<<"Enter k : "<<endl;
    cin>>k;
    cout<<"The number of subarrays with xor "<<k<<" are : "<<subarraysWithXorK(arr, k)<<endl;
    return 0;
}