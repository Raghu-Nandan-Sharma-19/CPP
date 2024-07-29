#include<bits/stdc++.h>
using namespace std;
int main() {
    int age;
    cout<<"Enter your age : ";
    cin>>age;
    if(age>=18) {
        cout<<"Eligible for voting"<<endl;
    } else {
        cout<<"Nor eligible for voting"<<endl;
    }
    return 0;
}