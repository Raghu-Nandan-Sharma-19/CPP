#include<bits/stdc++.h>
using namespace std;
int getLongestSubarray(vector<int>& a, long long k) {
    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i=0; i<a.size(); i++) {
        sum+=a[i];
        if(sum==k) {
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum-k;
        if(preSumMap.find(rem)!=preSumMap.end()) {
            int len = i-preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(preSumMap.find(sum)==preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
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
    int k;
    cout<<"Enter k : "<<endl;
    cin>>k;
    cout<<"The length of the longest subarray with sum k(positives and negatives) is : "<<getLongestSubarray(arr, k)<<endl;
    return 0;
}