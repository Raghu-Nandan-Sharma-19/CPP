#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    long int ans = 0, duplicate = num;
    int rem;
    
    if (num < 0) {
        cout<<"Negative number are not palindrome"<<endl;
        return 0;
    }
    while (duplicate != 0) {
        rem = duplicate % 10;
        duplicate /= 10;
        ans = ans * 10 + rem;
    }
    cout<<"Original number : "<<num<<endl;
    cout<<"Reversed number : "<<ans<<endl;
    if (num == ans) {
        cout<<"Palindrome"<<endl;
    } else {
        cout<<"Not a palindrome"<<endl;
    }

    return 0;
}