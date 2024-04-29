#include<bits/stdc++.h>
using namespace std;
// This function checks if it is possible to arrange the flowers in such a way that 
// at least 'm' bouquets can be made, each consisting of 'k' consecutive flowers, 
// given the constraint that flowers bloom on different days.

bool possible(vector<int> &arr, int day, int m, int k) {
    // Initialize variables to count flowers and bouquets
    int cnt = 0, noOfB = 0;
    
    // Iterate through the array of bloom days
    for(int i=0; i<arr.size(); i++) {
        // Check if the current flower blooms on or before the given day
        if(arr[i] <= day) {
            cnt++; // Increment the count of flowers
        } else {
            // If the flower blooms after the given day, calculate the number of bouquets that can be made
            noOfB += (cnt/k); // Increment the count of bouquets
            cnt = 0; // Reset the count of flowers
        }
    }
    
    // After looping through all flowers, calculate the remaining bouquets
    noOfB += (cnt/k);
    
    // Check if the total number of bouquets is greater than or equal to the required number 'm'
    if(noOfB >= m) return true; // If yes, return true
    else return false; // If not, return false
}

// This function finds the minimum number of days needed for at least 'm' bouquets, 
// each consisting of 'k' consecutive flowers, given the array of bloom days.

int roseGarden(vector<int> bloomDay, int m, int k) {
    // Calculate the total number of flowers required
    long long val = m * 1LL * k * 1LL;
    
    // Get the size of the array of bloom days
    int n = bloomDay.size();
    
    // Check if the required number of flowers exceeds the total number of flowers available
    if(val > n) return -1; // If yes, return -1 as it is impossible to make 'm' bouquets
    
    // Initialize variables to store the minimum and maximum bloom days
    int mini = INT_MAX, maxi = INT_MIN;
    
    // Loop through the array of bloom days to find the minimum and maximum bloom days
    for(int i=0; i<n; i++) {
        mini = min(mini, bloomDay[i]); // Update the minimum bloom day
        maxi = max(maxi, bloomDay[i]); // Update the maximum bloom day
    }
    
    // Initialize variables for binary search
    int low = mini, high = maxi;
    
    // Perform binary search to find the minimum number of days required
    while(low <= high) {
        int mid = (low+high)/2; // Calculate the mid value
        
        // Check if it is possible to make 'm' bouquets with 'k' flowers each on or before the mid day
        if(possible(bloomDay, mid, m, k) == true) {
            high = mid-1; // If yes, update the upper bound
        } else {
            low = mid+1; // If not, update the lower bound
        }
    }
    
    return low; // Return the minimum number of days required
}
int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}