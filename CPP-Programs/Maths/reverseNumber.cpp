#include<bits/stdc++.h>
using namespace std;
int reverse(int number) {
    int revNum = 0;
    while(number!=0) {
        int lastDigit = number%10;
        number/=10;
        revNum = (revNum*10)+lastDigit;
    }
    return revNum;
}
int main() {
    int number;
    cout<<"Enter any number : "<<endl;
    cin>>number;
    cout<<number<<" in reverse is : "<<reverse(number)<<endl;
    return 0;
}