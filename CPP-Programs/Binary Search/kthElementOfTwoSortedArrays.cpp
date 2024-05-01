#include<bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &a, vector<int>& b, int n1, int n2, int k) {
    if (n1 > n2) return kthElement(b, a, n2, n1, k);
    int n = n1 + n2; 
    int left = k; 
    int low = max(k - n2, 0), high = min(k, n1);
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        }
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement
}
int main() {
    vector<int> arr1 = {2,3,6,7,9};
    vector<int> arr2 = {1,4,8,10};
    int m = arr1.size();
    int n = arr2.size();
    int k = 5;
    cout<<"The element at the kth position in the final sorted array is "<<kthElement(arr1,arr2,m,n,k);
    return 0;
}