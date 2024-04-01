#include<bits/stdc++.h>
using namespace std;
int getGCD(int n1, int n2) {
    if(n2==0) {
        return n1;
    }
    return getGCD(n2, n1%n2);
}
int main() {
    int number1, number2;
    cout<<"Enter first number : "<<endl;
    cin>>number1;
    cout<<"Enter second number : "<<endl;
    cin>>number2;
    cout<<"Greatest common factor of "<<number1<<" and "<<number2<<" is : "<<getGCD(number1, number2);
    return 0;
}