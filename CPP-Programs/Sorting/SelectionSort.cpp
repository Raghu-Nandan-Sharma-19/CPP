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
void selectionSort(int arr[], int size) {
    for(int i=0; i<=size-2; i++) {
        int mini=i;
        for(int j=i; j<=size-1; j++) {
            if(arr[j]<arr[mini]) {
                mini=j;
            }
            swap(arr[mini], arr[i]);
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
    cout<<"After selection sort the array is : "<<endl;
    selectionSort(arr, size);
    display(arr, size);
    return 0;
}