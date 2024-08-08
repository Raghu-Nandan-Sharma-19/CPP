#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a binary number : ";
    cin>>num;
    int ans = 0, rem, mul = 1;
    cout<<num<<" in octal is : ";
    while (num > 0)
    {
        // remainder
        rem = num % 10;
        // quotient
        num /= 10;
        // ans
        ans = rem * mul + ans;
        // multiplier
        mul *= 2;
    }  
    int octal = 0, rem1, mul1 = 1;
    while (ans > 0)
    {
        rem1 = ans % 8;
        ans /= 8;
        octal = rem1 * mul1 + octal;
        mul1 *= 10;
    }
    cout<<octal<<endl;
    return 0;
}