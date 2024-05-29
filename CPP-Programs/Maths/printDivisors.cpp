#include<bits/stdc++.h>
using namespace std;
void printDivisors(int n) {
    // Stack to hold the larger divisors in reverse order
    stack<int> ans;
    
    // Loop from 1 to sqrt(n) to find divisors
    for(int i = 1; i * i <= n; i++) {
        // If i is a divisor of n
        if(n % i == 0) {
            // Print the divisor
            cout << i << " ";
            // If n / i is not the same as i, push it to the stack
            if(n / i != i) ans.push(n / i);
        }
    }
    
    // Print the larger divisors from the stack
    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}
int main() {
    int n = 36;
    cout<<"Divisors of "<<n<<" are : "<<endl;
    printDivisors(n);
    return 0;
}