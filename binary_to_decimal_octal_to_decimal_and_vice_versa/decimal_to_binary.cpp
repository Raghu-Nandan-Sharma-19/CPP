#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter any number : ";
    cin>>num;
    int rem, ans = 0, mul = 1;
    cout<<num<<" in binary is : ";
    while (num > 0)
    {
        // remainder
        rem = num & 1;
        // quotient
        num /= 2;
        // answer
        ans = rem * mul + ans;
        // multiplier
        mul *= 10;
    }
    cout<<ans<<endl;
    return 0;
}