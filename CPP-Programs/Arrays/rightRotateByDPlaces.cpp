// right rotate the array by d places
#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
vector<int> rotate(vector<int> &arr, int d) {
    d %= arr.size();
    reverse(arr.begin(), arr.end());
    reverse(arr.end(), arr.end() - d);
    reverse(arr.end() - d, arr.begin());
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
    cout<<"Enter the number of places for which you want to right rotate the array : "<<endl;
    cin>>d;
    rotate(arr, d);
    display(arr, size);
    return 0;
}