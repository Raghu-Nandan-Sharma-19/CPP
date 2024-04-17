#include<bits/stdc++.h>
using namespace std;
// // first type --> given R and C, tell the element at that place
// int findNCR(int n, int r) {
//     long long res = 1;
//     for(int i=0; i<r; i++) {
//         res = res*(n-i);
//         res = res/(i+1);
//     }
//     return res;
// }
// int pascalTriangle(int r, int c) {
//     int element = findNCR(r-1, c-1);
//     return element;
// }
// int main() {
//     int r, c;
//     cout<<"Enter R : "<<endl;
//     cin>>r;
//     cout<<"Enter C : "<<endl;
//     cin>>c;
//     cout<<"The element at "<<r<<" and "<<c<<" is : "<<pascalTriangle(r, c)<<endl;
//     return 0;
// }
// // second type --> Print any nth row of pascal triangle
// void pascalTriangle(int n) {
//     long long ans = 1;
//     cout<<ans<<" ";
//     for(int i=1; i<n; i++) {
//         ans = ans*(n-i);
//         ans = ans/i;
//         cout<<ans<<" ";
//     } cout<<endl;
// } 
// int main() {
//     int n;
//     cout<<"Enter n : "<<endl;
//     cin>>n;
//     cout<<"The "<<n<<" row is : "<<endl;
//     pascalTriangle(n);
//     return 0;
// }
// third type --> given n and print pascal triangle
// // brute force solution
// int findnCR(int n, int r) {
//     long long res = 1;
//     for(int i=0; i<r; i++) {
//         res = res*(n-i);
//         res = res/(i+1);
//     }
//     return (int)(res);
// }
// vector<vector<int>> pascalTriangle(int n) {
//     vector<vector<int>> ans;
//     for(int i=1; i<=n; i++) {
//         vector<int> tempLst;
//         for(int j=1; j<=i; j++) {
//             tempLst.push_back(findnCR(i-1, j-1));
//         }
//         ans.push_back(tempLst);
//     }
//     return ans;
// }
// optimal solution
vector<int> generateRow(int row) {
    long long ans = 1; // to store the value of nCr
    vector<int> ansRow; // to store the row
    ansRow.push_back(1); // first element of the row
    for(int col=1; col<row; col++) { // finding the elements of the row
        ans = ans*(row-col); // finding the value of nCr
        ans = ans/col; // finding the value of nCr
        ansRow.push_back(ans); // storing the value of nCr
    }
    return ansRow; // returning the row
}
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans; // to store the pascal triangle
    for(int i=1; i<=n; i++) { // finding the rows of the pascal triangle
        ans.push_back(generateRow(i)); // storing the row
    }
    return ans; // returning the pascal triangle
}
int main() {
    int n;
    cout<<"Enter n : "<<endl;
    cin>>n;
    vector<vector<int>> ans = pascalTriangle(n);
    for(auto it:ans) {
        for(auto ele:it) {
            cout<<ele<<" ";
        } cout<<endl;
    }
    return 0;
}