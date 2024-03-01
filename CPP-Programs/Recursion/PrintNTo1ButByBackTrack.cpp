#include<bits/stdc++.h>
using namespace std;
void printNTo1ButByBacktrack(int i, int n) {
    if(i>n) {
        return;
    }
    printNTo1ButByBacktrack(i+1, n);
    cout<<i<<endl;
}
int main() {
    int n;
    cin>>n;
    printNTo1ButByBacktrack(1, n);
    return 0;
}