#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cout<<"Enter n : ";
    cin>>n;
    for(int count=1; count<=n; count++) {
        if(count%2 == 1) {
            cout<<count<<endl;
        }
    }
    return 0;
}