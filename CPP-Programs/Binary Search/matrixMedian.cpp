#include<bits/stdc++.h>
using namespace std;
// Function to count the number of elements smaller than or equal to mid in a sorted row
int countSmallerThanMid(vector<int> &row, int mid) {
    // Initialize two pointers: l to the start of the row, and h to the end of the row
    int l = 0, h = row.size() - 1;
    // Binary search to find the position of mid in the row
    while (l <= h) {
        // Calculate the mid point of the current range
        int md = (l + h) >> 1;  // equivalent to (l + h) / 2, but faster
        // If the value at mid index is less than or equal to mid, move to the right half of the row
        if (row[md] <= mid) {
            l = md + 1;
        }
        // If the value at mid index is greater than mid, move to the left half of the row
        else {
            h = md - 1;
        }
    }
    // Return the index where the first element greater than mid would be placed
    // This effectively gives the count of elements smaller than or equal to mid in the row
    return l;
}

// Function to find the median of a matrix
int median(vector<vector<int>> &matrix, int m, int n) {
    // Initialize the low and high values for binary search
    int low = 1;
    int high = 1e9;  // 10^9
    // Determine the number of rows and columns in the matrix
    n = matrix.size();
    m = matrix[0].size();
    // Binary search to find the median value
    while (low <= high) {
        // Calculate the mid value
        int mid = (low + high) >> 1;  // equivalent to (low + high) / 2, but faster
        // Initialize a counter to store the count of elements smaller than or equal to mid
        int cnt = 0;
        // Iterate through each row of the matrix
        for (int i = 0; i < n; i++) {
            // Update the counter by adding the count of elements smaller than or equal to mid in each row
            cnt += countSmallerThanMid(matrix[i], mid);
        }
        // If the count of elements smaller than or equal to mid is less than or equal to half of the total elements,
        // update the low value to mid + 1 to search in the upper half of the range
        if (cnt <= (n * m) / 2) low = mid + 1;
        // Otherwise, update the high value to mid - 1 to search in the lower half of the range
        else high = mid - 1;
    }
    // Return the low value, which represents the median value
    return low;
}
int main() {
    vector<vector<int>> matrix = {{1, 3, 5}, {2, 6, 9}, {3, 6, 9}};
    int m = matrix.size();
    int n = matrix[0].size();
    cout << "Median of the matrix is: " << median(matrix, m, n) << endl;
    return 0;
}