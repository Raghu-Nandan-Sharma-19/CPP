#include<bits/stdc++.h>
using namespace std;
int main() {
    // for(char row='a'; row<='e'; row++) {
    //     for(char col='a'; col<='e'; col++) {
    //         cout<<row<<" ";
    //     }
    //     cout<<endl;
    // }

    // alternate way to print
    for(int row=1; row<=5; row++) {
        char alphabet = 'a'+row-1;
        for(int col=1; col<=5; col++) {
            cout<<alphabet<<" ";
        }
        cout<<endl;
    }
    return 0;
}