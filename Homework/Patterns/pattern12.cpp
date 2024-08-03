#include<bits/stdc++.h>
using namespace std;
int main() {
    char alphabet;
    cout<<"Enter alphabet : ";
    cin>>alphabet;
    int n = alphabet-'A'+1;
    for(int row=0; row<n; row++) {
        for(int col=0; col<n-row-1; col++) {
            cout<<"  ";
        }
        for(char col=alphabet; col>=alphabet-row; col--) {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    return 0;
}