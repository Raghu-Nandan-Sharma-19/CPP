#include<bits/stdc++.h>
using namespace std;
int linearSearch(vector<int> &arr, int size, int num) {
    for(int i=0; i<size; i++) {
        if(arr[i]==num) {
            return i;
        }
    }
    return -1;
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
    int num;
    cout<<"Enter the number to be searched : "<<endl;
    cin>>num;
    int index = linearSearch(arr, size, num);
    if(index==-1) {
        cout<<"Element not found!"<<endl;
    } else {
        cout<<"Element found at index : "<<index<<endl;
    }
    return 0;
}