#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cout<<"Enter an octal number : ";
    cin>>num;
    int ans = 0, rem, mul = 1;
    cout<<num<<" in binary is : ";
    while (num > 0)
    {
        rem = num % 10;
        num /= 10;
        ans = rem * mul + ans;
        mul *= 8;
    }
    int binary = 0, mul1 = 1;
    while (ans > 0)
    {
        rem = ans % 2;
        ans /= 2;
        binary += rem * mul1;
        mul1 *= 10;
    }
    cout<<binary<<endl;
    return 0;
}