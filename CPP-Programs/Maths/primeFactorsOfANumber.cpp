#include<bits/stdc++.h>
using namespace std;
// Function to perform a modified Sieve of Eratosthenes
// This sieve not only marks non-primes but also stores the smallest prime factor for each number
void mySieve(vector<int> &prime, int n) {
    // Initialize the prime vector such that prime[i] = i for all i from 1 to n
    for(int i = 1; i <= n; i++) prime[i] = i;

    // Perform the sieve
    for(int i = 2; i * i <= n; i++) {
        // If prime[i] is still i, it means i is a prime number
        if(prime[i] == i) {
            // Mark all multiples of i with i if they have not been marked by a smaller prime factor
            for(int j = i * i; j <= n; j++) {
                if(prime[j] == j) prime[j] = i;
            }
        }
    }
}

// Function to find and return the prime factors of a given number n
vector<int> findPrimeFactors(int n) {
    // Initialize a vector to store the smallest prime factors of numbers up to n
    vector<int> prime(n + 1);

    // Perform the sieve to fill the prime vector
    mySieve(prime, n);

    // Vector to store the prime factors of n
    vector<int> ans;

    // Find prime factors by repeatedly dividing n by its smallest prime factor
    while(n != 1) {
        // Add the smallest prime factor of n to the result
        ans.push_back(prime[n]);
        // Divide n by its smallest prime factor
        n /= prime[n];
    }

    return ans; // Return the list of prime factors
}
int main() {
    int n = 12;
    cout << "Prime factors of " << n << " are : " << endl;
    vector<int> ans = findPrimeFactors(n);
    for(auto it : ans) {
        cout << it << " ";
    } cout<<endl;
    return 0;
}