#include<bits/stdc++.h>
using namespace std;
// Functions are set of code which performs something for you
// Functions are used to modularise code
// Functions are used to increase readability
// Functions are used to use same code multiple times
// void --> which does not returns anything
// return
// parameterised
// Non parameterised
// Pass by value 
void printName() {
    cout<<"hey, Raghu!"<<endl;
}
void printInputName(string name) {
    cout<<"Hello, "<<name<<endl;
}
int addition(int a, int b) {
    int c = a+b;
    return c;
}
int main() {
    string name;
    getline(cin, name);
    int num1, num2;
    cin>>num1>>num2;
    printName();
    printInputName(name);
    int result = addition(num1, num2);
    cout<<result<<endl;
    int maximum = max(num1, num2);
    int minimum = min(num1, num2);
    cout<<"Maximum = "<<maximum<<endl;
    cout<<"Minimum = "<<minimum<<endl;
    return 0;
}