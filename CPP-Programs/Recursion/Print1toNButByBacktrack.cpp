#include<bits/stdc++.h>
using namespace std;
void print1ToNByBacktrack(int i, int n) {
    if(i<1) {
        return;
    }
    print1ToNByBacktrack(i-1, n);
    cout<<i<<endl;
}
int main() {
    int n;
    cin>>n;
    print1ToNByBacktrack(n, n);
    return 0;
}