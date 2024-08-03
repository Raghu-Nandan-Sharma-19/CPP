#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int row=1; row<=n; row++) {
        // space print
        for(int col=1; col<=n-row; col++) {
            cout<<"  ";
        }
        // star print
        for(int col=1; col<=row; col++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}