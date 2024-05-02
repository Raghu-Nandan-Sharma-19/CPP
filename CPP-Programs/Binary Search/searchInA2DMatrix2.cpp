#include<bits/stdc++.h>
using namespace std;
bool searchElement(vector<vector<int>> &matrix, int target) {
    // Get the number of rows and columns in the matrix
    int n = matrix.size(); // Number of rows
    int m = matrix[0].size(); // Number of columns
    // Start from the top-right corner of the matrix
    int row = 0; // Start from the first row
    int col = m - 1; // Start from the last column
    // Continue searching until we reach the boundaries of the matrix
    while(row < n && col >= 0) {
        // If the current element is equal to the target, return true
        if(matrix[row][col] == target) return true;
        // If the current element is less than the target, move down in the matrix
        else if(matrix[row][col] < target) row++;
        // If the current element is greater than the target, move left in the matrix
        else col--;
    }
    // If the target is not found in the matrix, return false
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}};
    int target = 14;
    if(searchElement(matrix, target) == true) {
        cout<<"Element found"<<endl;
    } else {
        cout<<"Element not found"<<endl;
    }
    return 0;
}