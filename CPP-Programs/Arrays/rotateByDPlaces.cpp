#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
vector<int> rotate(vector<int> &arr, int d) {
    d%=arr.size();
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin()+d+1);
    reverse(arr.begin()+d+1, arr.end());
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