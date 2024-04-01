#include<bits/stdc++.h>
using namespace std;
bool checkArmstrong(int number) {
    int count = 0, sum = 0, originalNumber = number, duplicateNumber = number;
    while(duplicateNumber!=0) {
        count++;
        duplicateNumber/=10;
    }
    while(number!=0) {
        int lastDigit = number%10;
        sum+=pow(lastDigit, count);
        number/=10;
    }
    return (sum==originalNumber);
}
int main() {
    int number;
    cout<<"Enter any number : "<<endl;
    cin>>number;
    if(checkArmstrong(number)) {
        cout<<number<<" is an armstrong number."<<endl;
    } else {
        cout<<number<<" is not an armstrong number."<<endl;
    }
    return 0;
}