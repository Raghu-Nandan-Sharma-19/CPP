#include<bits/stdc++.h>
using namespace std;
// Write a program which takes input of age and prints you are adult or not
int main() {
    int age;
    cout<<"Enter your age : ";
    cin>>age;
    if(age>=18) {
        cout<<"Adult";
    } else {
        cout<<"Not adult";
    }
    return 0;
}