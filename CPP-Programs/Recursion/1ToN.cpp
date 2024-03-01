#include<bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
void print() {
    if(cnt==n) {
        return;
    } else {
        cout<<cnt<<endl;
    }
    cnt++;
    print();
}
int main() {
    cout<<"Enter a number till you want to print numbers : ";
    cin>>n;
    print();
    return 0;
}