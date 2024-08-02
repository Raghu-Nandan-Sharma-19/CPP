#include<bits/stdc++.h>
using namespace std;
int main() {
    for(int row=1; row<=5; row++) {
        char alphabet = 'a'+(row-1);
        for(int col=1; col<=row; col++) {
            cout<<alphabet<<" ";
        }
        cout<<endl;
    }
    return 0;
}