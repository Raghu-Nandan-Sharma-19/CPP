#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<int>> arr) {
    for(auto it:arr) { // loop through the array
        cout<<"[ "; // print [
        for(auto i:it) { // loop through the array
            cout<<i<<" "; // print the element
        } cout<<"]"; // print ]
    } cout<<endl; // print new line
}
// // brute force approach --> O(n^3)
// vector<vector<int>> threeSum(vector<int> &nums) {
//     int n = nums.size(); // size of the array
//     set<vector<int>> st; // set to store the triplets
//     for(int i=0; i<n; i++) { // loop through the array
//         for(int j=i+1; j<n; j++) { // loop through the array
//             for(int k=j+1; k<n; k++) { // loop through the array
//                 if(nums[i] + nums[j] + nums[k] == 0) { // if the sum of the three elements is equal to 0
//                     vector<int> temp = {nums[i], nums[j], nums[k]}; // store the elements in a vector
//                     sort(temp.begin(), temp.end()); // sort the vector
//                     st.insert(temp); // insert the vector in the set
//                 } 
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end()); // store the set elements in a vector
//     return ans; // return the vector
// }
// // better solution below --> O(n^2)
// vector<vector<int>> threeSum(vector<int> &nums) {
//     int n = nums.size(); // size of the array
//     set<vector<int>> st; // set to store the triplets
//     for(int i=0; i<n; i++) { // loop through the array
//         set<int> hashSet; // set to store the elements
//         for(int j=i+1; j<n; j++) { // loop through the array
//             int third = -(nums[i]+nums[j]); // third element
//             if(hashSet.find(third) != hashSet.end()) { // if the third element is found in the set
//                 vector<int> temp = {nums[i], nums[j], third}; // store the elements in a vector
//                 sort(temp.begin(), temp.end()); // sort the vector
//                 st.insert(temp); // insert the vector in the set
//             }
//             hashSet.insert(nums[j]); // insert the element in the set
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end()); // store the set elements in a vector
//     return ans; // return the vector
// }
// Optimal solution below  --> O(nlogn) + O(n*n)
vector<vector<int>> threeSum(vector<int> &nums) {
    int n = nums.size(); // size of the array
    vector<vector<int>> ans; // vector to store the triplets
    sort(nums.begin(), nums.end()); // sort the array
    for(int i=0; i<n; i++) { // loop through the array
        if(i > 0 && nums[i] == nums[i-1]) { // if the current element is equal to the previous element
            continue; // skip the current iteration
        }
        int j = i+1, k = n-1; // two pointers
        while(j<k) { // loop until j is less than k
            int sum = nums[i]+nums[j]+nums[k]; // sum of the three elements
            if(sum < 0) { // if the sum is less than 0
                j++; // increment the left pointer
            } else if(sum > 0) { // if the sum is greater than 0
                k--; // decrement the right pointer
            } else { // if the sum is equal to 0
                vector<int> temp = {nums[i], nums[j], nums[k]}; // store the elements in a vector
                ans.push_back(temp); // insert the vector in the vector
                j++; // increment the left pointer
                k--; // decrement the right pointer
                // loop until j is less than k and the current element is equal to the previous element
                while(j<k && nums[j] == nums[j-1]) { 
                    j++;  // increment the left pointer
                }
                // loop until j is less than k and the current element is equal to the previous element
                while(j<k && nums[k] == nums[k+1]) {
                    k--;  // decrement the right pointer
                }
            }
        }
    }
    return ans; // return the vector
}
int main() {
    int size;
    cout<<"Enter the size of the array : "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"The triplets which sum up to give sum = 0 are : "<<endl;
    vector<vector<int>> ans = threeSum(arr);
    display(ans);
    return 0;
}