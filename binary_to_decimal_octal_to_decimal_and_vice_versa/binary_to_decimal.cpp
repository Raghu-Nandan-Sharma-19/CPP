#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a binary number : ";
    cin>>num;
    int ans = 0, rem, mul = 1;
    cout<<num<<" in decimal is : ";
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
    cout<<ans<<endl;   
    return 0;
}