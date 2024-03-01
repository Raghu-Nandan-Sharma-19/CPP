#include<bits/stdc++.h>
using namespace std;
void printNTo1(int i, int n) {
    if(i<1) {
        return;
    }
    cout<<i<<endl;
    printNTo1(i-1, 1);
}
int main() {
    int n;
    cin>>n;
    printNTo1(n, n);
    return 0;
}