#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// bool linearSearch(vector<int> &a, int num) {
//     for(int i=0; i<a.size(); i++) {
//         if(a[i] == num) {
//             return true;
//         }
//     }
//     return false;
// }
// int longestSuccessiveElements(vector<int> &a) {
//     int longest = 1;  // declare the longest sequence as 1
//     for(int i=0; i<a.size(); i++) {  // traverse the loop
//         // initialize first element of array as x and initialize counter = 1 
//         int x = a[i], cnt = 1;  
//         while(linearSearch(a, x+1) == true) { // linear search to find the next greater element
//             x++;  // increment the value of x
//             cnt++; // increment the counter
//         }
//         longest = max(longest, cnt); // find the maximum between counter and longest and store it in longest
//     }
//     return longest;  // return the longest sequence
// }
// // better solution
// int longestSuccessiveElements(vector<int> &a) {
//     if(a.size() == 0) return 0; // if the size of array is 0, return 0
//     sort(a.begin(), a.end()); // sort the array
//     // initialize counter as 0, lastSmaller as INT_MIN and longest as 1
//     int cntCur = 0, lastSmaller = INT_MIN, longest = 1; 
//     // traverse the array
//     for(int i=0; i<a.size(); i++) {
//         // if the current element is 1 greater than the last smaller element
//         if(a[i]-1 == lastSmaller) {
//             // increment the counter
//             cntCur++;
//             // update the last smaller element
//             lastSmaller = a[i];
//         } else if(a[i] != lastSmaller) { // if the current element is not equal to last smaller element
//             cntCur = 1;  // update the counter as 1
//             lastSmaller = a[i]; // update the last smaller element
//         }
//         longest = max(longest, cntCur); // find the maximum between counter and longest and store it in longest
//     }
//     // return the longest sequence
//     return longest;
// }
// Optimal solution 
int longestSuccessiveElements(vector<int> &a) {
    int n = a.size();
    if(n == 0) return 0; // if the size of array is 0, return 0
    int longest = 1; // initialize the longest sequence as 1
    unordered_set<int> st; // declare a set
    for(int i=0; i<n; i++) { // insert all the elements of array in the set
        st.insert(a[i]); 
    }
    for(auto it:st) { // traverse the set
        if(st.find(it-1) == st.end()) { // if the previous element is not present in the set    
            int cnt = 1; // initialize counter as 1
            int x = it; // initialize x as the current element
            while(st.find(x+1) != st.end()) { // if the next element is present in the set
                x++; // increment the value of x
                cnt++; // increment the counter
            }
            longest = max(longest, cnt); // find the maximum between counter and longest and store it in longest
        }
    }
    return longest; // return the longest sequence
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
    cout<<"The length of longest consecutive sequence in array is : "<<longestSuccessiveElements(arr)<<endl;
    return 0;
}