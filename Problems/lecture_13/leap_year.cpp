#include<bits/stdc++.h>
using namespace std;
int main() {
    int year;
    cout<<"Enter year : ";
    cin>>year;
    
    // if the year is divisible by 400 it is a leap year
    if (year % 400 == 0) {
        cout<<"Leap year"<<endl;
    } else if (year % 4 == 0 && year % 100 != 0) {
        // if the year is divisible by 4 and not divisible by 100 it is a
        // leap year
        cout<<"Leap year"<<endl;
    } else {
        // else it is not a leap year
        cout<<"Not a leap year"<<endl;
    }
    
    return 0;
}