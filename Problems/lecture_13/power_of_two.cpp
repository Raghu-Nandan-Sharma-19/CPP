#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    int dup = num; // made this duplicate variable to perform operations

    // if dup is less than 1 it is not a power of two
    if (dup < 1) {
        cout<<dup<<"is not a power of 2"<<endl;
    }
    // checking if dup is not equal to 1
    while (dup != 1) {
        // if dup modulus 2 gives remainder equal to 1, it is not a power of 2
        if (dup % 2 == 1) {
            cout<<dup<<" is not a power of 2"<<endl;
            return 0; // end the program here
        }
        // dividing the dup by 2
        dup /= 2;
    }
    // if the dup doesnt give remainder 1 after doing modulus by 2
    // then it is a power of 2
    cout<<num<<" is a power of 2"<<endl;

    return 0;
}