#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size()-1; // low and high are the indices of the array
    while(low<=high) { // if low is greater than high, then the element is not present in the array
        int mid = (low+high)/2; // calculating the mid index
        // if the element at mid index is equal to the target element, then return the mid index
        if(nums[mid] == target) { 
            return mid; 
        } else if(target > nums[mid]) { // if the target element is greater than the element at mid index   
            low = mid+1;  // then the target element will be present in the right half of the array
        } else { // if the target element is less than the element at mid index
            high = mid-1; // then the target element will be present in the left half of the array  
        }
    }
    return -1; // if the element is not present in the array, then return -1
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
    int index = search(arr, target);
    if(index != -1) {
        cout<<target<<" is present at index "<<index<<endl;
    } else {
        cout<<target<<" is not present in the array"<<endl;
    }
    return 0;
}