#include<bits/stdc++.h>
using namespace std;
bool checkIthBit(int n, int i) {
    // Shift the number 1 left by i positions to create a mask
    // where only the ith bit is set (1 << i).
    // Perform a bitwise AND with n to check if the ith bit in n is set.
    // If the result is non-zero, the ith bit is set; otherwise, it is not set.
    return n & (1 << i);
}
int main() {
    int n = 13;
    int i = 2;
    if(checkIthBit(n, i) == true) {
        cout<<"The "<<i<<" bit is set"<<endl;
    } else {
        cout<<"The "<<i<<" bit is not set"<<endl;
    }
    return 0;
}