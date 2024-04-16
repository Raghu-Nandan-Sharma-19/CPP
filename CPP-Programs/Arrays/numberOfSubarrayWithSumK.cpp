#include<bits/stdc++.h>
using namespace std;
// // brute force solution
// int findAllSubarraysWithTheGivenSum(vector<int> &arr, int k) {
//     int n = arr.size(); // size of the array
//     int cnt = 0; // count of subarrays
//     for(int i=0; i<n; i++) { // finding the subarrays
//         for(int j=i; j<n; j++) { // finding the subarrays
//             int sum = 0; // sum of the subarray
//             for(int k=i; k<=j; k++) { // finding the sum of the subarray
//                 sum += arr[k]; // finding the sum of the subarray
//             }
//             if(sum == k) { // checking if the sum of the subarray is equal to k
//                 cnt++; // incrementing the count of subarrays
//             }
//         }
//     }
//     return cnt; // returning the count of subarrays
// }
// // better solution
// int findAllSubarraysWithTheGivenSum(vector<int> &arr, int k) {
//     int n = arr.size(); // size of the array
//     int cnt = 0;
//     for(int i=0; i<n; i++) { // finding the subarrays
//         int sum = 0;
//         for(int j=i; j<n; j++) { // finding the subarrays
//             sum += arr[j]; // finding the sum of the subarray
//             if(sum == k) { // checking if the sum of the subarray is equal to k
//                 cnt++; // incrementing the count of subarrays
//             }
//         }
//     }
//     return cnt; // returning the count of subarrays
// }
// optimal solution
int findAllSubarraysWithTheGivenSum(vector<int> &arr, int k) {
    unordered_map<int, int> mpp; // map to store the prefix sum
    mpp[0] = 1; // initialising the map
    int preSum = 0, cnt = 0; // prefix sum and count of subarrays
    for(int i=0; i<arr.size(); i++) { // finding the subarrays
        preSum += arr[i]; // finding the prefix sum
        int remove = preSum-k; // finding the sum to be removed
        cnt += mpp[remove]; // incrementing the count of subarrays
        mpp[preSum] += 1; // storing the prefix sum
    }
    return cnt; // returning the count of subarrays
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
    cout<<"The number of subarrays with sum "<<k<<" is : "<<findAllSubarraysWithTheGivenSum(arr, k)<<endl;
    return 0;
}