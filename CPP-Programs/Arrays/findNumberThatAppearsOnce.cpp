#include<bits/stdc++.h>
using namespace std;
// brute force solution
// int getSingleElement(vector<int> &arr) {
//     // Size of the array:
//     int n = arr.size();
//     //Run a loop for selecting elements:
//     for (int i = 0; i < n; i++) {
//         int num = arr[i]; // selected element
//         int cnt = 0;
//         //find the occurrence using linear search:
//         for (int j = 0; j < n; j++) {
//             if (arr[j] == num)
//                 cnt++;
//         }
//         // if the occurrence is 1 return ans:
//         if (cnt == 1) return num;
//     }
//     //This line will never execute
//     //if the array contains a single element.
//     return -1;
// }
// better solution below 
//size of the array:
// int getSingleElement(vector<int> &arr) {
//     //size of the array:
//     int n = arr.size();
//     // Declare the hashmap.
//     // And hash the given array:
//     map<int, int> mpp;
//     for (int i = 0; i < n; i++) {
//         mpp[arr[i]]++;
//     }
//     //Find the single element and return the answer:
//     for (auto it : mpp) {
//         if (it.second == 1)
//             return it.first;
//     }
//     //This line will never execute
//     //if the array contains a single element.
//     return -1;
// }
// Optimal Solution below 
int getSingleElement(vector<int> &arr) {
    int n = arr.size();
    // Using XOR
    int xorr = 0;
    // XOR of all the elements
    for(int i=0; i<n; i++) {
        xorr = xorr^arr[i];
    }
    // return the XOR
    return xorr;
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
    int ans = getSingleElement(arr);
    cout<<"The number that appears once in the array is : "<<ans<<endl;
    return 0;
}