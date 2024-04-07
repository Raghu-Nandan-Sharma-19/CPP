#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
vector<int> move(vector<int> &a, int n) {
    // vector<int> temp;
    // for(int i=0; i<a.size(); i++) {
    //     if(nums[i]!=0) {
    //         temp.push_back(a[i]);
    //     }
    // }
    // for(int i=0; i<temp.size(); i++) {
    //     a[i] = temp[i];
    // }
    // int nonZero = temp.size();
    // for(int i=nonZero; i<a.size(); i++) {
    //     a[i] = 0;
    // }
    // return a;
    // Optimal code below
    int j = -1;
    //place the pointer j:
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    //no non-zero elements:
    if (j == -1) return a;

    //Move the pointers i and j
    //and swap accordingly:
    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
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
    cout<<"The array after moving all zeroes to end is : "<<endl;
    move(arr, size);
    display(arr, size);
    return 0;
}