#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int count = 1;
    while(count <= n) {
        if(count % 2 == 1) cout<<count<<" ";
        count++;
    }
    return 0;
}