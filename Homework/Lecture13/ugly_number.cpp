#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    int duplicate = num;

    if(duplicate == 0) {
        cout<<num<<" is not an ugly number"<<endl;
    }
    while (duplicate % 2 == 0) {
        duplicate /= 2;
    }
    while (duplicate % 3 == 0) {
        duplicate /= 3;
    }
    while (duplicate % 5 == 0) {
        duplicate /= 5;
    }
    if (duplicate != 1) {
        cout<<num<<" is not an ugly number"<<endl;
    } else {
        cout<<num<<" is an ugly number"<<endl;
    }
    
    return 0;
}