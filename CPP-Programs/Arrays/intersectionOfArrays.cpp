#include<bits/stdc++.h>
using namespace std;
void display(vector<int> arr, int n) {
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;
}
// vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2, int n1, int n2) {
//     vector<int> ans;
//     int visited[n2] = {0};
//     int j=0;
//     for(int i=0; i<n1; i++) {
//         for(j=0; j<n2; j++) {
//             if(arr1[i]==arr2[j] && visited[j]==0) {
//                 ans.push_back(arr1[i]);
//                 visited[j] = 1;
//                 break;
//             }
//         }
//         if(arr2[j]>arr1[i]) {
//             break;
//         }
//     }
//     return ans;
// }
// Optimal code below
vector<int> findIntersection(vector<int> &arr1, vector<int> &arr2, int n1, int n2) {
    vector<int> ans;
    int i = 0;
    int j = 0;
    while(i<n1 && j<n2) {
        if(arr1[i]<arr2[j]) {
            i++;
        } else if(arr2[j]<arr1[i]) {
            j++;
        } else {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans; 
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
    vector<int> intersection = findIntersection(arr1, arr2, size1, size2);
    cout<<"Intersection of the two arrays is : ";
    display(intersection, intersection.size());
    return 0;
}