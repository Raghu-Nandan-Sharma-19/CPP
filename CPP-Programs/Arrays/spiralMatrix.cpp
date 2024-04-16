#include<bits/stdc++.h>
using namespace std;
vector<int> spiralMatrix(vector<vector<int>>&MATRIX) {
    // Write your code here.
    int n = MATRIX.size(), m = MATRIX[0].size();
    int top = 0, bottom = n-1;
    int left = 0, right = m-1;
    vector<int> ans;
    while(top<=bottom && left<=right) {
        // right
        for(int i=left; i<=right; i++) { // left to right
            ans.push_back(MATRIX[top][i]); 
        }
        top++;
        // bottom
        for(int i=top; i<=bottom; i++) { // top to bottom
            ans.push_back(MATRIX[i][right]);
        }
        right--;
        if(top <= bottom) { // left
            for (int i=right; i>=left; i--) { // right to left
              ans.push_back(MATRIX[bottom][i]);
            }
            bottom--;
        }
        // bottom to top
        if(left <= right) {
            for (int i=bottom; i>=top; i--) { // bottom to top
              ans.push_back(MATRIX[i][left]);
            }
            left++;
        }
    }
    return ans;
}
int main() {
    int rows, cols;
    cout<<"Enter the number of rows: "<<endl;
    cin>>rows;
    cout<<"Enter the number of columns: "<<endl;
    cin>>cols;
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout<<"Enter the matrix elements:"<<endl;
    for(int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            cin>>matrix[i][j];
        }
    }
    vector<int> spiral = spiralMatrix(matrix);
    cout << "Spiral matrix:\n";
    for(int i=0; i<spiral.size(); i++) {
        cout<<spiral[i]<<" ";
    } cout<<endl;
    return 0;
}