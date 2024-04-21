#include<bits/stdc++.h>
using namespace std;
int maxProduct(vector<int> &nums) {
    int maxi = INT_MIN, n = nums.size();
    for(int i=0; i<n; i++) {
        int prod = 1;
        for(int j=i+1; j<n; j++) {
            prod *= nums[j];
            maxi = max(maxi, prod);
        }
    }
    return maxi;
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
    cout<<"The maximum product subarray is : "<<maxProduct(arr)<<endl;
    return 0;
}