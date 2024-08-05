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
        // 1 to row print
        for(int col=1; col<=row; col++) {
            cout<<col<<" ";
        }
        // row-1 to 1 print
        for(int col=row-1; col>=1; col--) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}