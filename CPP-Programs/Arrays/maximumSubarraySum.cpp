#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// long long maxSubarraySum(vector<int> arr, int n) {
//     long long maxi = LONG_MIN; // Initialize the maximum sum
//     for(int i=0; i<n; i++) { // Traverse the array
//         for(int j=i; j<n; j++) { // Traverse the array
//             long long sum = 0; // Initialize the sum
//             for(int k=i; k<=j; k++) { // Traverse the array
//                 sum += arr[k]; // Add the element to the sum
//             }
//             maxi = max(maxi, sum); // Update the maximum sum
//         }
//     }
//     return maxi; // Return the maximum sum
// }
// // better approach
// long long maxSubarraySum(vector<int> arr, int n) {
//     int maxi = INT_MIN;  // Initialize the maximum sum
//     for(int i=0; i<n; i++) { // Traverse the array
//         int sum = 0; // Initialize the sum
//         for(int j=i; j<n; j++) { // Traverse the array
//             sum += arr[j]; // Add the element to the sum
//         } 
//         maxi = max(maxi, sum); // Update the maximum sum
//     }
//     return maxi; // Return the maximum sum
// }
// optimal approach
long long maxSubarraySum(vector<int> arr, int n)
{
    long long maxi = LONG_MIN; // Initialize the maximum sum
    long long sum = 0; // Initialize the sum
    for(int i=0; i<n; i++) { // Traverse the array
        sum += arr[i]; // Add the element to the sum
        maxi = max(maxi, sum); // Update the maximum sum
        if(sum < 0) sum = 0; // If the sum is less than 0, update the sum to 0
    }
    if(maxi < 0) maxi = 0; // If the maximum sum is less than 0, update the maximum sum to 0
    return maxi; // Return the maximum sum
}
int main() {
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Enter "<<size<<" elements: "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"Maximum subarray sum: "<<maxSubarraySum(arr, size)<<endl;
    return 0;
}