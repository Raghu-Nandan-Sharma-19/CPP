#include<bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
    // Initialize low and high pointers for binary search
    int low = 0, high = arr.size()-1;
    // Binary search loop
    while(low <= high) {
        // Calculate the middle index
        int mid = (low+high)/2;
        
        // Calculate the number of missing elements between the current element and its index
        int missing = arr[mid]-(mid+1);
        
        // If the number of missing elements before arr[mid] is less than k,
        // we need to search in the right half of the array
        if(missing < k) low = mid+1;
        // Otherwise, search in the left half of the array
        else high = mid-1;
    }
    // At this point, high points to the index where the (k-1)th missing element should be.
    // So we return the position of the (k-1)th missing element plus k.
    return high+1+k;
}
int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    cout<<"The "<<k<<" TH missing positive number is : "<<findKthPositive(arr, k)<<endl;
    return 0;
}