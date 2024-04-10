#include<bits/stdc++.h>
using namespace std;
int getMaximumCount(vector<int> &arr) {
    int maxi = 0, cnt = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==1) {  // If the element is 1, then increment the count
            cnt++; // Increment the count
            maxi = max(maxi, cnt); // Update the maximum count
        } else {
            cnt = 0;    // If the element is not 1, then reset the count
        }
    }
    return maxi;   // Return the maximum count
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
    cout<<"The maximum consecutive ones in the array is : "<<getMaximumCount(arr)<<endl;
    return 0;
}