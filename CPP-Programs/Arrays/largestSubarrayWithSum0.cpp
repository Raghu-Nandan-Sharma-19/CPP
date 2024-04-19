#include<bits/stdc++.h>
using namespace std;
// optimal solution 
int getLongestZeroSumSubarrayLength(vector<int> &arr) {
	int n = arr.size(); // size of the array
	unordered_map<int, int> mpp; // map to store the sum and the index
	int maxi = 0, sum = 0; // initialize the variables
	for(int i=0; i<n; i++) { // loop through the array
		sum += arr[i]; // add the element to the sum
		if(sum == 0) { // if the sum is 0
			maxi = i+1; // update the maximum length
		} else { // if the sum is not 0
			if(mpp.find(sum) != mpp.end()) { // if the sum is found in the map
				maxi = max(maxi, i-mpp[sum]); // update the maximum length
			} else { // if the sum is not found in the map
				mpp[sum] = i; // store the sum and the index
			}
		}
	}
	return maxi; // return the maximum length
}
int main() {
    int size;
    cout<<"Enter the size of the array: "<<endl;
    cin>>size;
    vector<int> arr;
    cout<<"Enter "<<size<<" elements : "<<endl;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<"The length of the longest subarray with sum 0 is: "<<getLongestZeroSumSubarrayLength(arr)<<endl;
    return 0;
}