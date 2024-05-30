#include<bits/stdc++.h>
using namespace std;
// // Brute force solution
// bool isPrime(int n) {
//     for(int i = 2; i * i <= n; i++) {  
//         if(n % i == 0) return false;
//     }
//     return true;
// }
// void printPrimes(int n) {
//     for(int i = 2; i <= n; i++) {
//         if(isPrime(i) == true) cout<<i<<" ";
//     } cout<<endl;
// }
// Optimal solution --> using sieve of eratosthenes
void printPrimes(int n) {
    // Create a vector to store prime status for each number from 0 to n
    vector<int> primes(n + 1);

    // Initialize all numbers as potential primes (1 means prime, 0 means not prime)
    for(int i = 2; i < n; i++) primes[i] = 1;

    // Sieve of Eratosthenes algorithm to find all primes up to n
    for(int i = 2; i * i <= n; i++) {
        // If i is a prime
        if(primes[i] == 1) {
            // Mark all multiples of i as not prime
            for(int j = i * i; j <= n; j += i) primes[j] = 0;
        }
    }

    // Print all prime numbers less than n
    for(int i = 2; i < n; i++) {
        if(primes[i] == 1) cout << i << " ";
    }
}
int main() {
    int n = 10;
    cout << "All prime numbers till "<< n <<" are : " << endl;
    printPrimes(n);
    return 0;
}