#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int smallestElement(vector<int> &arr, int n) {
    int smallest = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i]<smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
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
    cout<<"The smallest element in array is : "<<smallestElement(arr, size)<<endl;
    return 0;
}