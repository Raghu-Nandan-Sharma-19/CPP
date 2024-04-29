#include<bits/stdc++.h>
using namespace std;
int findMax(vector<int>& v) {
    int n = v.size();
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}
long long int findHour(vector<int> &v,int banana){
    int n = v.size();
    long long int hour = 0;
    for(int i=0;i<n;i++){
        hour += ceil((double)v[i]/(double)banana);
    }
    return hour;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int low = 1,high = findMax(piles);
    while(low <= high){
        int mid = low + ((high-low)/2);
        long long int hour = findHour(piles, mid);
        if(hour <= h){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    int ans = minEatingSpeed(piles, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}