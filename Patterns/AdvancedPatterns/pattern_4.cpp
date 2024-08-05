#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter number : ";
    cin>>n;
    for(int row=n; row>=1; row--) {
        // star print
        for(int col=1; col<=row; col++) {
            cout<<"*"<<" ";
        }
        // space print
        for(int col=1; col<=2*n-2*row; col++) {
            cout<<"  ";
        }
        // star print
        for(int col=1; col<=row; col++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    for(int row=1; row<=n; row++) {
        // star print
        for(int col=1; col<=row; col++) {
            cout<<"*"<<" ";
        }
        // space print
        for(int col=1; col<=2*n-2*row; col++) {
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