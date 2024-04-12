#include<bits/stdc++.h>
using namespace std;
// Brute force approach
// string twoSum(int n, vector<int> &arr, int target) {
//     for(int i=0; i<n; i++) {  // loop through the array
//         for(int j=i+1; j<n; j++) { // loop through the array
//             if(arr[i]+arr[j]==target) { // if the sum of the two elements is equal to the target sum
//                 return "YES"; // return YES
//             }
//         }
//     }
//     return "NO"; // return NO
// }
// Better solution below but if you want to return indices it is the most optimal
// vector<int> twoSum(int n, vector<int> &arr, int target) {
//     map<int, int> mpp;  // map to store the elements of the array
//     for(int i=0; i<n; i++) { // loop through the array
//         int a = arr[i]; // current element
//         int more = target - a; // element needed to make the sum equal to target
//         if(mpp.find(more)!=mpp.end()) { // if the element needed is found in the map
//             return {mpp[more], i}; // return the indices of the two elements
//         }
//         mpp[a] = i; // store the current element in the map
//     }
//     return {}; // return an empty vector if no pair is found
// }
// Optimal solution below return yes or no 
string twoSum(int n, vector<int> &arr, int target) {
    int left = 0, right = n-1;  // two pointers
    sort(arr.begin(), arr.end()); // sort the array
    while(left < right) { // loop until left pointer is less than right pointer
        int sum = arr[left]+arr[right]; // sum of the two elements
        if(sum == target) { // if the sum is equal to the target sum
            return "YES"; // return YES
        } else if(sum < target) { // if the sum is less than the target sum
            left++; // move the left pointer
        } else { // if the sum is greater than the target sum
            right--; // move the right pointer
        }
    }
    return "NO"; // return NO
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
    int target;
    cout<<"Enter the target sum : "<<endl;
    cin>>target;
    cout<<"Does the array contain two elements whose sum is equal to the target sum? "<<endl;
    cout<<twoSum(size, arr, target)<<endl; // function call
    // below is the code if you want to return indices it is function call for better solutin
    // vector<int> ans = twoSum(size, arr, target);
    // cout<<"Does the array contain two elements whose sum is equal to the target sum? :"<<endl;
    // if(ans.size()==0) {
    //     cout<<"NO"<<endl;
    // } else {
    //     cout<<"YES"<<endl;
    //     cout<<"The indices of the two elements are : "<<ans[0]<<" "<<ans[1]<<endl;
    // }
    return 0;
}