// // Brute force approach
// int divide(int dividend, int divisor) {
//     int sum = 0, cnt = 0;
//     while(sum + divisor <= dividend) {
//         cnt++;
//         sum += divisor;
//     }
//     return cnt;
// }
// Optimal solution
int divide(int dividend, int divisor) {
    // If dividend and divisor are equal, the result is 1
    if(dividend == divisor) return 1;
    // Determine the sign of the result
    bool sign = true;
    if(dividend >= 0 && divisor < 0) sign = false;
    if(dividend < 0 && divisor > 0) sign = false;
    // Use long to handle overflow and take the absolute values of dividend and divisor
    long n = abs(dividend), d = abs(divisor), quotient = 0;
    divisor = abs(divisor);
    // Perform division using bit manipulation
    while(n >= d) {
        int cnt = 0;
        // Find the highest power of 2 multiplier for the divisor that is less than or equal to the dividend
        while(n >= (d<<(cnt+1))) {
            cnt += 1;
        }
        // Add the power of 2 multiplier to the quotient
        quotient += 1<<cnt;
        // Subtract the corresponding value from the dividend
        n -= (d<<cnt);
    }
    // Handle overflow cases
    if(quotient == 1<<31 && sign == true) return INT_MAX;
    if(quotient == 1<<31 && sign == false) return INT_MIN;
    // Return the result with the correct sign
    return sign ? quotient : -quotient;
}