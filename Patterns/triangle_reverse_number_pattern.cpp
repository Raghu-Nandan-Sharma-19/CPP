#include<bits/stdc++.h>
using namespace std;
int main() {
    for(int row=1; row<=5; row++) {
        for(int col=1; col<=row; col++) {
            cout<<row-col+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}