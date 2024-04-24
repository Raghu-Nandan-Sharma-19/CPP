#include<bits/stdc++.h>
using namespace std;
int upperBound(vector<int> arr, int n, int x) {
    int ans = n; // ans is the smallest index of element which is >= x
	// int low = 0, high = n-1; // low and high are the indices of the array
	// while(low <= high) { // if low is greater than high, then the element is not present in the array
	// 	int mid = (low+high)/2; // calculating the mid index
	// 	if(arr[mid] > x) { // if the element at mid index is greater than  the target element
	// 		ans = mid; // then update the ans to mid index
	// 		high = mid-1; // then the target element will be present in the left half of the array
	// 	} else { // if the element at mid index is less than the target element
	// 		low = mid+1; // then the target element will be present in the right half of the array
	// 	}
	// }
	// return ans; // return the smallest index of element which is >= x
    // using stl
    int ub = upper_bound(arr.begin(), arr.end(), x)-arr.begin();
	return ub;
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
    int target;
    cout<<"Enter target number : "<<endl;
    cin>>target;
    cout<<"The smallest index of element which is > "<<target<<" is : "<<upperBound(arr, size, target)<<endl;
    return 0;
}