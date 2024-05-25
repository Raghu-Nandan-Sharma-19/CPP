#include<bits/stdc++.h>
using namespace std;
bool isOddOrEven(int n) {
    if(n & 1) {
        return true;
    }
    return false;
}
int main() {
    int n = 5;
    if(isOddOrEven(n) == true) {
        cout<<n<<" is an odd number"<<endl;
    } else {
        cout<<n<<" is an even number"<<endl;
    }
    return 0;
}