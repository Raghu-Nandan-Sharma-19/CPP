#include<bits/stdc++.h>
using namespace std;
int main() {
    for(char row='A'; row<='E'; row++) {
        for(char col='A'; col<=row; col++) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}