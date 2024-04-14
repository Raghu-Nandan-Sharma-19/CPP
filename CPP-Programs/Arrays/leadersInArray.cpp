#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr) {
    cout<<"[ ";
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<" ]"<<endl;
}
// // brute force approach
// vector<int> findLeaders(vector<int> &a) {
//     // vector to store the leaders
//     vector<int> ans;
//     // traverse the array
//     for(int i=0; i<a.size(); i++) {
//         // initialize leader as true
//         bool leader = true;
//         // traverse the array from i+1 to end
//         for(int j=i+1; j<a.size(); j++) {
//             // if any element is greater than the current element, it is not a leader
//             if(a[j] > a[i]) {
//                 leader = false;
//                 // break the loop
//                 break;
//             }
//         }
//         // if leader is true, push the element to the answer vector
//         if(leader == true) ans.push_back(a[i]);
//     }
//     // return the answer vector
//     return ans;
// }
// optimized approach
vector<int> findLeaders(vector<int> &a) {
    // vector to store the leaders
    vector<int> ans;
    // initialize the maximum element as INT_MIN
    int maxi = INT_MIN;
    int n = a.size();
    // traverse the array from right to left
    for(int i=n-1; i>=0; i--) {
        // if the current element is greater than the maximum element
        if(a[i] > maxi) {
            // push the element to the answer vector
            ans.push_back(a[i]);
        }
        // update the maximum element
        maxi = max(maxi, a[i]);
    }
    // sort the answer vector
    sort(ans.begin(), ans.end());
    // return the answer vector
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
    vector<int> ans = findLeaders(arr);
    cout<<"Leaders in the array are : "<<endl;
    display(ans);
    return 0;
}