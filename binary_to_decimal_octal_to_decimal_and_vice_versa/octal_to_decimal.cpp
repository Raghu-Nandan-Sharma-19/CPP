#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter an octal number : ";
    cin>>num;
    int ans = 0, rem, mul = 1;
    while (num > 0)
    {
        rem = num % 10;
        num /= 10;
        ans = rem * mul + ans;
        mul *= 8;
    }
    cout<<ans;
    return 0;
}