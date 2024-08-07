#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, x;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter x : ";
    cin>>x;
    int count = 1;
    while(count <= n) {
        if(count == x) break;
        cout<<count<<" ";
        count++;
    }
    return 0;
}