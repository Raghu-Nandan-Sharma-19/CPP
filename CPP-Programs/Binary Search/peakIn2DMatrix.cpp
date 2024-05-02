#include<bits/stdc++.h>
using namespace std;
int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col) {
    int maxVal = -1, index = -1;
    for(int i=0; i<n; i++) {
        if(mat[i][col] > maxVal) {
            maxVal = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    int low = 0, high = m - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        int row = findMaxIndex(mat, n, m, mid);
        int left = mid - 1 > 0 ? mat[row][mid - 1] : -1;
        int right = mid + 1 < m ? mat[row][mid + 1] : -1;
        if(mat[row][mid] > left && mat[row][mid] > right) {
            return {row, mid};
        } else if(mat[row][mid] < left) high = mid - 1;
        else low = mid + 1;
    }
    return {-1, -1};  
}
int main() {
    vector<vector<int>> mat = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}};
    vector<int> peak = findPeakGrid(mat);
    cout<<"Peak element found at index: "<<peak[0]<<" "<<peak[1]<<endl;
    return 0;
}