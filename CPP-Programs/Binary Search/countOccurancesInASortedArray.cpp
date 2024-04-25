#include<bits/stdc++.h>
using namespace std;
int firstOccurrence(vector<int> &arr, int n, int x) {
    int low = 0, high = n-1;
    int first = -1; // Initialize the first occurrence index to -1
    while(low <= high) { 
        int mid = (low + high) / 2; // Calculate the middle index
        if(arr[mid] == x) { 
            first = mid; // Update the first occurrence index
            high = mid - 1; // Search for first occurrence in the left subarray
        } else if(arr[mid] < x) { 
            low = mid + 1; // If the element at mid is less than x, search in the right subarray
        } else { 
            high = mid - 1; // If the element at mid is greater than x, search in the left subarray
        }
    }
    return first; // Return the index of the first occurrence of x
}

// Function to find the last occurrence of element x in a sorted vector arr
int lastOccurrence(vector<int> &arr, int n, int x) {
    int low = 0, high = n-1;
    int last = -1; // Initialize the last occurrence index to -1
    while(low <= high) {
        int mid = (low + high) / 2; // Calculate the middle index
        if(arr[mid] == x) {
            last = mid; // Update the last occurrence index
            low = mid + 1; // Search for last occurrence in the right subarray
        } else if(arr[mid] < x) {
            low = mid + 1; // If the element at mid is less than x, search in the right subarray
        } else {
            high = mid - 1; // If the element at mid is greater than x, search in the left subarray
        }
    }
    return last; // Return the index of the last occurrence of x
}

// Function to find both the first and last occurrences of element k in a sorted vector arr
pair<int, int> firstAndLastOccurrence(vector<int> arr, int k) {
    int n = arr.size();
    int first = firstOccurrence(arr, n, k); // Find the first occurrence of k
    if(first == -1) { // If k is not found, return {-1, -1}
        return {-1, -1};
    }
    int last = lastOccurrence(arr, n, k); // Find the last occurrence of k
    return {first, last}; // Return a pair containing the first and last occurrences of k
}
int count(vector<int>& arr, int n, int x) {
	pair<int, int> ans = firstAndLastOccurrence( arr,  x);
	if(ans.first == -1) return 0;
	return ans.second-ans.first+1;
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
    cout<<"Enter a number to find its count : "<<endl;
    cin>>target;
    cout<<"The count of "<<target<<" is : "<<count(arr, size, target)<<endl;
    return 0;
}