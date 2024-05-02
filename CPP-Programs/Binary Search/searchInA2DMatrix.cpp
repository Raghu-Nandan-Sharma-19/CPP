#include<bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Get the number of rows and columns in the matrix
    int n = matrix.size(), m = matrix[0].size();
    // Set the initial low and high pointers for binary search
    int low = 0, high = n * m - 1;
    // Binary search loop
    while(low <= high) {
        // Calculate the middle index
        int mid = (low + high) / 2;
        // Convert the middle index to row and column
        int row = mid / m, col = mid % m;
        // If the element at the middle index is equal to the target, return true
        if(matrix[row][col] == target) return true;
        // If the element at the middle index is less than the target, update the low pointer
        else if(matrix[row][col] < target) low = mid + 1;
        // If the element at the middle index is greater than the target, update the high pointer
        else high = mid - 1;
    }
    // If the target is not found, return false
    return false;
}
int main() {
    vector<vector<int>> matrix = {{3, 4, 7, 9}, {12, 13, 16, 18}, {20, 21, 23, 29}};
    int target = 23;
    if(searchMatrix(matrix, target) == true) {
        cout<<"Target found"<<endl;
    } else {
        cout<<"Target not found"<<endl;
    }
    return 0;
}