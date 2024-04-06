#include<bits/stdc++.h>
using namespace std;
void display(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int find_largest(vector<int> &arr, int n) {
    int largest = arr[0];
    for(int i=0; i<n; i++) {
        if(arr[i]>largest) {
            largest = arr[i];
        }
    }
    return largest;
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
    cout<<"Largest element in array is : "<<find_largest(arr, size)<<endl;
    return 0;
}