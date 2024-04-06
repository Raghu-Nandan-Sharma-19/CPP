#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int secondLargest(vector<int> &arr, int n) {
    int largest = arr[0];
    int sLargest = -1;
    for(int i=1; i<n; i++) {
        if(arr[i]>largest) {
            sLargest = largest;
            largest = arr[i];
        } else if(arr[i]<largest && arr[i]>sLargest) {
            sLargest = arr[i];
        }
    }
    return sLargest;
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
    cout<<"Second largest element is : "<<secondLargest(arr, size)<<endl;
    return 0;
}