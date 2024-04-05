#include<bits/stdc++.h>
using namespace std;
void display(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void insertion_sort(int arr[], int i, int n) {
    int j = i;
    if(i==n) return;
    while(j>0 && arr[j-1]>arr[j]) {
        swap(arr[j-1], arr[j]);
        j--;
    }
    insertion_sort(arr, i+1, n);
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
    cout<<"Before recursive insertion sort : "<<endl;
    display(arr, size);
    cout<<"After recursive insertion sort : "<<endl;
    insertion_sort(arr, 0, size);
    display(arr, size);
    return 0;
}