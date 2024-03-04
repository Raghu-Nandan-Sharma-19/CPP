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
void bubbleSort(int arr[], int size) {
    int didSwap=0;
    for(int i=size-1; i>=1; i--) {
        for(int j=0; j<=i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
                didSwap=1;
            }
        }
        if(didSwap==0) {
            break;
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
    cout<<"After bubble sort the array is : "<<endl;
    bubbleSort(arr, size);
    display(arr, size);
    return 0;
}