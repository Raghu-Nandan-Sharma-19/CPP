#include<bits/stdc++.h>
using namespace std;
// // Brute Force Approach:
// // Given a matrix of size n x m, if an element is 0, set its entire row and column to 0.
// void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
//     // set all non-zero elements as -1 in the row i:
//     for (int j = 0; j < m; j++) { 
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }
// void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
//     // set all non-zero elements as -1 in the col j:
//     for (int i = 0; i < n; i++) {
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
//     // mark rows and columns to be set as 0:
//     for(int i=0; i<n; i++) { 
//         for(int j=0; j<m; j++) {
//             // if element is 0, mark the row and column:  
//             if(matrix[i][j] == 0) { 
//                 markRow(matrix, n, m, i);
//                 markCol(matrix, n, m, j);
//             }
//         }
//     }
//     // set the rows and columns to 0:
//     for(int i=0; i<n; i++) {
//         for(int j=0; j<m; j++) {
//             if(matrix[i][j] == -1) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
//     // return the matrix:
//     return matrix;
// }
// // Better solution
// vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
// 	int col[m] = {0}, row[n] = {0}; // initialize row and col arrays with 0
// 	for(int i=0; i<n; i++) { // mark the rows and columns to be set as 0
// 		for(int j=0; j<m; j++) { // if element is 0, mark the row and column
// 			if(matrix[i][j] == 0) { // mark the row and column
// 				row[i] = 1; 
// 				col[j] = 1;
// 			}
// 		}
// 	}
// 	for(int i=0; i<n; i++) { // set the rows and columns to 0
// 		for(int j=0; j<m; j++) { // if row or col is marked, set the element as 0
// 			if(row[i] || col[j]) { // if row or col is marked, set the element as 0
// 				matrix[i][j] = 0; // set the element as 0
// 			}
// 		}
// 	}
// 	return matrix; // return the matrix
// }
// optimal solution
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] != 0) {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    //step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0) {
        for (int j = 0; j < m; j++) {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0) {
        for (int i = 0; i < n; i++) {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}
int main() {
    int n, m;
    cout<<"Enter the number of rows and columns: ";
    cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> matrix[i][j];
        }
    }
    // function call:
    vector<vector<int>> ans = zeroMatrix(matrix, n, m);
    // print the matrix:
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}