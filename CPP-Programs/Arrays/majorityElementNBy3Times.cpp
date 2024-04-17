#include<bits/stdc++.h>
using namespace std;
// // brute force solution
// vector<int> majorityElement(vector<int> v) {
// 	vector<int> list;  // list to store the elements that appears more than N/3 times
// 	for(int i=0; i<v.size(); i++) { // finding the elements that appears more than N/3 times
// 		int cnt = 0; // count of the element
// 		if(list.size() == 0 || list[0] != v[i]) { // checking if the element is already in the list
// 			for(int j=0; j<v.size(); j++) { // finding the elements that appears more than N/3 times
// 				if(v[j] == v[i]) { // checking if the element is equal to the current element
// 					cnt++; // incrementing the count of the element
// 				} 
// 			}
// 			if(cnt > v.size()/3) list.push_back(v[i]); // checking if the element appears more than N/3 times
// 			if(list.size() == v.size()/3) break;  // checking if the list size is equal to N/3
// 		}
// 	}
// 	return list; // returning the list
// }
// //  better solution
// vector<int> majorityElement(vector<int> v) {
// 	vector<int> list; // list to store the elements that appears more than N/3 times
// 	map<int, int> mpp; // map to store the elements
// 	int min = (v.size()/3)+1; // minimum count of the element
// 	for(int i=0; i<v.size(); i++) { // finding the elements that appears more than N/3 times
// 		mpp[v[i]]++; // storing the elements
// 		if(mpp[v[i]] == min) { // checking if the element appears more than N/3 times
// 			list.push_back(v[i]); // adding the element to the list
// 		}
// 	}
// 	return list; // returning the list
// }
// optimal solution
vector<int> majorityElement(vector<int> v) {
	int n = v.size(); // size 
	int cnt1 = 0, cnt2 = 0, el1, el2; 
	for(int i=0; i<n; i++) { // finding the elements that appears more than N/3 times
		// checking if the count of the element is zero and the element is not equal to the second element
		if(cnt1 == 0 && v[i] != el2) { 
			cnt1 = 1; // incrementing the count of the element
			el1 = v[i]; // storing the element

		} else if(cnt2 == 0 && v[i] != el1) { // checking if the count of the element is zero and the element is not equal to the first element
			cnt2 = 1; // incrementing the count of the element
			el2 = v[i]; // storing the element
		} else if(el1 == v[i]) cnt1++; // checking if the element is equal to the first element
		else if(el2 == v[i]) cnt2++; // checking if the element is equal to the second element
		else { // if the element is not equal to the first and second element
			cnt1--; // decrementing the count of the first element
			cnt2--; // decrementing the count of the second element
		}
	}
	vector<int> list; // list to store the elements that appears more than N/3 times
	cnt1 = 0, cnt2 = 0; // resetting the count of the elements
	for(int i=0; i<n; i++) { // finding the elements that appears more than N/3 times
		if(el1 == v[i]) cnt1++; // checking if the element is equal to the first element
		if(el2 == v[i]) cnt2++; // checking if the element is equal to the second element
	}
	int mini = (int)(n/3)+1; // minimum count of the element
	if(cnt1 >= mini) list.push_back(el1); // checking if the count of the first element is greater than or equal to the minimum count
	if(cnt2 >= mini) list.push_back(el2); // checking if the count of the second element is greater than or equal to the minimum count
	sort(list.begin(), list.end()); // sorting the list
	return list; // returning the list
}
int main() {
    int size;
    cin>>size;
    vector<int> arr;
    for(int i=0; i<size; i++) {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    vector<int> ans = majorityElement(arr);
    cout<<"The elements that appears more than N/3 times are : "<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    } cout<<endl;
    return 0;
}