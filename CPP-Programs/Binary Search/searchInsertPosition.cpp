#include<bits/stdc++.h>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
    int n = nums.size(); // n is the size of the array
    int ans = n; // ans is the index where we can insert the target element
    int low = 0, high = n-1; // low and high are the indices of the array
    while(low<=high) { // if low is greater than high, then the element is not present in the array
        int mid = (low+high)/2; // calculating the mid index
        if(nums[mid] >= target) { // if the element at mid index is greater than or equal to the target element
            ans = mid; // then update the ans to mid index
            high = mid-1; // then the target element will be present in the left half of the array
        } else { // if the element at mid index is less than the target element
            low = mid+1; // then the target element will be present in the right half of the array
        }
    }
    return ans; // return the index where we can insert the target element
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
    int target;
    cout<<"Enter the target element : "<<endl;
    cin>>target;
    cout<<"The index where we can insert "<<target<<" is : "<<searchInsert(arr, target)<<endl;
    return 0;
}