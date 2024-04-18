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
// // brute force solution --> O(n^4)
// vector<vector<int>> fourSum(vector<int> &nums, int target) {
//     int n = nums.size(); // size of the array
//     set<vector<int>> st; // set to store the quadruplets
//     for(int i=0; i<n; i++) { // loop through the array
//         for(int j=i+1; j<n; j++) { // loop through the array
//             for(int k=j+1; k<n; k++) { // loop through the array
//                 for(int l=k+1; l<n; l++) { // loop through the array
//                     long long sum = nums[i] + nums[j];
//                     sum += nums[k];
//                     sum += nums[l];
//                     if(sum == target) {
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end()); // store the set elements in a vector
//     return ans; // return the vector
// }
// // better solution --> O(n^3)
// vector<vector<int>> fourSum(vector<int> &nums, int target) {
//     int n = nums.size(); // size of the array
//     set<vector<int>> st; // set to store the quadruplets
//     for(int i=0; i<n; i++) { // loop through the array
//         for(int j=i+1; j<n; j++) { // loop through the array
//             set<long long> hashSet; // set to store the elements
//             for(int k=j+1; k<n; k++) { // loop through the array
//                 long long sum = nums[i]+nums[j]; // sum of the two elements
//                 sum += nums[k]; // sum of the three elements
//                 long long fourth = target-(sum); // fourth element
//                 if(hashSet.find(fourth) != hashSet.end()) { // if the fourth element is found in the set
//                     vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth}; // store the elements in a vector
//                     sort(temp.begin(), temp.end()); // sort the vector
//                     st.insert(temp); // insert the vector in the set
//                 }
//                 hashSet.insert(nums[k]); // insert the element in the set
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin(), st.end()); // store the set elements in a vector
//     return ans; // return the vector
// }
// optimal solution --> 0(n^3)
vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int n = nums.size(); // size of the array
    sort(nums.begin(), nums.end()); // sort the array
    vector<vector<int>> ans; // vector to store the quadruplets
    for(int i=0; i<n; i++) { // loop through the array
        if(i > 0 && nums[i] == nums[i-1]) continue; // if the current element is equal to the previous element
        for(int j=i+1; j<n; j++) { // loop through the array
            if(j > i && nums[j] == nums[j-1]) continue; // if the current element is equal to the previous element
            int k = j+1; // left pointer
            int l = n-1; // right pointer
            while(k<l) { // loop until left pointer is less than right pointer
                long long sum = nums[i]; // sum of the four elements
                sum += nums[j]; // sum of the four elements
                sum += nums[k]; // sum of the four elements
                sum += nums[l]; // sum of the four elements
                if(sum == target) { // if the sum is equal to the target sum
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]}; // store the elements in a vector
                    ans.push_back(temp); // insert the vector in the vector
                    k++; // increment the left pointer
                    l--; // decrement the right pointer
                    // loop until left pointer is less than right pointer and the current element is equal to the previous element
                    while(k<l && nums[k] == nums[k-1]) k++; 
                    // loop until left pointer is less than right pointer and the current element is equal to the previous element
                    while(k<l && nums[l] == nums[l+1]) l--; 
                } else if(sum < target) k++; // if the sum is less than the target sum increment the left pointer
                else l--; // if the sum is greater than the target sum decrement the right pointer
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
    int targetSum;
    cout<<"Enter target sum : "<<endl;
    cin>>targetSum;
    cout<<"The quadruplets in array which add upto give sum = "<<targetSum<<" are : "<<endl;
    vector<vector<int>> ans = fourSum(arr, targetSum);
    display(ans);
    return 0;
}