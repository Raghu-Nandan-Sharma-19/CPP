#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cout<<"Enter number : ";
    cin>>num;
    // if the number is less than 2 it is not a prime number
    if(num<2) {
        cout<<"Not a prime number"<<endl;
        return 0;
    } else {
        for(int count=2; count<num; count++) {
            // if we get the remainder = 0 till the loop ends it is not a prime number
            if(num%count == 0) {
                cout<<"Not a prime number"<<endl;
                return 0; 
            }
        }
        // if the number doesn't gives remainder = 0 till the loop ends then it is a prime number
        cout<<"Prime number";
    }
    return 0;
}