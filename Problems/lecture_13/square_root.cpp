#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    cout<<"Enter a number : ";
    cin>>num;

    // initializing long variable to avoid overflow condition
    long int count = 1;

    // checking if count * count is less than or equal to number
    while (count * count <= num) {
        count++;
    }
    // Print count - 1 as answer
    cout<<"Square root of "<<num<<" is : "<<(count - 1)<<endl;

    return 0;
}