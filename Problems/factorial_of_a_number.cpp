#include<bits/stdc++.h>
using namespace std;
int main() {
    int num;
    unsigned long fact = 1;
    cout<<"Enter number : ";
    cin>>num;
    for(int count=1; count<=num; count++) {
        fact *= count;
    }
    cout<<"Factorial of "<<num<<" is : "<<fact<<endl;
    return 0;
}