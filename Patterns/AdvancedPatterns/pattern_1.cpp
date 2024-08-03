#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter number : ";
    cin>>n;
    for(int row=1; row<=n; row++) {
        // space print
        for(int col=1; col<=n-row; col++) {
            cout<<"  ";
        }
        // number print
        for(int col=1; col<=2*row-1; col++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}