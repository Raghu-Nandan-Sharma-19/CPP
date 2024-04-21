#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// int reversePairs(vector<int> &nums) {
//     int n = nums.size(), cnt = 0;
//     for(int i=0; i<n; i++) {
//         for(int j=i+1; j<n; j++) {
//             if(nums[i] > 2*nums[j]) {
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }
// optimal approach --> using merge sort
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
void countPairs(vector<int> &arr, int low, int mid, int high) {
    int right = mid+1;
    for(int i=low; i<=mid; i++) {
        while(right<=high && arr[i]>2*arr[right]) {
            right++;
        }
        cnt += (right-(mid+1));
    }
}
void merge_sort(vector<int> &arr, int low, int high) {
    if(low>=high) return;
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
}
int reversePairs(vector<int>& nums) {
    int n = nums.size();
    merge_sort(nums, 0, n-1);
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
    cout<<"The number of reverse pair is : "<<reversePairs(arr)<<endl;
    return 0;
}