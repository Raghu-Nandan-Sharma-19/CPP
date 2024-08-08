#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    int rem, ans = 0, mul = 1;
    cout<<num<<" in octal is : ";
    for(int count = num; count > 0; count--)
    {
        rem = num % 8;
        num /= 8;
        ans = rem * mul + ans;
        mul *= 10;
    }
    cout<<ans<<endl;
    return 0;
}