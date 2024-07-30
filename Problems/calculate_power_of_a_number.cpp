#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, power;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter power : ";
    cin>>power;
    int result = n;
    for(int count=1; count<power; count++) {
        result *= n;
    }
    cout<<result<<endl;
    return 0;
}