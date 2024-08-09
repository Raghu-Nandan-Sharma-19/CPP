#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    if (num == 0) cout<<"Complement of "<<num<<" is : "<<1<<endl;
    int ans = 0, rem, mul = 1, dup = num;

    while (dup) {
        rem = dup % 2;
        rem ^= 1;
        dup /= 2;
        ans = ans + rem * mul;
        mul *= 2;
    }
    cout<<"Complement of "<<num<<" is : "<<ans<<endl;
    
    return 0;
}