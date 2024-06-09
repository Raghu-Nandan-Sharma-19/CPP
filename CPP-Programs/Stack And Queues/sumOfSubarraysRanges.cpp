#include<bits/stdc++.h>
using namespace std;
long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long res = 0;
    for(int i = 0; i < n - 1; i++){
        int maxi = nums[i], mini = nums[i];
        for(int j = i + 1; j < n; j++){
            if(nums[j] > maxi) maxi = nums[j];
            else if(nums[j] < mini) mini = nums[j];
            res += maxi - mini;
        }
    }
    return res;
}
int main() {
    int n = 5;
    vector<int> arr = {3, 4, 2, 7, 5};
    cout << subArrayRanges(arr);
    return 0;
}