#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
// // better solution
// vector<int> nextGreaterPermutation(vector<int> &A) {
//     // using next_permutation function
//     next_permutation(A.begin(), A.end());
//     // return the next greater permutation
//     return A;
// }
// optimized solution below
vector<int> nextGreaterPermutation(vector<int> &A) {
    int index = -1, n = A.size();
    // traverse the array from right to left
    for(int i=n-2; i>=0; i--) {
        // find the first element from right which is smaller than the next element
        if(A[i] < A[i+1]) {
            // store the index of the element
            index = i;
            // break the loop
            break;
        }
    }
    // if no such element is found, reverse the array and return
    if(index == -1) {
        reverse(A.begin(), A.end());
        return A;
    }
    // traverse the array from right to left
    for(int i=n-1; i>=index; i--) {
        // find the first element from right which is greater than the element at index
        if(A[i] > A[index]) {
            // swap the elements
            swap(A[i], A[index]);
            // break the loop
            break;
        }
    }
    // reverse the array from index+1 to end
    reverse(A.begin()+index+1, A.end());
    // return the next greater permutation
    return A;
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
    // function call
    vector<int> ans = nextGreaterPermutation(arr);
    cout<<"Next greater permutation : ";
    display(ans);
    return 0;
}