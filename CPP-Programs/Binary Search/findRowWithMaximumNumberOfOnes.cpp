#include<bits/stdc++.h>
using namespace std;
// Function to find the lower bound of an element in a sorted array
int lowerBound(vector<int> arr, int n, int x) {
    // Initializing answer with the size of array, assuming x is not found in the array
    int ans = n;
    // Setting up the pointers for binary search
    int low = 0, high = n-1;
    // Binary search loop
    while(low <= high) {
        // Calculating the middle index
        int mid = (low+high)/2;
        // If the middle element is greater than or equal to x
        if(arr[mid] >= x) {
            // Update answer to the current index
            ans = mid;
            // Move to the left half of the array
            high = mid-1;
        } else {
            // Move to the right half of the array
            low = mid+1;
        }
    }
    // Returning the lower bound index
    return ans;
}

// Function to find the row in the matrix with the maximum number of 1s
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    // Initializing variables to store the index of the row with max 1s and the count of max 1s
    int index = -1, maxCnt = 0;
    // Loop through each row of the matrix
    for (int i = 0; i < n; i++) {
        // Counting the number of 1s in the current row by subtracting the lower bound of 1 from total columns
        int cntOnes = m - lowerBound(matrix[i], m, 1);
        // If the count of 1s in the current row is greater than the max count
        if(cntOnes > maxCnt) {
            // Update the max count and index of the row
            maxCnt = cntOnes;
            index = i;
        }
    }
    // Returning the index of the row with the maximum number of 1s
    return index;
}
int main() {
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
    return 0;
}