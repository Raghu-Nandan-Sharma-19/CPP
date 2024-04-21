#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// int numberOfInversions(vector<int> &arr) {
//     // initialising the count of inversions
//     int n = arr.size(), cnt = 0;
//     // checking for each pair of elements
//     for(int i=0; i<n; i++) {
//         for(int j=i+1; j<n; j++) {
//             // if the element at i is greater than the element at j then increment the count
//             if(arr[i]>arr[j]) {
//                 cnt++;
//             }
//         }
//     }
//     // return the count of inversions
//     return cnt;
// }
// optimal solution --> using merge sort
int cnt = 0;
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<=mid && right<=high) {
        if(arr[left]<=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            cnt += (mid-left+1);
            right++;
        } 
    }
    while(left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high) {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++) {
        arr[i] = temp[i-low];
    }
}
void merge_sort(vector<int> &arr, int low, int high) {
    if(low>=high) return;
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
int numberOfInversions(vector<int> &arr) {
    int n = arr.size();
    merge_sort(arr, 0, n-1);
    return cnt;
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
    cout<<"The number of inversions in the given array is : "<<numberOfInversions(arr)<<endl;
    return 0;
}