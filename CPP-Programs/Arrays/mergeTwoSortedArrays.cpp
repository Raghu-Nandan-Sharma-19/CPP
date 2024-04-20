#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int left = m-1; // left pointer
    int right = 0; // right pointer
    while(left>=0 && right<n) { // loop through the arrays
        // if the element in the first array is greater than the element in the second array
        if(nums1[left]>nums2[right]) { 
            // swap the elements
            swap(nums1[left], nums2[right]);
            left--; // decrement the left pointer
            right++; // increment the right pointer
        } else {
            break; // break the loop
        }
    }
    sort(nums1.begin(), nums1.end()); // sort the first array
    sort(nums2.begin(), nums2.end()); // sort the second array
}
int main() {
    int size1, size2;
    cout<<"Enter size of the first array : "<<endl;
    cin>>size1;
    cout<<"Enter size of the second array : "<<endl;
    cin>>size2;
    vector<int> arr1, arr2;
    cout<<"Enter "<<size1<<" elements in first array : "<<endl;
    for(int i=0; i<size1; i++) {
        int temp;
        cin>>temp;
        arr1.push_back(temp);
    }
    cout<<"Enter "<<size2<<" elements in second array : "<<endl;
    for(int i=0; i<size2; i++) {
        int temp;
        cin>>temp;
        arr2.push_back(temp);
    }
    merge(arr1, size1, arr2, size2);
    cout<<"After merging the two arrays : "<<endl;
    for(auto it:arr1) {
        cout<<it<<" ";
    }
    for(auto it:arr2) {
        cout<<it<<" ";
    } cout<<endl;
    return 0;
}