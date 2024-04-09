#include<bits/stdc++.h>
using namespace std;
int findMissingNumber(vector<int> &arr, int n){
    // int sum1 = (n*(n+1))/2;
    // int sum2 = 0;
    // for(int i=0; i<n-1; i++) {
    //     sum2+=arr[i];
    // }
    // int missingNumber = sum1-sum2;
    // return missingNumber;
    // using XOR
    int xor1 = 0;
    int xor2 = 0;
    for(int i=0; i<n-1; i++) {
        xor2 = xor2^arr[i];
        xor1 = xor1^(i+1);
    }
    xor1 = xor1^n;
    return xor1^xor2;
}
int main() {
    int size = 5;
    vector<int> arr = {1, 2, 4, 5};
    cout<<"Missing number is : "<<findMissingNumber(arr, size)<<endl;
    return 0;
}