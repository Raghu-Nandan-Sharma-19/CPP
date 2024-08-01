#include<bits/stdc++.h>
using namespace std;
int main() {
    // int count = 1;
    // for(int row=1; row<=5; row++) {
    //     for(int col=1; col<=5; col++) {
    //         cout<<count++<<" ";
    //     }
    //     cout<<endl;
    // }

    // alternate way
    for(int row=1; row<=5; row++) {
        for(int col=1; col<=5; col++) {
            cout<<(row-1)*5+col<<" ";
        }
        cout<<endl;
    }
    return 0;
}