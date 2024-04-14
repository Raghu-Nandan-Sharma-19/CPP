#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
// // brute force approach
// vector<int> rearrangeBySign(vector<int> arr) {
//      int n = arr.size();
//     // Create two vectors to store positive and negative elements
//     vector<int> pos;
//     vector<int> neg;
//     // Traverse the array and store positive and negative elements in their respective vectors
//     for(int i=0; i<n; i++) {
//         if(arr[i]>0) pos.push_back(arr[i]);
//         else neg.push_back(arr[i]);
//     }
//     // Sort the positive and negative vectors
//     for(int i=0; i<n/2; i++) {
//         // store the positive and negative elements in the array alternatively
//         arr[2*i] = pos[i]; 
//         arr[2*i+1] = neg[i];
//     }
//     // return the rearranged array
//     return arr;
// }
// optimized approach
vector<int> rearrangeBySign(vector<int> arr) {
    int n = arr.size();
    // Initialize the answer array with 0
    vector<int> ans(n, 0);
    // Initialize the positive and negative indexes
    int posIndex = 0, negIndex = 1;
    // Traverse the array
    for(int i=0; i<n; i++) {
        // If the element is negative, store it at the negative index and increment the negative index by 2
        if(arr[i]<0) {
            ans[negIndex] = arr[i];
            negIndex += 2;
        } else { // If the element is positive, store it at the positive index and increment the positive index by 2
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }
    // return the rearranged array
    return ans;
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
    vector<int> ans = rearrangeBySign(arr);
    cout<<"The array after rearranging elements by sign is : "<<endl;
    display(ans, ans.size());
    return 0;
}