#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// vector<int> missingAndRepeating(vector<int> &nums) {
//     int n = nums.size(); // size of the array
//     int repeating = -1, missing = -1; // initialising repeating and missing elements
//     for(int i=1; i<=n; i++) { // checking for each element from 1 to n
//         int cnt = 0; // count of the element
//         for(int j=0; j<n; j++) { // checking for each element in the array
//             if(nums[j] == i) { // if element is found in the array
//                 cnt++; // increment the count
//             } 
//         }
//         // if count is 2 then element is repeating
//         if(cnt == 2) repeating = i; 
//         // if count is 0 then element is missing
//         else if(cnt == 0) missing = i;
//         // if both repeating and missing elements are found then break the loop
//         if(repeating != -1 && missing != -1) {
//             break;
//         } 
//     }
//     // return the repeating and missing elements
//     return {repeating, missing};
// }
// // better approach using hash array
// vector<int> missingAndRepeating(vector<int> &nums) {
//     int n = nums.size(); // size of the array
//     int hash[n+1] = {0}; // hash array to store the count of each element
//     for(int i=0; i<n; i++) { // storing the count of each element
//         hash[nums[i]]++; 
//     }
//     // initialising repeating and missing elements
//     int repeating = -1, missing = -1;
//     // checking for each element from 1 to n
//     for(int i=1; i<=n; i++) {
//         // if count is 2 then element is repeating
//         if(hash[i] == 2) repeating = i;
//         // if count is 0 then element is missing
//         else if(hash[i] == 0) missing = i;
//         // if both repeating and missing elements are found then break the loop
//         if(repeating != -1 && missing != -1) {
//             break;
//         }
//     }
//     // return the repeating and missing elements
//     return {repeating, missing};
// }
// optimal approach --> O(N)
vector<int> missingAndRepeating(vector<int> &nums) {
    long long n = nums.size(); // size of the array
    long long sN = (n*(n+1))/2; // sum of n natural numbers
    long long s2N = (n*(n+1)*(2*n+1))/6; // sum of squares of n natural numbers
    long long s = 0, s2 = 0; // initialising sum and sum of squares of the array
    for(int i=0; i<n; i++) { // calculating sum and sum of squares of the array
        s += nums[i]; 
        s2 += (long long)nums[i] * (long long)nums[i];
    }
    long long val1 = s-sN; // difference of sum of array and sum of n natural numbers
    long long val2 = s2-s2N; // difference of sum of squares of array and sum of squares of n natural numbers
    val2 = val2/val1; // difference of repeating and missing elements
    long long x = (val1+val2)/2; // repeating element
    long long y = x-val1; // missing element
    return {(int)x, (int)y}; // return the repeating and missing elements
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
    vector<int> ans = missingAndRepeating(arr);
    cout<<"The repeating element in array is : "<<ans[0]<<" and missing element in array is : "<<ans[1]<<endl;
    return 0;
}