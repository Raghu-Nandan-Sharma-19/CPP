#include<bits/stdc++.h>
using namespace std;

// brute force approach
int singleNumber(vector<int> &nums) {
    // Initialize a map to store the number and frequency 
    map<int, int> mpp;

    // iterate the array 
    for(int i = 0; i < nums.size(); i++) {
        // Store the number in the map with its frequency
        mpp[nums[i]]++;
    }

    // iterate through the map
    for(auto it : mpp) {
        // check if the frequency is equal to one then return the number
        if(it.second == 1) return it.first;
    }

    // dummy statement this will never execute if we have an element which appears once in the array
    return -1;
}
int main() {
    vector<int> arr = {5, 5, 5, 2, 4, 4, 4};
    cout<<"The array is : "<<endl;
    for(auto it : arr) {
        cout<<it<<" ";
    } cout<<endl;
    cout<<"The number which appears once in the array is : "<<singleNumber(arr)<<endl;
    return 0;
}