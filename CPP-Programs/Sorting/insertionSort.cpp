#include<bits/stdc++.h>
using namespace std;
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void insertion_sort(int arr[], int n) {
    for(int i=0; i<=n-1; i++) {
        int j = i;
        while(j>0 && arr[j-1]>arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
    cout<<"Before insertion sort : "<<endl;
    display(arr, size);
    cout<<"After insertion sort : "<<endl;
    insertion_sort(arr, size);
    display(arr, size);
    return 0;
}