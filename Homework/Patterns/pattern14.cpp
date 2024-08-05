#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter number : ";
    cin>>n;
    for(int row=0; row<n; row++) {
        for(int col=0; col<2*(n-row-1); col++) {
            cout<<" ";
        }
        for(int col=1; col<=2*row+1; col++) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}