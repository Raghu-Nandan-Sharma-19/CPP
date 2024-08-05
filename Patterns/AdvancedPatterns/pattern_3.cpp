#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter number : ";
    cin>>n;
    for(int row=n; row>=1; row--) {
        // space print
        for(int col=1; col<=n-row; col++) {
            cout<<"  ";
        }
        // star print
        for(int col=1; col<=2*row-1; col++) {
            cout<<"*"<<" ";
        }
        cout<<endl;
    }
    return 0;
}