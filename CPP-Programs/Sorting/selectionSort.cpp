#include<bits/stdc++.h>
using namespace std;
void display(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
void selection_sort(int arr[], int n) {
    for(int i=0; i<=n-2; i++) {
        int mini = i;
        for(int j=i; j<=n-1; j++) {
            if(arr[j]<arr[mini]) {
                mini = j;
            }
        }
        swap(arr[mini], arr[i]);
        // int temp = arr[mini];
        // arr[mini] = arr[i];
        // arr[i] = temp;
    }
}
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) cin>>arr[i];
    cout<<"Before selection sort : "<<endl;
    display(arr, size);
    cout<<"After selection sort : "<<endl;
    selection_sort(arr, size);
    display(arr, size);
    return 0;
}