#include<bits/stdc++.h>
using namespace std;
void print(int n) {
    for(int i=0; i<n; i++) {
        for(char ch='A'; ch<='A'+i; ch++) {
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int t, n;
    cin>>t;
    for(int i=0; i<t; i++) {
        cin>>n;
        print(n);
    }
    return 0;
}