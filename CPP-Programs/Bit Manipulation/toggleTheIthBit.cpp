#include<bits/stdc++.h>
using namespace std;
int toggleIthBit(int n, int i) {
    return n ^ (1 << i);
}
int main() {
    int n = 13, i = 2;
    cout<<"Before toggling the "<<i<<" bit n = "<<n<<endl;
    cout<<"After toggling the "<<i<<" bit n = "<<toggleIthBit(n, i)<<endl;
    return 0;
}