#include<bits/stdc++.h>
using namespace std;
// // Brute force approach
// int myPow(int x, int n) {
//     int ans = 1;
//     for(int i = 1; i <= n; i++) ans *= x;
//     return ans;
// }
// Optimal approach below
int myPow(int x, int n) {
    // Initialize the result to 1
    int ans = 1;
    
    // Use a long long type for m to handle the case where n is the minimum integer value
    long long m = n;
    
    // If n is negative, make m positive
    if(m < 0) m = -m;

    // Loop until m becomes 0
    while(m > 0) {
        // If m is odd, multiply the current result by x
        if(m % 2 == 1) {
            ans *= x;
            m--; // Decrement m by 1 to make it even
        } else {
            // If m is even, square x
            x *= x;
            // Divide m by 2
            m /= 2;
        }
    }
    
    // If the original n was negative, take the reciprocal of the result
    if(n < 0) ans = 1 / ans;
    
    // Return the final result
    return ans;
}
int main() {
    int x = 2, n = 4;
    cout << x << " raise to power " << n << " is : " << myPow(x, n)<<endl;
    return 0;
}