#include<bits/stdc++.h>
using namespace std;
int removeRightMostSetBit(int n) {
    return n & (n - 1);
}
int main() {
    int n = 12;
    cout<<"Before removing the right most set bit n = "<<n<<endl;
    cout<<"After removing the right most set bit n = "<<removeRightMostSetBit(n)<<endl;
    return 0;
}