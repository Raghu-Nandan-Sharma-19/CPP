#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& heights) {
    if(heights.size() == 1) return heights[0];
    int n = heights.size();
    stack<int> st;
    st.push(-1);
    vector<int> smallestRight(n, heights.size()-1);
    vector<int> smallestLeft(n, 0);
        
    // Calculating smallest element to the left of each element
    for(int i = 0 ; i < n; i++) {
        while(st.top() != -1 and heights[st.top()] >= heights[i]){
            st.pop();
        }
        smallestLeft[i] = st.top();
        st.push(i);
    }
        
    // Calculating smallest element to the right of each element
    stack<int> st1;
    st1.push(-1);
        
    for(int i = n - 1; i >= 0; i--) {
        while(st1.top() != -1 and heights[st1.top()] >= heights[i]) st1.pop();
        smallestRight[i] = st1.top() == (-1) ? n : st1.top();
        st1.push(i);
    }
    // Calculating Area
    int area = 0;
    for(int i = 0; i < n; i++) {
        int l = heights[i];
        int b = smallestRight[i] - smallestLeft[i] - 1;
        area = max(area, l*b);
    }
    return area;
}
int main() {
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights);
    return 0;
}