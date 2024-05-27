#include<bits/stdc++.h>
using namespace std;

// Function to find XOR from 0 to n
int xorr(int n) {
    // If n % 4 == 1, result is always 1
    if(n % 4 == 1) return 1;
    // If n % 4 == 2, result is always n + 1
    else if(n % 4 == 2) return n + 1;
    // If n % 4 == 3, result is always 0
    else if(n % 4 == 3) return 0;
    // If n % 4 == 0, result is always n
    else return n;
}

// Function to find XOR from l to r
int findXOR(int l, int r) {
    // XOR from l to r is calculated as XOR from 0 to r XORed with XOR from 0 to l-1
    return xorr(l - 1) ^ xorr(r);
}

int main() {
    int l = 1, r = 4;
    cout<<"After doing XOR of all numbers from "<<l<<" to "<<r<<" is : "<<findXOR(l, r)<<endl;
    return 0;
}