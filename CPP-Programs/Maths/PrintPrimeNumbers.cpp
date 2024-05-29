#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {  
        if(n % i == 0) return false;
    }
    return true;
}
void printPrimes(int n) {
    for(int i = 2; i <= n; i++) {
        if(isPrime(i) == true) cout<<i<<" ";
    } cout<<endl;
}
int main() {
    int n = 10;
    cout<<"All prime numbers till "<<" are : "<<endl;
    printPrimes(n);
    return 0;
}