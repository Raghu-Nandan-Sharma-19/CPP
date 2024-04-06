#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int secondSmallest(vector<int> &arr, int n) {
    int smallest = arr[0];
    int sSmallest = INT_MAX;
    for(int i=1; i<n; i++) {
        if(arr[i]<smallest) {
            sSmallest = smallest;
            smallest = arr[i];
        } else if(arr[i]!=smallest && arr[i]<sSmallest) {
            sSmallest = arr[i];
        }
    }   
    return sSmallest;
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
    cout<<"The array is : "<<endl;
    display(arr, size);
    cout<<"The second smallest element in array is : "<<secondSmallest(arr, size)<<endl;
    return 0;
}