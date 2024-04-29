#include<bits/stdc++.h>
using namespace std;
// Function to find the maximum element in a vector
int maxElement(vector<int> &arr) {
    int maxi = INT_MIN; // Initialize the maximum element to the smallest possible integer
    for(int i=0; i<arr.size(); i++) {
        maxi = max(maxi, arr[i]); // Update the maximum element if the current element is greater
    }
    return maxi; // Return the maximum element
}

// Function to find the sum of elements in a vector
int sumOfElements(vector<int> arr) {
    int sum = 0; // Initialize sum to zero
    for(int i=0; i<arr.size(); i++) {
        sum += arr[i]; // Add each element to the sum
    }
    return sum; // Return the sum
}

// Function to find the number of days required to ship given weights with a specified capacity
int findDays(vector<int> &weights, int cap) {
    int days = 1, load = 0, n = weights.size(); // Initialize days, load, and the number of weights
    for(int i=0; i<n; i++) {
        if(load + weights[i] > cap) { // If adding the current weight exceeds the capacity
            days++; // Increment the number of days
            load = weights[i]; // Reset the load to the current weight
        } else {
            load += weights[i]; // Otherwise, add the current weight to the load
        }
    } 
    return days; // Return the total number of days required
}

// Function to find the minimum capacity required to ship the weights within specified days
int shipWithinDays(vector<int>& weights, int days) { 
    int low = maxElement(weights), high = sumOfElements(weights); // Initialize the range of possible capacities
    while(low <= high) { // Perform binary search within the range
        int mid = (low+high)/2; // Calculate the midpoint of the range
        int noOfDays = findDays(weights, mid); // Find the number of days required for the current capacity
        if(noOfDays <= days) { // If the number of days required is less than or equal to the specified days
            high = mid-1; // Adjust the upper bound of the range
        } else {
            low = mid+1; // Otherwise, adjust the lower bound of the range
        }
    }
    return low; // Return the minimum capacity required
}
int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = shipWithinDays(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}