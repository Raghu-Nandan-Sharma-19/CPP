#include <iostream>
using namespace std;
int reverse(int X) {
    int Y = 0;
    while (X > 0) {
        //Extract the last digit
        int digit = X % 10;
        //Appending last digit
        Y = Y * 10 + digit;
        // Shrinking X by discarding the last digit
        X = X / 10;
    }
    return Y;
}
int main() {
    int number;
    cout<<"Enter any number : "<<endl;
    cin>>number;
    int dummy = number;
    int reverseNumber = reverse(number);
    if (dummy == reverseNumber) {
        cout << "Palindrome Number" << endl;
    } else {
        cout << "Not Palindrome Number" << endl;
    }
    return 0;
}
