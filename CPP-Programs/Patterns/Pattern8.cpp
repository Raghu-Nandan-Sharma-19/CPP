#include<bits/stdc++.h>
using namespace std;
void print(int n) {
    for(int i=0; i<n; i++) {
        // space
        for(int j=0; j<i; j++) {
            cout<<" ";
        }
        // stars
        for(int j=0; j<2*n-(2*i+1); j++) {
            cout<<"*";
        }  
        // space
        for(int j=0; j<i; j++) {
            cout<<" ";
        }
        cout<<endl;      
    }
}
int main() {
    int n, t;
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>n;
        print(n);
    }
    return 0;
}