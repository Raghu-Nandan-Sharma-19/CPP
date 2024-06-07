#include<bits/stdc++.h>
using namespace std;
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;
    s.push(-1);


    vector<int> ans(n);

    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while(s.top()>= curr) {
            s.pop();
        }
        // ans is stack ka top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}
int main() {
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();
    vector<int> res = nextSmallerElement(arr, n);
    for(int i : res) {
        cout << i << " ";
    }
    return 0;
}