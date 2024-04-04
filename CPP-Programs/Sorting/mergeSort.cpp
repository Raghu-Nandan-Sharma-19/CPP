#include<bits/stdc++.h>
using namespace std;
void display(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
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
void merge_sort(vector<int> &arr, int low, int high) {
    if(low>=high) return;
    int mid = (low+high)/2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
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
    cout<<"Before merge sort : "<<endl;
    display(arr, size);
    cout<<"After merge sort : "<<endl;
    merge_sort(arr, 0, size-1);
    display(arr, size);
    return 0;
}