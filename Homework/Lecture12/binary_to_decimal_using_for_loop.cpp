#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a binary number : ";
    cin>>num;
    int ans = 0, rem, mul = 1;
    cout<<num<<" in decimal is : ";
    for (int count = num; count > 0; count--)
    {
        rem = num % 10;
        num /= 10;
        ans = rem * mul + ans;
        mul *= 2;
    }
    cout<<ans<<endl;
    return 0;
}