#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
vector<int> rotate(vector<int> &arr, int n) {
    int temp = arr[n-1];
    for(int i=n-2; i>=0; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
    return {arr};
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
    cout<<"The array after right rotating by one place is : "<<endl;
    rotate(arr, size);
    display(arr, size);
    return 0;
}