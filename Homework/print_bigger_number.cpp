#include<bits/stdc++.h>
using namespace std;
int main() {
    int num1, num2;
    cout<<"Enter first number : ";
    cin>>num1;
    cout<<"Enter second number : ";
    cin>>num2;
    
    if(num1>num2) {
        cout<<num1<<endl;
    } else if(num1<num2) {
        cout<<num2<<endl;
    } else {
        cout<<"Don't enter same numbers."<<endl;
    }
    return 0;
}