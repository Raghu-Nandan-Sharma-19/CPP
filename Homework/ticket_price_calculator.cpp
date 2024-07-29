#include<bits/stdc++.h>
using namespace std;
int main() {
    int age;
    cout<<"Enter your age : "<<endl;
    cin>>age;
    if(age < 12) cout<<"Eligible for discount"<<endl;
    else if(age > 65) cout<<"Eligible for discount"<<endl;
    else cout<<"Not eligible for discount"<<endl;
    return 0;
}