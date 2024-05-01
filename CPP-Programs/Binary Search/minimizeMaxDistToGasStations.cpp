#include<bits/stdc++.h>
using namespace std;
// Function to calculate the number of gas stations required
// Parameters:
//   dist: the maximum distance the car can travel with a full tank
//   arr: a vector containing distances between gas stations
// Returns:
//   The number of gas stations required to cover the given distance
int numberOfGasStationsReqd(long double dist, vector<int> &arr) {
    // Initialize a counter for gas stations
    int cnt = 0;
    // Loop through the distances between gas stations
    for(int i=1; i<arr.size(); i++) {
        // Calculate the number of gas stations needed between current and previous stations
        int numberInBetween = ((arr[i]-arr[i-1]) / dist);
        // If the distance perfectly divides by dist, reduce the count by 1
        if((arr[i]-arr[i-1]) / dist == numberInBetween * dist) {
            numberInBetween--;
        }
        // Add the number of gas stations required between current and previous stations to the counter
        cnt += numberInBetween;
    }
    // Return the total count of gas stations required
    return cnt;
}
// Function to minimize the maximum distance between gas stations
// Parameters:
//   arr: a vector containing distances between gas stations
//   k: the maximum number of gas stations allowed
// Returns:
//   The minimized maximum distance between gas stations
double minimiseMaxDistance(vector<int> &arr, int k) {
    // Get the size of the vector arr
    int n = arr.size();
    // Initialize low and high values for binary search
    long double low = 0;
    long double high = 0;
    // Find the maximum distance between adjacent gas stations
    for(int i=0; i<n-1; i++) {
        high = max(high, (long double)(arr[i+1]-arr[i]));
    }	
    // Set the precision for the binary search
    long double diff = 1e-6;
    // Perform binary search to minimize the maximum distance
    while((high-low) > diff) {
        // Calculate the mid value
        long double mid = (low+high)/(2.0);
        // Get the number of gas stations required for the current mid value
        int cnt = numberOfGasStationsReqd(mid, arr);
        // Adjust low and high based on the number of gas stations required
        if(cnt > k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    // Return the minimized maximum distance between gas stations
    return high;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}