#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
int removeDuplicates(vector<int> &arr, int n) {
	int i=0;
	for(int j=1; j<n; j++) {
		if(arr[j]!=arr[i]) {
			arr[i+1] = arr[j];
			i++;
		}
	}
	return (i+1);
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
    cout<<"The array is : "<<endl;
    display(arr, size);
    int newSize = removeDuplicates(arr, size);
    cout<<"The array after removing duplicates is : "<<endl;
    display(arr, newSize);
    return 0;
}