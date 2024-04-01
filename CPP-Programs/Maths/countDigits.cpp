#include<bits/stdc++.h>
using namespace std;
int countDigits(int number) {
    int count = 0;
    while(number!=0) {
        // int lastDigit = number%10;
        count++;
        number/=10;
    }
    return count;
}
int main() {
    int number;
    cout<<"Enter any number : "<<endl;
    cin>>number;
    cout<<"Number of digits : "<<countDigits(number)<<endl;
    return 0;
}