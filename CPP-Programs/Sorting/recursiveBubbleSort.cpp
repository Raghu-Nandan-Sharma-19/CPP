#include<bits/stdc++.h>
using namespace std;
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void bubble_sort(int arr[], int n) {
    if(n==1) return;
    for(int j=0; j<=n-2; j++) {
        if(arr[j]>arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
    bubble_sort(arr, n-1);
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
    cout<<"Before recursive bubble sort : "<<endl;
    display(arr, size);
    cout<<"After recursive bubble sort : "<<endl;
    bubble_sort(arr, size);
    display(arr, size);
    return 0;
}