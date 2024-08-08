#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter any number : ";
    cin>>num;
    int rem, ans = 0, mul = 1;
    while (num > 0)
    {
        // remainder
        rem = num % 2;
        // quotient
        num = num / 2;
        // answer
        ans = rem * mul + ans;
        // multiplier
        mul = mul * 10;
    }
    cout<<num<<" in binary is : "<<ans<<endl;
    return 0;
}