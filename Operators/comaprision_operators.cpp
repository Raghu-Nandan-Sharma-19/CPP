#include<bits/stdc++.h>
using namespace std;
int main() {
    int num1, num2;
    cout<<"Enter number 1 : ";
    cin>>num1;
    cout<<"Enter number 2 : ";
    cin>>num2;

    // ==
    if(num1 == num2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    // >
    if(num1 > num2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    // <
    if(num1 < num2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    // >=
    if(num1 >= num2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    // <=
    if(num1 <= num2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    if(num1 != num2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}