#include<bits/stdc++.h>
using namespace std;
vector<int> primeFactors(int N) {
    vector<int> list;
    
    // Loop from 2 to the square root of N to find factors
    for(int i = 2; i <= sqrt(N); i++) {
        // Check if i is a factor of N
        if(N % i == 0) {
            // If it is, add i to the list of prime factors
            list.push_back(i);
            // Divide N by i as long as it is divisible
            while(N % i == 0) N /= i;
        }
    }
    
    // If N is not 1 after the loop, it means N itself is a prime factor
    if(N != 1) list.push_back(N);
    
    return list;
}
int main() {
    int number = 780;
    vector<int> ans = primeFactors(number);
    cout<<"Prime factors of "<<number<<" are : "<<endl;
    for(auto it : ans) {
        cout<<it<<" ";
    } cout<<endl;
    return 0;
}