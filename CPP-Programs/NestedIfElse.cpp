#include<bits/stdc++.h>
using namespace std;
int main() {
    int age;
    cin>>age;
    if(age<18) {
        cout<<"Not eligible for job"<<endl;
    } else if(age>=18 && age<=57) {
        cout<<"eligible for job";
        if(age>=55 && age<=57) {
            cout<<", but retirement soon"<<endl;
        }
    } else {
        cout<<"retirement time"<<endl;
    }
    return 0;
}