#include<bits/stdc++.h>
using namespace std;
int main() {
    int number;
    cout<<"Enter number : ";
    cin>>number;
    int count = 1;
    while(count <= 10) {
        cout<<number<<" * "<<count<<" = "<<number*count<<endl;
        count++;
    }
    return 0;
}