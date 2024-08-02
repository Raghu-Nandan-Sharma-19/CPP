#include<bits/stdc++.h>
using namespace std;
int main() {
    for(int row=1; row<=5; row++) {
        for(int col=1; col<=5-(row-1); col++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}