#include<bits/stdc++.h>
using namespace std;
// // brute force approach
// vector<vector<int>> rotate(vector<vector<int>> &matrix) {
//     int n = matrix.size(); 
//     vector<vector<int>> rotated(n, vector<int> (n, 0)); // Rotated matrix
//     for(int i=0; i<n; i++) { // Rotating the matrix
//         for(int j=0; j<n; j++) { // Rotating the matrix
//             rotated[j][n-i-1] = matrix[i][j]; 
//         }
//     }
//     return rotated;
// }
// optimal approach
vector<vector<int>> rotate(vector<vector<int>> &matrix) {
    int n = matrix.size(); 
    for(int i=0; i<n; i++) { // Transpose of the matrix
        for(int j=i; j<n; j++) { // Transpose of the matrix
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<n; i++) { // Reversing the rows
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;

} 
int main() {
    int n, m;
    cout<<"Enter the number of rows: "<<endl;
    cin>>n;
    cout<<"Enter the number of columns: "<<endl;
    cin>>m;
    vector<vector<int>> matrix(n, vector<int>(m));
    cout<<"Enter the matrix elements:"<<endl;
    for(int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> rotated = rotate(matrix);
    cout << "Rotated matrix:\n";
    for(int i=0; i<rotated.size(); i++) {
        for (int j=0; j<rotated[i].size(); j++) {
            cout<<rotated[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}