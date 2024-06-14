#include<bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &M, int n) { 
    stack<int> st;
    for(int i = 0; i < n; i++) st.push(i);
    //find a potential celebrity
    while(st.size() > 1) {
        int row = st.top();
        st.pop();
        int col = st.top();
        st.pop();
        if(M[row][col] == 1) st.push(col);
        else st.push(row);
    }

    //verify that celebrity
    int x = st.top();
    st.pop();

    for(int i = 0; i < n; i++) {
        if(i == x) continue;
        if(M[x][i] == 1) return -1;
    }

    for(int i = 0; i < n; i++) {
        if(i == x) continue;
        if(M[i][x] == 0) return -1;
    }

    return x;
}
int main() {
    vector<vector<int>> M = {{0, 0, 1, 0},
                              {0, 0, 1, 0},
                              {0, 0, 0, 0},
                              {0, 0, 1, 0}};
    int n = 4;
    cout << "Celebrity: " << celebrity(M, n) << endl;
    return 0;
}