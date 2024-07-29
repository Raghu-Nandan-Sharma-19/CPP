#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int count = 2; count <= n; count++) {
        if(count%2 == 0) {
            cout<<count<<endl;
        }
    }
    return 0;
}