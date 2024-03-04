#include<bits/stdc++.h>
using namespace std;
void arrayInput(int arr[], int size) {
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }
}
void display(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void insertionSort(int arr[], int size) {
    for(int i=0; i<=size-1; i++) {
        int j=i;
        while(j>0 && arr[j-1]>arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}
int main() {
    int arr[1000], size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    arrayInput(arr, size);
    cout<<"The array is : "<<endl;
    display(arr, size);
    cout<<"After insertion sort the array is : "<<endl;
    insertionSort(arr, size);
    display(arr, size);
    return 0;
}