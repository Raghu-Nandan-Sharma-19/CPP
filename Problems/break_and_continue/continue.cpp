#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int count = 1; count <= n; count++) {
        if(count % 4 == 0) continue;
        cout<<count<<" ";
    }
    return 0;
}