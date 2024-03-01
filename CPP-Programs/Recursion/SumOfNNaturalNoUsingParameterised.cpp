#include<bits/stdc++.h>
using namespace std;
void sumUsingParameterisedRecursion(int i, int sum) {
    if(i<1) {
        cout<<sum;
        return;
    }
    sumUsingParameterisedRecursion(i-1, sum+i);
}
int main() {
    int n;
    cin>>n;
    sumUsingParameterisedRecursion(n, 0);
    return 0;
}