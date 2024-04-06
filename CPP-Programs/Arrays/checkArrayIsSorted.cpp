#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int isSorted(vector<int> arr, int n) {
    for(int i=1; i<n; i++) {
        if(arr[i]>=arr[i-1]) {

        } else {
            return false;
        }
    }
    return true;
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
    if(isSorted(arr, size)) {
        cout<<"The array is sorted."<<endl;
    } else {
        cout<<"The array is not sorted."<<endl;
    }
}