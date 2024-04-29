#include<bits/stdc++.h>
using namespace std;
// Function to find the maximum element in the given vector
int maxElement(vector<int> &arr) {
    int maxi = INT_MIN; // Initialize the maximum element as the smallest possible integer value
    for(int i=0; i<arr.size(); i++) {
        maxi = max(maxi, arr[i]); // Update the maximum element if a larger element is found
    }
    return maxi; // Return the maximum element
}

// Function to calculate the sum of ceil(arr[i] / d) for each element arr[i] in the vector
int sumD(vector<int> &arr, int d) {
    int sum = 0; // Initialize the sum
    for(int i=0; i<arr.size(); i++) {
        sum += ceil((double)arr[i] / (double)d); // Increment the sum by ceil(arr[i] / d)
    }
    return sum; // Return the sum
}

// Function to find the smallest divisor such that the sumD() function does not exceed the given threshold
int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1, high = maxElement(nums); // Initialize the range of possible divisors from 1 to the maximum element in the vector
    while(low <= high) { // Binary search loop
        int mid = (low+high)/2; // Calculate the midpoint of the current range
        if(sumD(nums, mid) <= threshold) { // If the sum of ceil(arr[i] / mid) for each element does not exceed the threshold
            high = mid-1; // Update the upper bound of the range to search for a smaller divisor
        } else {
            low = mid+1; // Update the lower bound of the range to search for a larger divisor
        }
    }
    return low; // Return the smallest divisor found
}
int main() {
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 7;
    cout<<"The smallest divisor of "<<threshold<<" is : "<<smallestDivisor(arr, threshold);
    return 0;
}