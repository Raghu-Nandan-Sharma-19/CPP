#include<bits/stdc++.h>
using namespace std;
int setIthBit(int n, int i) {
    return n | (1 << i);
}
int main() {
    int n = 9, i = 2;
    cout<<"Before setting the "<<i<<" bit n = "<<n<<endl;
    cout<<"After setting the "<<i<<" bit n = "<<setIthBit(n, i)<<endl;
    return 0;
}