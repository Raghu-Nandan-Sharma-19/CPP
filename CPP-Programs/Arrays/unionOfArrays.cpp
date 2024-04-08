#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// vector<int> unionOfArrays(vector<int> &arr1, vector<int> arr2, int n1, int n2) {
//     set<int> st;
//     for(int i=0; i<n1; i++) {
//         st.insert(arr1[i]);
//     }
//     for(int i=0; i<n2; i++) {
//         st.insert(arr2[i]);
//     }
//     vector<int> unionArray;
//     for(auto it:st) {
//         unionArray.push_back(it);
//     }
//     return unionArray;
// }
// Optimal approach below
vector<int> unionOfArrays(vector<int> &arr1, vector<int> &arr2, int n1, int n2) {
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i<n1 && j<n2) {
        if(arr1[i]<=arr2[j]) {
            if(unionArr.size()==0 || unionArr.back()!=arr1[i]) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        } else {
            if(unionArr.size()==0 || unionArr.back()!=arr2[j]) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j<n2) {
        if(unionArr.size()==0 || unionArr.back()!=arr2[j]) {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }
    while(i<n1) {
        if(unionArr.size()==0 || unionArr.back()!=arr1[i]) {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }
    return unionArr;
}
int main() {
    int size1;
    cout<<"Enter the size of array 1 : "<<endl;
    cin>>size1;
    vector<int> arr1;
    cout<<"Enter "<<size1<<" elements in array 1 : "<<endl;
    for(int i=0; i<size1; i++) {
        int x;
        cin>>x;
        arr1.push_back(x);
    }
    int size2;
    cout<<"Enter the size of array 2 : "<<endl;
    cin>>size2;
    vector<int> arr2;
    cout<<"Enter "<<size2<<" elements in array 2 : "<<endl;
    for(int i=0; i<size2; i++) {
        int y;
        cin>>y;
        arr2.push_back(y);
    }
    vector<int> unionArray = unionOfArrays(arr1, arr2, size1, size2);
    cout<<"Union of the arrays is : "<<endl;
    display(unionArray, unionArray.size());
    return 0;
}