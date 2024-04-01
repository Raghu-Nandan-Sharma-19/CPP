#include<bits/stdc++.h>
using namespace std;
bool isPrime(int N) {
    for (int i = 2; i < sqrt(N); i++) {
        if (N % i == 0) {
            return false;
        }
    }
    return true;
}
int main() {
    int number;
    cout<<"Enter any number : "<<endl;
    cin>>number;
    bool ans = isPrime(number);
    if (number != 1 && ans == true) {
        cout << "Prime Number";
    } else {
        cout << "Non Prime Number";
    }
    return 0;
}