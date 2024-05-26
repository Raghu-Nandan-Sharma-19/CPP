#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> powerSet(vector<int> &nums) {
    // Calculate the total number of subsets possible, which is 2^n where n is the size of nums
    int subsets = 1 << nums.size();
    // Initialize the answer vector to hold all subsets
    vector<vector<int>> ans;
    
    // Iterate through each possible subset
    for(int num = 0; num < subsets; num++) {
        // Temporary list to store the current subset
        vector<int> list;
        
        // Check each bit position in the current number 'num'
        for(int i = 0; i < nums.size(); i++) {
            // If the i-th bit is set, include nums[i] in the current subset
            if(num & (1 << i)) list.push_back(nums[i]);
        }
        
        // Add the current subset to the answer vector
        ans.push_back(list);
    }
    
    // Return the complete list of subsets
    return ans;
}
int main() {
    vector<int> arr = {1, 2, 3};
    cout<<"The array is : "<<endl;
    for(auto i: arr) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"The power set of the array is : "<<endl;
    vector<vector<int>> ans = powerSet(arr);
    for(auto i: ans) {
        cout<<"[ ";
        for(auto j: i) {
            cout<<j<<" ";
        }
        cout<<"] ";
    }
    return 0;
}