#include<bits/stdc++.h>
using namespace std;
void swap(int a, int b) {
    // Step 1: XOR a with b and store the result in a
    a = a ^ b; // a now holds the value of a XOR b
    // Step 2: XOR the new a (which is a XOR b) with b and store the result in b
    b = a ^ b; // b now holds the original value of a
    // Step 3: XOR the new a (which is a XOR b) with the new b (which is the original a) and store the result in a
    a = a ^ b; // a now holds the original value of b
    // Print the swapped values
    cout << "a = " << a << ", b = " << b << endl;
}
int main() {
    int a = 6, b = 5;
    cout<<"Before swapping : "<<endl<<"a = "<<a<<", b = "<<b<<endl;
    cout<<"After swapping : "<<endl;
    swap(a, b);
    return 0;
}