#include<bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    cout<<"Enter c : ";
    cin>>c;
    if(a > b && a > c) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}