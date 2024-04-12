#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
// // Brute force approach
// void merge(vector<int> &arr, int low, int mid, int high) {
//     vector<int> temp;
//     int left = low;
//     int right = mid+1;
//     while(left<=mid && right<=high) {
//         if(arr[left]<=arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         } else {
//             temp.push_back(arr[right]);
//             right++;
//         } 
//     }
//     while(left<=mid) {
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right<=high) {
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i=low; i<=high; i++) {
//         arr[i] = temp[i-low];
//     }
// }
// void merge_sort(vector<int> &arr, int low, int high) {
//     if(low>=high) return;
//     int mid = (low+high)/2;
//     merge_sort(arr, low, mid);
//     merge_sort(arr, mid+1, high);
//     merge(arr, low, mid, high);
// }
// // Better solution
// void sort(vector<int> &arr) {
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0; // Count of 0's, 1's and 2's
//     for(int i=0; i<arr.size(); i++) { // Count the number of 0's, 1's and 2's
//         if(arr[i] == 0) cnt0++; // if the element is 0 increment the count of 0's
//         else if(arr[i] == 1) cnt1++; // if the element is 1 increment the count of 1's
//         else cnt2++; // if the element is 2 increment the count of 2's
//     }
//     for(int i=0; i<cnt0; i++) arr[i] = 0; // Fill the array with 0's
//     for(int i=cnt0; i<cnt0+cnt1; i++) arr[i] = 1; // Fill the array with 1's
//     for(int i=cnt0+cnt1; i<arr.size(); i++) arr[i] = 2; // Fill the array with 2's
// }
// Optimal solution below
void sort(vector<int> &arr) {
    int n = arr.size();
    int low = 0, mid = 0, high = n-1;
    while(mid<=high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if(arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
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
    // // function call for brute force approach
    // cout<<"Before merge sort : "<<endl;
    // display(arr);
    // cout<<"After merge sort : "<<endl;
    // merge_sort(arr, 0, size-1);
    // display(arr);
    // // function call for better approach
    // cout<<"The array after sorting 0's 1's and 2's is : "<<endl;
    // sort(arr);
    // display(arr);
    // function call for most optimal approach
    cout<<"The array after sorting 0's 1's and 2's is : "<<endl;
    sort(arr);
    display(arr);
    return 0;
}