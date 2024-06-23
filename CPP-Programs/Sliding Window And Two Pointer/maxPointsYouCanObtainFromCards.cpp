#include<bits/stdc++.h>
using namespace std;
int maxScore(vector<int>& cardPoints, int k) {
    int lSum = 0, rSum = 0, maxSum = 0;
    for(int i = 0; i < k; i++) lSum = lSum + cardPoints[i];
    maxSum = lSum;
    int rIndex = cardPoints.size() - 1;
    for(int i = k - 1; i >= 0; i--) {
        lSum = lSum - cardPoints[i];
        rSum = rSum + cardPoints[rIndex];
        rIndex = rIndex - 1;
        maxSum = max(maxSum, lSum + rSum);
    }
    return maxSum;
}
int main() {
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 4;
    cout<<maxScore(arr, k)<<endl;
    return 0;
}