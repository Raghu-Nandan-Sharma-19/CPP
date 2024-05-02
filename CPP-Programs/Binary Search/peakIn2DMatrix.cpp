#include<bits/stdc++.h>
using namespace std;
// Function to find the index of the maximum element in a given column of the matrix
int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col) {
    // Initialize variables to store maximum value and its index
    int maxVal = -1, index = -1;
    // Loop through each row of the matrix
    for(int i = 0; i < n; i++) {
        // Check if the current element in the column is greater than the current maximum value
        if(mat[i][col] > maxVal) {
            // Update the maximum value and its index
            maxVal = mat[i][col];
            index = i;
        }
    }
    // Return the index of the maximum element in the column
    return index;
}

// Function to find a peak element in the grid using binary search
vector<int> findPeakGrid(vector<vector<int>> &mat) {
    // Get the number of rows and columns in the matrix
    int n = mat.size(), m = mat[0].size();
    // Initialize variables for binary search
    int low = 0, high = m - 1;
    // Binary search loop
    while(low <= high) {
        // Calculate the middle column
        int mid = (low + high) / 2;
        // Find the row index of the maximum element in the middle column
        int row = findMaxIndex(mat, n, m, mid);
        // Get the values of the elements to the left and right of the middle element
        int left = mid - 1 >= 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        // Check if the middle element is greater than its left and right neighbors
        if(mat[row][mid] > left && mat[row][mid] > right) {
            // If it is, it's a peak element, return its coordinates
            return {row, mid};
        } else if(mat[row][mid] < left) {
            // If the middle element is less than its left neighbor, search left
            high = mid - 1;
        } else {
            // Otherwise, search right
            low = mid + 1;
        }
    }
    // If no peak is found, return {-1, -1}
    return {-1, -1};  
}
int main() {
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}};
    vector<int> peak = findPeakGrid(mat);
    cout<<"Peak element found at index: "<<peak[0]<<" "<<peak[1]<<endl;
    return 0;
}