#include<bits/stdc++.h>
using namespace std;
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
    vector<int> ans(queries, 0);
    while(queries) {
        int c = 0;
        for(int i = indices[queries-1]; i < arr.size(); i++) {
            if(arr[i] > arr[indices[queries-1]]) {
                c++;
            }
        }
        ans[queries - 1] = c;
        queries--;
    }
    return ans;
}
int main() {
    int n = 5;
    vector<int> arr = {3, 4, 2, 7, 5};
    int queries = 2;
    vector<int> indices = {0, 2};
    vector<int> res = count_NGE(n, arr, queries, indices);
    for(int i : res) {
        cout << i << " ";
    }
    return 0;
}