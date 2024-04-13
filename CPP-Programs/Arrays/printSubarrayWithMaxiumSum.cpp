#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(vector<int> arr, int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i=0; i<n; i++) {
        if (sum == 0) {
            start = i;
        }
        sum += arr[i];
        if(sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0) {
            sum = 0;
        }
    }
    cout<<"The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout<<" "<<arr[i]<<" ";
    }
    cout<<"]"<<endl;
    return maxi;
}
int main() {
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    vector<int> arr;
    cout << "Enter " << size << " elements: " << endl;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Maximum subarray sum: " << maxSubarraySum(arr, size) << endl;
    return 0;
}