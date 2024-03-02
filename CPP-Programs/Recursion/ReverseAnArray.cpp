#include<bits/stdc++.h>
using namespace std;
void displayArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}
void reverseArray(int i, int arr[], int n) {
    if(i>=n/2) {
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverseArray(i+1, arr, n);
}
int main() {
    int arr[1000], size;
    cout<<"Enter the size of array : "<<endl;
    cin>>size;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
    cout<<"The array before reversing is : "<<endl;
    displayArray(arr, size);
    cout<<endl;
    cout<<"The array after reversing is : "<<endl;
    reverseArray(0, arr, size);
    displayArray(arr, size);
}