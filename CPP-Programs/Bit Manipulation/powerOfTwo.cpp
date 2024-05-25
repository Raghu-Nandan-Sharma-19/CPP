#include<bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int n) {
    if(n > 0 && (n & (n - 1)) == 0) {
        return true;
    }
    return false;
}
int main() {
    int n = 16;
    if(isPowerOfTwo(n) == true) {
        cout<<n<<" is power of two"<<endl;
    } else {
        cout<<n<<" is not power of two"<<endl;
    }
    return 0;
}