#include<bits/stdc++.h>
using namespace std;
void display(int arr[], int n) {
    for(int i=0; i<n; i++) { 
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void bubble_sort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]) { 
                swap(arr[j], arr[j+1]);
            }       
        }
    }
}
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<"Before bubble sort : "<<endl;
    display(arr, size);
    bubble_sort(arr, size);
    cout<<"After bubble sort : "<<endl;
    display(arr, size);
    return 0;
}