#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// int majorityElement(vector<int> arr) {
//     int n = arr.size(); // Size of the array
//     for(int i=0; i<n; i++) { // Traverse the array
//         int cnt = 0; // Count of the element
//         for (int j=0; j<n; j++) { // Traverse the array
//             if (arr[j] == arr[i]) { // If the element is equal to the current element
//                 cnt++; // Increment the count
//             } 
//         }
//         if (cnt > (n/2)) return arr[i]; // If the count is greater than n/2 return the element
//     }
//     return -1; // If no majority element found return -1
// }
// // Better solution
// int majorityElement(vector<int> &arr) {
//     int n = arr.size(); // Size of the array
//     map<int, int> mpp; // Map to store the frequency of the elements
//     for(int i=0; i<n; i++) { // Traverse the array
//         mpp[arr[i]]++; // Increment the frequency of the element
//     }
//     for(auto it:mpp) { // Traverse the map
//         if(it.second > (mpp.size()/2)) { // If the frequency of the element is greater than n/2
//             return it.first; // Return the element
//         }
//     }
//     return -1; // If no majority element found return -1
// }
// Optimal approach (Moore's Voting Algorithm)
int majorityElement(vector<int> &arr) {
    int n = arr.size(); // Size of the array
    int cnt = 0; // Count of the element
    int element; // Element
    for(int i=0; i<n; i++) { // Traverse the array
        if(cnt == 0) { // If count is 0
            cnt = 1; // Increment the count
            element = arr[i]; // Assign the element
        } else if(arr[i] == element) { // If the element is equal to the current element
            cnt++; // Increment the count
        } else { // If the element is not equal to the current element
            cnt--; // Decrement the count
        }
    }
    int cnt1 = 0; // Count of the element
    for(int i=0; i<n; i++) { // Traverse the array
        if(arr[i] == element) cnt1++; // If the element is equal to the current element increment the count
    }
    if(cnt1>(n/2)) { // If the count is greater than n/2
        return element; // Return the element
    }
    return -1; // If no majority element found return -1
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
    // // brute force approach function call
    // int element = majorityElement(arr);
    // if(element == -1) {
    //     cout<<"No majority element found!"<<endl;
    // } else {
    //     cout<<"Majority element is: "<<element<<endl;
    // }
    // // Better solution function call
    // int element = majorityElement(arr);
    // if(element == -1) {
    //     cout<<"No majority element found!"<<endl;
    // } else {
    //     cout<<"Majority element is: "<<element<<endl;
    // }
    // optimised solution function call
    int element = majorityElement(arr);
    if(element == -1) {
        cout<<"No majority element found!"<<endl;
    } else {
        cout<<"Majority element is: "<<element<<endl;
    }
    return 0;
}