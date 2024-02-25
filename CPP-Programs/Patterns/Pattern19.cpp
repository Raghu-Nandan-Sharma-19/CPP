#include<bits/stdc++.h>
using namespace std;
void print(int n) {
    int spaces=0;
    for(int i=0; i<n; i++) {
        // stars
        for(int j=1; j<=n-i; j++) {
            cout<<"*";
        }
        // spaces
        for(int j=0; j<spaces; j++) {
            cout<<" ";
        }
        // stars
        for(int j=1; j<=n-i; j++) {
            cout<<"*";
        }
        spaces+=2;
        cout<<endl;
    }
    spaces=2*n-2;
    for(int i=1; i<=n; i++) {
        // stars
        for(int j=1; j<=i; j++) {
            cout<<"*";
        }
        // spaces
        for(int j=0; j<spaces; j++) {
            cout<<" ";
        }
        // stars
        for(int j=1; j<=i; j++) {
            cout<<"*";
        }
        spaces-=2;
        cout<<endl;
    }
}
int main() {
    int t, n;
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>n;
        print(n);
    }
    return 0;
}