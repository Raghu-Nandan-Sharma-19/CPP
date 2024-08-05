#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter number : ";
    cin>>n;
    for(int row=1; row<=n; row++) {
        for(int col=1; col<=n-row; col++) {
            cout<<"  ";
        }
        for(int col=1; col<=row; col++) {
            cout<<col<<" ";
        }
        for(int col=row-1; col>=1; col--) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}