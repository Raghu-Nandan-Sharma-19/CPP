#include<bits/stdc++.h>
using namespace std;
void print1ToNLinearly(int i, int n) {
    if(i>n) {
        return;
    }
    cout<<i<<endl;
    print1ToNLinearly(i+1, n);
}
int main() {
    int n;
    cin>>n;
    print1ToNLinearly(1, n);
    return 0;
}