#include<bits/stdc++.h>
using namespace std;
int findFLoor(vector<int> &arr, int n, int x) {
	int ans = -1; // if no floor is present then return -1
	int low = 0, high = n-1; // low and high pointers
	while(low<=high) { // binary search
		int mid = (low+high)/2; // mid element
		if(arr[mid] <= x) { // if mid element is less than or equal to x then update ans and move to right side
			ans = arr[mid]; // update ans
			low = mid+1; // move to right side
		} else { // if mid element is greater than x then move to left side
			high = mid-1; // move to left side
		}
	}
	return ans; // return ans
}
int findCeil(vector<int> &arr, int n, int x) {
	int ans = -1; // if no ceil is present then return -1
	int low = 0, high = n-1; // low and high pointers
	while(low<=high) { // binary search
		int mid = (low+high)/2; // mid element
		if(arr[mid] >= x) { // if mid element is greater than or equal to x then update ans and move to left side
			ans = arr[mid]; // update ans
			high = mid-1; // move to left side
		} else {
			low = mid+1; // move to right side
		}
	}
	return ans; // return ans
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
    sort(a.begin(), a.end()); // sort the array
	int floor = findFLoor(a, n, x); // find floor
	int ceil = findCeil(a, n, x); // find ceil
	return make_pair(floor, ceil); // return pair of floor and ceil
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
	int x;
	cout<<"Enter the element to find floor and ceil: "<<endl;
	cin>>x;
	pair<int, int> ans = getFloorAndCeil(arr, size, x);
	cout<<"Floor: "<<ans.first<<endl;
	cout<<"Ceil: "<<ans.second<<endl;
	return 0;
}