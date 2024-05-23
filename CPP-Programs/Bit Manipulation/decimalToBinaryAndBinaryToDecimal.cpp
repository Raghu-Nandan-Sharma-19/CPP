#include<bits/stdc++.h>
using namespace std;
// Function to convert an integer to its binary representation
string convert2Binary(int x) {
    // Initialize an empty string to store the binary representation
    string res = "";
    // Loop until x becomes zero
    while(x > 0) {
        // Check if the current bit is 1 or 0 and append the corresponding character to the result
        if(x % 2 == 1) res += "1";
        else res += "0";
        // Divide x by 2 to process the next bit
        x /= 2;
    }
    // Reverse the string to get the correct binary representation
    reverse(res.begin(), res.end());
    // Return the resulting binary string
    return res;
}
// Function to convert a binary string to its decimal representation
int convert2Decimal(string x) {
    // Get the length of the binary string
    int len = x.length();
    // Initialize variables to store the power of 2 and the resulting decimal number
    int p2 = 1; // This represents 2^0 initially
    int num = 0;
    // Loop through the binary string from the least significant bit to the most significant bit
    for(int i = len - 1; i >= 0; i--) {
        // If the current bit is '1', add the current power of 2 to the result
        if(x[i] == '1') {
            num = num + p2;
        }
        // Multiply the power of 2 by 2 for the next bit (move to the next higher power of 2)
        p2 = p2 * 2;
    }
    // Return the resulting decimal number
    return num;
}
int main() {
    int x = 13;
    cout<<x<<" in binary is : "<<convert2Binary(x)<<endl;
    string y = "1101";
    cout<<y<<" in decimal is : "<<convert2Decimal(y)<<endl;
    return 0;
}