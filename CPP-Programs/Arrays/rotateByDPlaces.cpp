#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
vector<int> rotate(vector<int> &arr, int d) {
    d%=arr.size();
    vector<int> temp;
    for(int i=0; i<d; i++) {
        temp.push_back(arr[i]);
    }
    for(int i=d; i<arr.size(); i++) {
        arr[i-d] = arr[i];
    }
    for(int i=arr.size()-d; i<arr.size(); i++) {
        arr[i] = temp[i-(arr.size()-d)];
    }
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
    int d;
    cout<<"Enter the number of places you want to rotate the array : "<<endl;
    cin>>d;
    cout<<"The array after rotating by "<<d<<" places is : "<<endl;
    rotate(arr, d);
    display(arr, size);
    return 0;
}