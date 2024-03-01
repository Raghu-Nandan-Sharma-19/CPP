#include<bits/stdc++.h>
using namespace std;
int sumUsingFunctionalRecursion(int n) {
    if(n==0) return 0;
    return n+sumUsingFunctionalRecursion(n-1);
}
int main() {
    int n;
    cin>>n;
    cout<<sumUsingFunctionalRecursion(n)<<endl;
    return 0;
}