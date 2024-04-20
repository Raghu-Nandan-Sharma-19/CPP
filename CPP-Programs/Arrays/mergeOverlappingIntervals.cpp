#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> arr) {
    for(auto it:arr) {
        cout<<"[ "<<it[0]<<", "<<it[1]<<" ]"<<endl;
    };
}
// // brute force solution
// vector<vector<int>> merge(vector<vector<int>>& arr) {
//     int n = arr.size(); // size of the array
//     //sort the given intervals:
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> ans;
//     for(int i=0; i<n; i++) { // select an interval:
//         int start = arr[i][0];
//         int end = arr[i][1];
//         //Skip all the merged intervals:
//         if (!ans.empty() && end <= ans.back()[1]) {
//             continue;
//         }
//         //check the rest of the intervals:
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j][0] <= end) {
//                 end = max(end, arr[j][1]);
//             }
//             else {
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
// }
vector<vector<int>> merge(vector<vector<int>> &intervals) {
    int n = intervals.size(); // size of the array

    //sort the given intervals:
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> ans;

    for (int i=0; i<n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || intervals[i][0] > ans.back()[1]) {
            ans.push_back(intervals[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}
int main() {
    int size;
    cout<<"Enter size of the array : "<<endl;
    cin>>size;
    vector<vector<int>> arr;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int start, end;
        cin>>start>>end;
        arr.push_back({start, end});
    }
    vector<vector<int>> ans = merge(arr);
    cout<<"The merged intervals are : "<<endl;
    display(ans);
    return 0;   
}