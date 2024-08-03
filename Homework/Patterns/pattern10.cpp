#include<bits/stdc++.h>
using namespace std;
int main() {
    char alphabet;
    cout<<"Enter alphabet : ";
    cin>>alphabet;
    for(char row='A'; row<=alphabet; row++) {
        for(int col=1; col<=alphabet-row; col++) {
            cout<<"  ";
        }
        for(char col='A'; col<=row; col++) {
            cout<<row<<" ";
        }
        cout<<endl;
    }
    return 0;
}