#include<bits/stdc++.h>
using namespace std;
int floorSqrt(int n) {
    // initialize low as 1 and high as the given number
    int low = 1, high = n;
    // apply binary search
    while(low <= high) {
        // take a mid number
        long long mid = (low+high)/2;
        // if square of mid is less than or equal to the number
        if((mid * mid) <= n) {
            // increment the low to mid + 1
            low = mid+1;
        } else {
            // the mid is greater than the number, you have to decrement high to mid - 1
            high = mid-1;
        }
    }
    // you can return the high as it contains the square root of the number
    return high;
}
int main() {
    int number;
    cout<<"Enter a number : "<<endl;
    cin>>number;
    cout<<"Square root of "<<number<<" is : "<<floorSqrt(number)<<endl;
    return 0;
}