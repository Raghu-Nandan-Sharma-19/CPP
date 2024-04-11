#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int>& a, long long k) {
    int left = 0, right = 0; // two pointers
    long long sum = a[0]; // sum of the subarray
    int maxLen = 0; // length of the subarray
    int n = a.size(); // size of the array
    while(right<n) { // loop until right pointer reaches the end
        while(left<=right && sum>k) { // if sum is greater than k, move the left pointer
            sum-=a[left]; // remove the element at left pointer
            left++; // move the left pointer
        }
        if(sum==k) {  // if sum is equal to k, update the length of the subarray
            maxLen = max(maxLen, right-left+1); // update the length of the subarray
        } 
        right++; // move the right pointer
        if(right<n) sum+=a[right]; // add the element at right pointer
    }
    return maxLen; // return the length of the subarray
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
    long long k;
    cout<<"Enter k : "<<endl;
    cin>>k;
    cout<<"The length of the longest subarray with sum equal to k is : "<<longestSubarrayWithSumK(arr, k)<<endl;
    return 0;
}