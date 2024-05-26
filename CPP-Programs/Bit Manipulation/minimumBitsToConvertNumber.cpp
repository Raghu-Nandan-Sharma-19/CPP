#include<bits/stdc++.h>
using namespace std;
int minBitFlips(int start, int goal) {
    // Calculate the XOR of start and goal.
    // XOR gives a binary number where each bit is 1 if the corresponding bits of start and goal are different, otherwise 0.
    int num = start ^ goal;
    // Initialize a counter to count the number of 1s in the XOR result.
    // Each 1 represents a bit that needs to be flipped to convert start to goal.
    int cnt = 0;
    // Loop until num becomes 0.
    // This loop will count the number of 1s in the binary representation of num.
    while(num) {
        // Perform a bitwise AND between num and (num - 1).
        // This operation removes the rightmost 1 bit from num.
        num = num & (num - 1);
        // Increment the counter since we've found and removed a 1 bit.
        cnt++;
    }
    // Return the total count of bit flips needed.
    return cnt;
}
int main() {
    int start = 3, goal = 4;
    cout<<"The minimum bits required to convert "<<start<<" to "<<goal<<" is : "<<minBitFlips(start, goal)<<endl;
    return 0;
}