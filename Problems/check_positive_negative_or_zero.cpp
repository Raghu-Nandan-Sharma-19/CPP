#include<bits/stdc++.h>
using namespace std;
int main() {
    int number;
    cin>>number;
    if(number>0) {
        cout<<"Positive";
    } else if(number<0) {
        cout<<"Negative";
    } else {
        cout<<"0";
    }
    return 0;
}