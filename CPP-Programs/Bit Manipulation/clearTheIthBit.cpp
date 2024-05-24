#include<bits/stdc++.h>
using namespace std;
int clearIthBit(int n, int i) {
    return n & (~(1 << i));
}
int main() {
    int n = 13, i = 2;
    cout<<"Before clearing the "<<i<<" bit n = "<<n<<endl;
    cout<<"After clearing the "<<i<<" bit n = "<<clearIthBit(n, i)<<endl;
    return 0;
}